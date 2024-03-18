/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 07:15:48 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/03/18 01:48:56 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static char	*put(char const *str, int *index, char c)
{
	int		i;
	int		length;
	char	*result;

	i = *index;
	length = 0;
	while (str[i] == c && str[i] != '\0')
	{
		i++;
		*index = *index + 1;
	}
	while (str[*index] != c && str[*index] != '\0')
	{
		*index = *index + 1;
		length++;
	}
	result = (char *)malloc(sizeof(char) * (length + 1));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, str + i, length + 1);
	return (result);
}

static int	countwords(char const *str, char c)
{
	int	i;
	int	count;
	int	trigger;

	trigger = 0;
	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			if (trigger == 0)
			{
				trigger = 1;
				count++;
			}
		}
		else if (trigger == 1)
			trigger = 0;
		i++;
	}
	return (count + 1);
}

static void	freelist(int i, char **res)
{
	while (i > 0)
	{
		free(res[i]);
		i = i - 1;
	}
	free(res[i]);
	free(res);
}

char	**ft_split(char const *str, char c)
{
	int		i;
	int		count;
	char	**res;
	int		index;

	if (str == NULL)
		return (NULL);
	count = countwords(str, c);
	res = (char **)malloc(sizeof(char *) * (count));
	if (res == NULL)
		return (NULL);
	index = 0;
	i = 0;
	while (i < count - 1)
	{
		res[i] = put(str, &index, c);
		if (res[i] == NULL)
		{
			freelist(i, res);
			return (NULL);
		}
		i++;
	}
	res[i] = NULL;
	return (res);
}

// int main (void)
// {
// 	char	**split;
// 	char	*str = "xxxxxxxxxxxxxhello!";
// 	char	c = 'x';
// 	int	i = 0;
// 	printf("%d\n\n",countwords(str,c));
// 	split = ft_split(str, c);
// 	while (split[i])
// 	{
// 		printf("%s\n",split[i]);
// 		i++;
// 	}
// 	return (0);
// }