/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 20:15:31 by sehjung           #+#    #+#             */
/*   Updated: 2022/07/12 17:18:11 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**freeall(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	return (NULL);
}

int	count_word(const char *str, char charset)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (str[i] == charset)
			i++;
		else
		{
			cnt++;
			while (str[i] && str[i] != charset)
				i++;
		}
	}
	return (cnt);
}

void	copy_str(char *arr, const char *str, char charset)
{
	int	i;

	i = 0;
	while (str[i] != charset && str[i])
	{
		arr[i] = str[i];
		i++;
	}
	arr[i] = '\0';
}

char	**real_split(char **arr, char const *str, char charset)
{
	int	word;
	int	i;
	int	j;

	word = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == charset)
			i++;
		else
		{
			j = 0;
			while (str[i + j] != charset && str[i + j])
				j++;
			arr[word] = (char *)malloc(sizeof(char) * (j + 1));
			if (!arr[word])
				return (freeall(arr));
			copy_str(arr[word], str + i, charset);
			i += j;
			word++;
		}
	}
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		word;

	if (!s)
		return (NULL);
	word = count_word(s, c);
	arr = (char **)malloc(sizeof(char *) * (word + 1));
	if (!arr)
		return (NULL);
	arr[word] = 0;
	arr = real_split(arr, s, c);
	return (arr);
}
