/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerokhin <aerokhin@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 11:55:36 by aerokhin          #+#    #+#             */
/*   Updated: 2024/11/05 17:14:55 by aerokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static int	my_count_words(char const *s, char c)
{
	size_t	i;
	size_t	counter;

	if (!s || s[0] == '\0')
		return (0);
	i = 0;
	counter = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			counter++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (counter);
}

static char	*my_take_n_word(char const *s, char c, size_t n)
{
	size_t	i;
	size_t	word;
	size_t	w_begin;
	size_t	w_end;

	i = 0;
	word = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (word == n)
		{
			w_begin = i;
			while (s[i] != c && s[i] != '\0')
				i++;
			w_end = i;
			return (ft_substr(s, w_begin, w_end - w_begin));
		}
		while (s[i] != c && s[i] != '\0')
			i++;
		word++;
	}
	return (NULL);
}

static void	my_free_result(char **res, size_t i)
{
	while (i > 0)
	{
		free(res[i - 1]);
		i--;
	}
	free(res);
}

static char	**my_create_empty_array(void)
{
	char	**res;

	res = (char **)malloc (sizeof(char *));
	if (!res)
		return (NULL);
	res[0] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	size_t	word_count;
	char	**res;
	size_t	i;

	if (!s)
		return (NULL);
	if (s[0] == 0)
		return (my_create_empty_array());
	word_count = my_count_words(s, c);
	res = (char **) malloc((word_count + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		res[i] = my_take_n_word(s, c, i);
		if (!res[i])
		{
			my_free_result(res, i);
			return (NULL);
		}
		i++;
	}
	res[word_count] = NULL;
	return (res);
}
