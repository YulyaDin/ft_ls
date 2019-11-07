/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malannys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 23:39:24 by malannys          #+#    #+#             */
/*   Updated: 2019/01/11 16:39:37 by malannys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;
	size_t	len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	len = src_len + ((size < dst_len) ? size : dst_len);
	i = dst_len;
	while (size && i < size - 1 && src[i - dst_len])
	{
		dst[i] = src[i - dst_len];
		i++;
	}
	if (size && i <= size - 1)
		dst[i] = '\0';
	return (len);
}
