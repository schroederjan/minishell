
#include "lexer.h"

/* This function is used to handle quotes in a string by counting
 * the number of characters between two occurrences of the `del` character. */
int	handle_quotes(int i, char *str, char del)
{
	int	j;

	j = 0;
	if (str[i + j] == del)
	{
		j++;
		while (str[i + j] != del && str[i + j])
			j++;
		j++;
	}
	return (j);
}
