/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malannys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 15:55:27 by malannys          #+#    #+#             */
/*   Updated: 2019/01/11 16:03:04 by malannys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_sqrt(size_t nb)
{
	size_t count;

	if (nb == 1)
		return (1);
	count = 1;
	while (count <= nb / 2)
	{
		if (count * count == nb)
			return (count);
		else if (count * count > nb)
			return (0);
		count++;
	}
	return (0);
}
