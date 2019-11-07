/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malannys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 20:48:01 by malannys          #+#    #+#             */
/*   Updated: 2019/08/18 20:15:33 by malannys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	short	check;
	size_t	elem;

	i = 0;
	check = (dst > src) ? 1 : 0;
	while (i < len)
	{
		elem = (len - 1 - 2 * i) * check + i;
		*((unsigned char *)dst + elem) = *((const unsigned char *)src + elem);
		i++;
	}
	return (dst);
}
