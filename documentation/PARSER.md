# VISUAL

```scss
parser(t_data *data)
  |
  |---> cmd_lst_new() -- Creates new command node
  |        |
  |        `---> cmd_init() -- Initializes command fields
  |
  |---> Iterates over tokens
  |        |
  |        |---> parse_input() / parse_output() / parse_heredoc() / parse_pipe() / parse_word()
  |        |        |           |            |            |                  |
  |        |        |           |            |            |                  `---> parse_word_fill_args()
  |        |        |           |            |            `---> cmd_lst_get_end()
  |        |        |           |            `---> generate_heredoc() -- fill_heredoc()
  |        |        |           `---> open_outfile() -- clear_old_outfiles()
  |        |        `---> open_infile() -- clear_old_infiles()
  |        |
  |        `---> syntax_check() -- Uses skip_spaces() and syntax_error()
  |
  `---> cmd_lst_add_end()
```


# TEXT

## Parser Directory Overview

### Function Flow Overview

- **`parser(t_data *data)`**
  - The main entry point for parsing.
  - Initializes command list and iterates over tokens to process input commands.

### Command List Management

- **`cmd_lst_new(void)`**
  - Creates a new command node, initializing all fields to default values.
  
- **`cmd_lst_add_end(t_command **lst, t_command *new_node)`**
  - Adds a new command node to the end of the command list.
  
- **`cmd_lst_get_end(t_command *cmd)`**
  - Returns the last command node in the list.

### Input Handling

- **`parse_input(t_command **last_cmd, t_token **token_lst)`**
  - Parses input redirection tokens and sets up input file descriptors.

- **`open_infile(t_io_fds *io, char *file)`**
  - Opens the infile and updates the command's IO structure.

- **`clear_old_infiles(t_io_fds *io)`**
  - Clears any existing infile configurations in the command's IO structure.

### Output Handling

- **`parse_output(t_command **last_cmd, t_token **token_lst, char c)`**
  - Parses output redirection tokens (truncate or append) and sets up output file descriptors.

- **`open_outfile(t_io_fds *io, char *file, char c)`**
  - Opens the outfile (for truncation or appending) and updates the command's IO structure.

- **`clear_old_outfiles(t_io_fds *io)`**
  - Clears any existing outfile configurations in the command's IO structure.

### Heredoc Handling

- **`parse_heredoc(t_command **last_cmd, t_token **token_lst)`**
  - Parses heredoc tokens and sets up heredoc file descriptors.

- **`generate_heredoc(t_io_fds *io)`**
  - Generates the heredoc content into a temporary file.

- **`fill_heredoc(t_io_fds *io, int fd)`**
  - Reads lines from the user until the heredoc delimiter is encountered, writing content to a temporary file.

- **`clear_old_infiles_heredoc(t_io_fds *io)`**
  - Clears any existing infile configurations specific to heredocs in the command's IO structure.

### Pipe Handling

- **`parse_pipe(t_command **cmd, t_token **token_lst)`**
  - Parses pipe tokens, indicating that the output of the current command should be piped to the next command.

### Word and Argument Parsing

- **`parse_word(t_command **cmd, t_token **token_lst)`**
  - Parses command names and arguments, filling the command and arguments list.

- **`parse_word_fill_args(t_token **token_node, t_command *last_cmd)`**
  - Helper function for `parse_word`, specifically for filling the command's argument list.

### Syntax Checking

- **`syntax_check(t_token **token_lst)`**
  - Performs a preliminary syntax check on the tokens list to identify any obvious syntax errors before executing commands.

### Utility Functions

- **`cmd_init(t_command **cmd)`**
  - Initializes a command structure with default values.

- **`generate_heredoc_name(void)`**
  - Generates a unique name for a heredoc temporary file.

- **`skip_spaces(t_token *lst)`**
  - Skips space tokens to facilitate syntax checking and token processing.

- **`syntax_error(t_token *temp, t_token *prev)`**
  - Checks for syntax errors based on the current and previous tokens.

### Token List Management

- **`lst_new_token(char *str, int type)`**
  - Creates a new token node.

- **`lst_add_back_token(t_token **alst, t_token *new_node)`**
  - Adds a new token node to the end of the token list.

### Error Handling

- **`err_msg_syntax(int type)`**
  - Prints syntax error messages based on the type of error encountered.
