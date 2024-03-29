#include "../includes/minishell.h"

static int		is_whitespace(char c)
{
	return (c == ' ' || (c > 8 && c < 14));
}

static int		skip_whitespace(char *str, int i)
{
	while (str[i] && is_whitespace(str[i]))
		i++;
	return i;
}

static int		skip_quotes(int index, char *str, char quote_type) 
{
	int offset = 0;

	if (str[index] == quote_type) {
		offset++;
		while (str[index + offset] && str[index + offset] != quote_type)
			offset++;
		if (str[index + offset] == quote_type)
			offset++;
	}
	return offset;
}

static int		parse_words(int start_pos, char *str, t_lexer **lexer_list) 
{
	int		len;
    char	*word;

	len = 0;
	while (str[start_pos + len] && !token_identify(str, start_pos + len))
	{
		if (str[start_pos + len] == '"' || str[start_pos + len] == '\'') 
			len += skip_quotes(start_pos + len, str, str[start_pos + len]);
		else if (is_whitespace(str[start_pos + len]))
			break;
		else
			len++;
	}
	if (len > 0) {
		word = ft_substr(str, start_pos, len);
		if (!word || !add_lexer_node(word, TOKEN_WORD, lexer_list)) 
		{
			free(word);
			return (-1);
		}
		free(word);
	}
	return (len);
}

int		parse_input(t_session *session)
{
	int			pos;
	int			move;
	t_tokens	ttype;

	pos = 0;
	while (session->arg[pos])
	{
		pos += skip_whitespace(session->arg, pos);
		ttype = token_identify(session->arg, pos);
		if (ttype != NO_TOKEN)
			move = token_add(session->arg, pos, &session->lexer_list, ttype);
		else
			move = parse_words(pos, session->arg, &session->lexer_list);
		if (move <= 0)
			return (0);
		pos += move;
		if (!session->arg[pos])
			break;
	}
	return (1);
}
