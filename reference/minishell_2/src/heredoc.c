#include "../includes/executor.h"

/**
 * Creates a heredoc file with the given content.
 *
 * This function creates a heredoc file with the content provided by the user.
 * The function reads input from the user until a specified stop condition is
 * met, and writes the input to the file specified by `file_name`.
 *
 * @param heredoc A pointer to the lexer struct containing the heredoc content
 * @param quotes A boolean flag indicating whether to expand variables in the
 * input
 * @param tools A pointer to the tools struct for variable expansion
 * @param file_name The name of the file to create and write the heredoc content
 * to
 * @return Returns EXIT_SUCCESS if the heredoc file was successfully created,
 * EXIT_FAILURE otherwise
 */
int create_heredoc(t_lexer *heredoc, bool quotes, t_tools *tools, char *file_name)
{
    int fd; // File descriptor for the heredoc file
    char *line; // Input line read from the user

    // Open the file for writing
    fd = open(file_name, O_CREAT | O_RDWR | O_TRUNC, 0644);

    // Read input from the user until stop condition is met
    line = readline(HEREDOC_MSG);
    while (line && ft_strncmp(heredoc->str, line, ft_strlen(heredoc->str)) && !g_global.stop_heredoc)
    {
        // Expand variables in the input if quotes flag is false
        if (quotes == false)
            line = expander_str(tools, line);

        // Write the input line to the heredoc file
        write(fd, line, ft_strlen(line));
        write(fd, "\n", 1);

        // Free the input line and read the next line
        free(line);
        line = readline(HEREDOC_MSG);
    }
    free(line);

    // Check for stop condition or error in reading input
    if (g_global.stop_heredoc || !line)
        return (EXIT_FAILURE);

    // Close the file and return success
    close(fd);
    return (EXIT_SUCCESS);
}


/**
 * Executes a here document, which is a way to redirect input into a command
 * from a file or string.
 *
 * @param tools A pointer to the tools struct containing various tools needed
 * for execution
 * @param heredoc A pointer to the lexer struct representing the here document
 * @param file_name The name of the file to redirect input from
 * @return Returns EXIT_SUCCESS if the here document was executed successfully,
 * otherwise returns an error code
 */
int ft_heredoc(t_tools *tools, t_lexer *heredoc, char *file_name)
{
    bool quotes;
    int sl;

    // Initialize success flag
    sl = EXIT_SUCCESS;

    // Check if the heredoc string is enclosed in quotes
    if ((heredoc->str[0] == '\"' && heredoc->str[ft_strlen(heredoc->str) - 1] == '\"')
        || (heredoc->str[0] == '\'' && heredoc->str[ft_strlen(heredoc->str) - 1] == '\''))
        quotes = true;
    else
        quotes = false;
    
    // Remove quotes from the heredoc string
    delete_quotes(heredoc->str, '\"');
    delete_quotes(heredoc->str, '\'');
    
    // Set global flags for heredoc processing
    g_global.stop_heredoc = 0;
    g_global.in_heredoc = 1;
    
    // Create the heredoc with or without quotes
    sl = create_heredoc(heredoc, quotes, tools, file_name);
    
    // Reset global heredoc flag
    g_global.in_heredoc = 0;
    // Mark that a heredoc has been processed
    tools->heredoc = true;
    
    return sl;
}

/**
 * Generates a unique filename for a heredoc temporary file.
 *
 * This function generates a unique filename for a heredoc temporary file by
 * appending a numerical suffix to a base filename. The numerical suffix is
 * incremented each time this function is called.
 *
 * @return char* A pointer to the generated filename string
 */
char	*generate_heredoc_filename(void)
{
	static int	i = 0;
	char		*num;
	char		*file_name;

	num = ft_itoa(i++);
	file_name = ft_strjoin("build/.tmp_heredoc_file_", num);
	free(num);
	return (file_name);
}


/**
 * Sends a heredoc to the specified file descriptor.
 *
 * This function sends a heredoc to the specified file descriptor using the
 * given tools and simple command.
 *
 * @param tools A pointer to the tools struct containing necessary information
 * for sending the heredoc.
 * @param cmd A pointer to the simple_cmds struct representing the simple
 * command with redirections.
 * @return Returns EXIT_SUCCESS if the heredoc was sent successfully, otherwise
 * returns an error code.
 */
int send_heredoc(t_tools *tools, t_simple_cmds *cmd)
{
    t_lexer *start;
    int sl;

    start = cmd->redirections; // Save the start of the redirections list
    sl = EXIT_SUCCESS; // Initialize success flag
    while (cmd->redirections) // Iterate through all redirections
    {
        if (cmd->redirections->token == LESS_LESS) // Check if current redirection is a heredoc
        {
            if (cmd->hd_file_name) // Free previous heredoc filename if exists
                free(cmd->hd_file_name);
            cmd->hd_file_name = generate_heredoc_filename(); // Generate a new filename for the heredoc
            sl = ft_heredoc(tools, cmd->redirections, cmd->hd_file_name); // Process the heredoc and save its content to a file
            if (sl) // Check if heredoc processing failed
            {
                g_global.error_num = 1; // Set global error flag
                return (reset_tools(tools)); // Reset tools and return failure
            }
        }
        cmd->redirections = cmd->redirections->next; // Move to the next redirection
    }
    cmd->redirections = start; // Restore the start of the redirections list
    return (EXIT_SUCCESS); // Return success
}

