/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malannys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 17:25:36 by malannys          #+#    #+#             */
/*   Updated: 2019/08/18 20:14:10 by malannys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;

	i = 0;
	while (i < n)
	{
		*(((unsigned char *)dst) + i) = *(((const unsigned char *)src) + i);
		if (*(((const unsigned char *)src) + i++) == (unsigned char)c)
			return ((void *)(((unsigned char *)dst) + i));
	}
	return (NULL);
}
