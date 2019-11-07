/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malannys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 20:07:53 by malannys          #+#    #+#             */
/*   Updated: 2019/01/10 19:05:28 by malannys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static const char	*delim_skip(const char *s, char c)
{
	while (*s == c)
		s++;
	return (s);
}

static size_t		words_count(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			count += 1;
			while (*s != c && *s)
				s++;
		}
	}
	return (count);
}

static size_t		wordlen(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static void			free_arr(char **arr, size_t words_num)
{
	size_t	i;

	i = 0;
	while (i < words_num)
	{
		free((void *)*(arr + i));
		i++;
	}
	free(arr);
}

char				**ft_strsplit(char const *s, char c)
{
	size_t	w_num;
	size_t	word_len;
	size_t	i;
	char	**words_arr;

	if (!s)
		return (NULL);
	i = 0;
	w_num = words_count(s, c);
	if (!(words_arr = (char **)malloc(sizeof(char *) * (w_num + 1))))
		return (NULL);
	while (i < w_num)
	{
		s = delim_skip(s, c);
		word_len = wordlen(s, c);
		if (!(words_arr[i] = ft_strsub(s, 0, word_len)))
		{
			free_arr(words_arr, i);
			return (NULL);
		}
		s += word_len;
		i++;
	}
	words_arr[i] = NULL;
	return (words_arr);
}
