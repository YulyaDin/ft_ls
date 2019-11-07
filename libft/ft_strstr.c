/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malannys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 22:10:50 by malannys          #+#    #+#             */
/*   Updated: 2018/12/18 20:57:48 by malannys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	needle_len;
	size_t	i;

	if (!(needle_len = ft_strlen(needle)))
		return ((char *)haystack);
	while ((haystack = ft_strchr(haystack, *needle)))
	{
		i = 0;
		while (haystack[i] == needle[i] && needle[i])
			i++;
		if (i == needle_len)
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
