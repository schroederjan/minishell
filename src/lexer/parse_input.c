#include "../../includes/minishell.h"

int	is_whitespace(char c)
{
	return (c == ' ' || (c > 8 && c < 14));
}

int skip_whitespace(char *str, int i)
{
	while (str[i] && is_whitespace(str[i]))
		i++;
	return i;
}

int		parse_words(int start_pos, char *str, t_lexer **lexer_list) 
{
	int		len;

	len = 0;
	while (str[start_pos + len] && !identify_token(str[start_pos + len]))
	{
		if (str[start_pos + len] == '"' || str[start_pos + len] == '\'') 
			len += handle_quotes(start_pos + len, str, str[start_pos + len]);
		else if (is_whitespace(str[start_pos + len]))
			break; // Stop at the first whitespace after a word or quoted string.
		else
			len++; // Regular character, just move to the next one.
	}
	if (len > 0 && !add_node(ft_substr(str, start_pos, len), WORD, lexer_list))
		return (-1);
	return (len);
}


int		parse_input(t_session *session)
{
	int		pos;
	int		move;

	pos = 0;
	while (session->args[pos])
	{
		pos += skip_whitespace(session->args, pos);
		if (identify_token(session->args[pos]))
			move = parse_token(session->args, pos, &session->lexer_list);
		else
			move = parse_words(pos, session->args, &session->lexer_list);
		if (move < 0)
			return (0);
		pos += move;
		if (!session->args[pos])
			break;
	}
	return (1);
}

