
#include "../includes/executor.h"

/**
 * Joins an array of strings into a single string with spaces in between each element.
 *
 * This function takes an array of strings and concatenates them into a single string with spaces in between each element.
 *
 * @param split_str An array of strings to be joined together.
 * @param new_str The resulting string after joining all elements of split_str.
 * @return A pointer to the newly created string that contains all elements of split_str joined together with spaces.
 */
char	*join_split_str(char **split_str, char *new_str)
{
	char	*tmp;
	char	*add_space;
	int		i;

	tmp = ft_strdup(split_str[0]);
	i = 1;
	while (split_str[i])
	{
		new_str = tmp;
		add_space = ft_strjoin(new_str, " ");
		free(new_str);
		tmp = ft_strjoin(add_space, split_str[i]);
		free(add_space);
		i++;
	}
	new_str = tmp;
	return (new_str);
}


/**
 * Splits a double array of strings into a new double array of strings by
 * splitting each string by spaces.
 *
 * This function takes a double array of strings as input, joins all the strings
 * together into one string, splits the joined string by spaces, and then joins
 * the resulting array of strings back together into one string before splitting
 * it by spaces again. The final result is a new double array of strings where
 * each string is a word from the original input strings.
 *
 * @param double_arr The double array of strings to split
 * @return A new double array of strings where each string is a word from the
 * original input strings
 */
char	**resplit_str(char **double_arr)
{
	char	**ret;
	char	*joined_str;

	joined_str = join_split_str(double_arr, NULL);
	free_arr(double_arr);
	ret = ft_split(joined_str, ' ');
	free(joined_str);
	joined_str = join_split_str(ret, NULL);
	free_arr(ret);
	ret = ft_split(joined_str, ' ');
	free(joined_str);
	return (ret);
}

