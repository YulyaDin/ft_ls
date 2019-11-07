/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malannys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 22:54:12 by malannys          #+#    #+#             */
/*   Updated: 2018/12/18 20:36:53 by malannys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i++ < len)
	{
		if (!*src)
		{
			*dst = '\0';
			dst++;
			continue ;
		}
		*dst = *src;
		dst++;
		src++;
	}
	return (dst - len);
}
