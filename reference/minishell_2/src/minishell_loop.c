
#include "../includes/minishell.h"

int	minishell_loop(t_tools *tools);

int	implement_tools(t_tools *tools)
{
	tools->simple_cmds = NULL;
	tools->lexer_list = NULL;
	tools->reset = false;
	tools->pid = NULL;
	tools->heredoc = false;
	g_global.stop_heredoc = 0;
	g_global.in_cmd = 0;
	g_global.in_heredoc = 0;
	parse_envp(tools);
	init_signals();
	return (1);
}

int	reset_tools(t_tools *tools)
{
	ft_simple_cmdsclear(&tools->simple_cmds);
	free(tools->args);
	if (tools->pid)
		free(tools->pid);
	free_arr(tools->paths);
	implement_tools(tools);
	tools->reset = true;
	minishell_loop(tools);
	return (1);
}

/*
The `prepare_executor` function is responsible for setting up the execution of
commands. Here is a breakdown of the code:

1. `signal(SIGQUIT, sigquit_handler);`: This line sets up a signal handler for
the SIGQUIT signal. When the SIGQUIT signal is received, the `sigquit_handler`
function will be called.

2. `g_global.in_cmd = 1;`: This line sets a global variable `in_cmd` to 1,
indicating that a command is currently being executed.

3. `if (tools->pipes == 0)`: This condition checks if there are no pipes in the
command. If there are no pipes, it calls the `single_cmd` function with the
`simple_cmds` and `tools` as arguments.

4. `else`: If there are pipes in the command, the following steps are executed:
   - `tools->pid = ft_calloc(sizeof(int), tools->pipes + 2);`: Allocate memory
for an array of integers to store process IDs. The size of the array is
`tools->pipes + 2`.
   - `if (!tools->pid) return (ft_error(1, tools));`: Check if the memory
allocation was successful. If not, return an error.
   - `executor(tools);`: Call the `executor` function with `tools` as an
argument to execute the command with pipes.

5. `g_global.in_cmd = 0;`: Set the global variable `in_cmd` back to 0,
indicating that the command execution has finished.

6. `return (EXIT_SUCCESS);`: Return `EXIT_SUCCESS` to indicate that the function
executed successfully.

Overall, the `prepare_executor` function prepares for the execution of commands,
sets up signal handling, allocates memory for process IDs if needed, and then
calls the appropriate function to execute the command.
*/
int	prepare_executor(t_tools *tools)
{
	signal(SIGQUIT, sigquit_handler);
	g_global.in_cmd = 1;
	if (tools->pipes == 0)
		single_cmd(tools->simple_cmds, tools);
	else
	{
		tools->pid = ft_calloc(sizeof(int), tools->pipes + 2);
		if (!tools->pid)
			return (ft_error(1, tools));
		executor(tools);
	}
	g_global.in_cmd = 0;
	return (EXIT_SUCCESS);
}

int	minishell_loop(t_tools *tools)
{
	char	*tmp;

	tools->args = readline(READLINE_MSG);
	tmp = ft_strtrim(tools->args, " ");
	free(tools->args);
	tools->args = tmp;
	if (!tools->args)
	{
		ft_putendl_fd("exit", STDOUT_FILENO);
		exit(EXIT_SUCCESS);
	}
	if (tools->args[0] == '\0')
		return (reset_tools(tools));
	add_history(tools->args);

	if (!count_quotes(tools->args))
		return (ft_error(2, tools));
	if (!token_reader(tools))
		return (ft_error(1, tools));
	parser(tools);
	prepare_executor(tools);
	reset_tools(tools);
	return (1);
}
