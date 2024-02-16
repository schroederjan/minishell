# VISUAL

```scss
lexer(t_data *data)
  |
  |---> split_usr_input(char *usr_input)
  |        |
  |        |---> remove_dollar_quote(char *user_input)
  |        |
  |        `---> add_str(char **src_ptr, char *src, int length)
  |
  |---> var_expansion(char **usr_split, char **env)
  |        `---> search_and_replace_var(char *str, int *i, char **env)
  |
  `---> tokenization(char **usr_split)
           |
           |---> token_add_space(t_token **token, char *str)
           |
           |---> token_add_sepcial_node(t_token **token, char *str)
           |
           `---> token_add_word_node(t_token **token, char *str)
                 `---> token_add_quote_node(t_token **token, char *str)
  
  `---> quote_removal(t_token *token)
           `---> remove_quotes(char *str)
```

# TEXT

## Lexer Functionality Overview

### `lexer(t_data *data)`
- Entry point for the lexer phase.
- Checks if `data` or `data->user_input` is valid.
- Splits user input into segments for processing (`split_usr_input`).
- Performs variable expansion on the split input (`var_expansion`).
- Tokenizes the processed input into a list of tokens (`tokenization`).
- Removes quotes from tokens (`quote_removal`).

### `split_usr_input(char *usr_input)`
- Duplicates user input for modification (`ft_strdup`).
- Removes `$""` or `$''` patterns (`remove_dollar_quote`).
- Splits the modified input into segments, considering quotes and spaces
  (`find_dstsize`, `add_str`).

### `remove_dollar_quote(char *user_input)`
- Searches for `$""` or `$''` patterns and removes them.

### `add_str(char **src_ptr, char *src, int length)`
- Adds a new string to an array of strings, creating or expanding the array as needed.

### `var_expansion(char **usr_split, char **env)`
- Expands variables in each segment of the split input (`search_and_replace_var`).

### `search_and_replace_var(char *str, int *i, char **env)`
- Identifies variables in a string and replaces them with their values from `env`.

### `tokenization(char **usr_split)`
- Converts the preprocessed and split input segments into a linked list of tokens.
- Depending on the segment's content, calls `token_add_space`,
  `token_add_sepcial_node`, or `token_add_word_node` to create appropriate
  tokens.

### `quote_removal(t_token *token)`
- Iterates over the list of tokens, removing surrounding quotes from each token
  (`remove_quotes`).

## Auxiliary Functions

- `get_nbr_spaces(char *str)`: Counts leading spaces in a string.
- `token_lstadd_back(t_token **start, t_token *new)`: Adds a token to the end
  of the token list.
- `token_lstnew(char *str, int type)`: Creates a new token.
- `token_add_space(t_token **token, char *str)`,
  `token_add_sepcial_node(t_token **token, char *str)`,
  `token_add_word_node(t_token **token, char *str)`: Utility functions for
  creating specific types of tokens during tokenization.

