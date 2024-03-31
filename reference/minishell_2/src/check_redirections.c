#include "../includes/executor.h"

/**
 * Check if the output file should be appended to or truncated, and open the
 * file accordingly.
 *
 * This function takes a pointer to a lexer struct containing information about
 * the redirection token and the file name. If the redirection token is
 * GREAT_GREAT, the file will be opened in append mode. If the token is not
 * GREAT_GREAT, the file will be opened in truncate mode.
 *
 * @param redirections A pointer to a lexer struct containing information about
 * the redirection token and the file name
 * @return The file descriptor of the opened file, or -1 if an error occurred
 */
int check_append_outfile(t_lexer *redirections)
{
    int fd;

    if (redirections->token == GREAT_GREAT)
        fd = open(redirections->str, O_CREAT | O_RDWR | O_APPEND, 0644);
    else
        fd = open(redirections->str, O_CREAT | O_RDWR | O_TRUNC, 0644);

    if (fd == -1)
    {
        perror("Error opening file");
    }

    return fd;
}

/**
 * handle_infile - Handles input redirection from a file
 *
 * This function takes a file name as input and opens the file in read-only
 * mode. If the file does not exist, an error message is printed to stderr and
 * the function returns EXIT_FAILURE. If the file is successfully opened, the
 * file descriptor is duplicated to STDIN_FILENO for input redirection. If an
 * error occurs during the duplication process, an error message is printed to
 * stderr and the function returns EXIT_FAILURE. Finally, the file descriptor is
 * closed before the function returns EXIT_SUCCESS.
 *
 * @param file The name of the file to be opened for input redirection
 * @return EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int	handle_infile(char *file)
{
    int	fd;

    fd = open(file, O_RDONLY);
    if (fd < 0)
    {
        ft_putstr_fd("minishell: infile: No such file or directory\n",
            STDERR_FILENO);
        return (EXIT_FAILURE);
    }
    if (fd > 0 && dup2(fd, STDIN_FILENO) < 0)
    {
        ft_putstr_fd("minishell: pipe error\n", STDERR_FILENO);
        return (EXIT_FAILURE);
    }
    if (fd > 0)
        close(fd);
    return (EXIT_SUCCESS);
}


/**
 * Handles the redirection of output to a file.
 *
 * This function takes a pointer to a lexer struct representing the output
 * redirection and checks if the output should be appended to the file. If so,
 * it opens the file in append mode and returns the file descriptor. If an error
 * occurs during this process, an error message is printed to stderr and the
 * function returns EXIT_FAILURE.
 *
 * If the file descriptor is greater than 0, the function duplicates the file
 * descriptor to STDOUT_FILENO using the dup2 system call. If an error occurs
 * during this process, an error message is printed to stderr and the function
 * returns EXIT_FAILURE.
 *
 * If the file descriptor is greater than 0, the function closes the file
 * descriptor before returning EXIT_SUCCESS.
 *
 * @param redirection A pointer to a lexer struct representing the output
 * redirection
 * @return EXIT_SUCCESS if the output redirection is successful, EXIT_FAILURE if
 * an error occurs
 */
int handle_outfile(t_lexer *redirection)
{
    int fd;

    fd = check_append_outfile(redirection);
    if (fd < 0)
    {
        ft_putstr_fd("minishell: outfile: Error\n", STDERR_FILENO);
        return EXIT_FAILURE;
    }
    if (fd > 0 && dup2(fd, STDOUT_FILENO) < 0)
    {
        ft_putstr_fd("minishell: pipe error\n", STDERR_FILENO);
        return EXIT_FAILURE;
    }
    if (fd > 0)
        close(fd);
    
    return EXIT_SUCCESS;
}


/**
 * Check for any redirections in the given simple command.
 *
 * This function iterates through the list of redirections in the given simple
 * command and handles each type of redirection accordingly. It checks for input
 * redirection (LESS), output redirection (GREAT, GREAT_GREAT), and here
 * document redirection (LESS_LESS). For each type of redirection, it calls the
 * appropriate handler function to process the redirection.
 *
 * @param cmd A pointer to the simple command structure containing the
 * redirections
 * @return Returns EXIT_SUCCESS if all redirections are successfully handled,
 *         EXIT_FAILURE if an error occurs during handling
 */
int check_redirections(t_simple_cmds *cmd)
{
    t_lexer *start;

    start = cmd->redirections;
    while (cmd->redirections)
    {
        if (cmd->redirections->token == LESS)
        {
            if (handle_infile(cmd->redirections->str))
                return (EXIT_FAILURE);
        }
        else if (cmd->redirections->token == GREAT
            || cmd->redirections->token == GREAT_GREAT)
        {
            if (handle_outfile(cmd->redirections))
                return (EXIT_FAILURE);
        }
        else if (cmd->redirections->token == LESS_LESS)
        {
            if (handle_infile(cmd->hd_file_name))
                return (EXIT_FAILURE);
        }
        cmd->redirections = cmd->redirections->next;
    }
    cmd->redirections = start;
    return (EXIT_SUCCESS);
}

