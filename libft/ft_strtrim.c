/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malannys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 20:06:35 by malannys          #+#    #+#             */
/*   Updated: 2019/01/10 16:10:01 by malannys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	len;
	size_t	i;
	char	*new_str;

	if (!s)
		return (NULL);
	i = 0;
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	if (!(len = ft_strlen(s)))
	{
		new_str = ft_strdup("");
		return (new_str);
	}
	while (len - i - 1 && (s[len - i - 1] == ' ' || s[len - i - 1] == '\n' \
				|| s[len - i - 1] == '\t'))
		i++;
	new_str = ft_strsub(s, 0, len - i);
	return (new_str);
}
