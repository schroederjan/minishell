#include "../includes/executor.h"

char	*join_split_str(char **split_str, char *new_str);
char	**resplit_str(char **double_arr);

/**
 * Finds a command in the given list of simple commands and executes it.
 *
 * This function takes a pointer to a struct containing a list of simple
 * commands and a pointer to a struct containing tools needed for execution. It
 * iterates through the list of simple commands, checking if the command exists
 * in the current directory or in any of the paths specified in the tools
 * struct. If the command is found, it is executed using execve.
 *
 * @param cmd A pointer to a struct containing a list of simple commands
 * @param tools A pointer to a struct containing tools needed for execution
 * @return Returns an integer indicating the result of the command execution
 *         0 if the command is found and executed successfully
 *         -1 if the command is not found
 */
int find_cmd(t_simple_cmds *cmd, t_tools *tools)
{
    int i;
    char *mycmd;

    i = 0;
    cmd->str = resplit_str(cmd->str);
    if (!access(cmd->str[0], F_OK))
        execve(cmd->str[0], cmd->str, tools->envp);
    while (tools->paths[i])
    {
        mycmd = ft_strjoin(tools->paths[i], cmd->str[0]);
        if (!access(mycmd, F_OK))
            execve(mycmd, cmd->str, tools->envp);
        free(mycmd);
        i++;
    }
    return (cmd_not_found(cmd->str[0]));
}

/**
 * Executes a given command with the provided tools.
 *
 * This function takes a pointer to a struct representing a simple command and a
 * pointer to a struct containing tools needed for execution. It first checks
 * for any redirections in the command and handles them if present. If any
 * errors occur during redirection handling, the function exits with a status
 * code of 1. If the command is a built-in command, it executes the built-in
 * command using the tools provided and exits with the exit code returned by the
 * built-in command. If the command is not a built-in command and is not empty,
 * it searches for the command in the system and executes it using the tools
 * provided. The function then exits with the exit code returned by the executed
 * command.
 *
 * @param cmd A pointer to a struct representing a simple command.
 * @param tools A pointer to a struct containing tools needed for execution.
 */
void handle_cmd(t_simple_cmds *cmd, t_tools *tools)
{
    int exit_code;

    exit_code = 0;
    if (cmd->redirections)
        if (check_redirections(cmd))
            exit(1);
    if (cmd->builtin != NULL)
    {
        exit_code = cmd->builtin(tools, cmd);
        exit(exit_code);
    }
    else if (cmd->str[0][0] != '\0')
        exit_code = find_cmd(cmd, tools);
    exit(exit_code);
}

/**
 * Duplicates file descriptors and handles command execution.
 *
 * This function duplicates file descriptors for input and output streams, and
 * then handles the execution of a given command.
 *
 * @param cmd - A pointer to a struct representing the command to be executed.
 * @param tools - A pointer to a struct containing tools needed for command
 * execution.
 * @param end - An array of integers representing file descriptors for input and
 * output streams.
 * @param fd_in - An integer representing the file descriptor for input stream.
 *
 * @return void
 *
 * @throws ft_error(4, tools) - If an error occurs during file descriptor
 * duplication.
 */
void dup_cmd(t_simple_cmds *cmd, t_tools *tools, int end[2], int fd_in)
{
    if (cmd->prev && dup2(fd_in, STDIN_FILENO) < 0)
        ft_error(4, tools);
    close(end[0]);
    if (cmd->next && dup2(end[1], STDOUT_FILENO) < 0)
        ft_error(4, tools);
    close(end[1]);
    if (cmd->prev)
        close(fd_in);
    handle_cmd(cmd, tools);
}

/**
 * Executes a single command from the input, handling built-in commands and
 * external commands.
 *
 * This function takes a single command from the input and executes it. If the
 * command is a built-in command (such as cd, exit, export, or unset), it calls
 * the corresponding built-in function and returns. If the command is an
 * external command, it forks a new process to handle the command and waits for
 * the child process to finish.
 *
 * @param cmd - A pointer to the t_simple_cmds struct representing the command
 * to be executed
 * @param tools - A pointer to the t_tools struct containing various tools and
 * settings for the shell
 *
 * @return void
 *
 * If an error occurs during forking a new process, the function calls ft_error
 * with error code 5. If the child process exits normally, the function sets the
 * global error number to the exit status of the child process.
 */
void	single_cmd(t_simple_cmds *cmd, t_tools *tools)
{
	int	pid;
	int	status;

	tools->simple_cmds = call_expander(tools, tools->simple_cmds);
	if (cmd->builtin == mini_cd || cmd->builtin == mini_exit
		|| cmd->builtin == mini_export || cmd->builtin == mini_unset)
	{
		g_global.error_num = cmd->builtin(tools, cmd);
		return ;
	}
	send_heredoc(tools, cmd);
	pid = fork();
	if (pid < 0)
		ft_error(5, tools);
	if (pid == 0)
		handle_cmd(cmd, tools);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		g_global.error_num = WEXITSTATUS(status);
}

