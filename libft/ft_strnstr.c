/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malannys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 23:05:20 by malannys          #+#    #+#             */
/*   Updated: 2018/12/18 19:58:51 by malannys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;
	size_t	i;

	if (!(needle_len = ft_strlen(needle)))
		return ((char *)haystack);
	while (*haystack && (len >= needle_len))
	{
		i = 0;
		while (haystack[i] == needle[i] && needle[i])
			i++;
		if (i == needle_len)
			return ((char *)haystack);
		len--;
		haystack++;
	}
	return (NULL);
}
