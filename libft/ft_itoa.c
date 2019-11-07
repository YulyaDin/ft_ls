/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malannys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 19:36:43 by malannys          #+#    #+#             */
/*   Updated: 2018/12/18 19:36:45 by malannys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_ch(int n)
{
	size_t	count;

	count = 1;
	if (n < 0)
		count++;
	while (n /= 10)
		count++;
	return (count);
}

char			*ft_itoa(int n)
{
	size_t	ch_num;
	short	sgn;
	char	*str;

	sgn = (n < 0) ? -1 : 1;
	ch_num = count_ch(n);
	if (!(str = ft_strnew(ch_num)))
		return (NULL);
	str[--ch_num] = (n % 10) * sgn + '0';
	while (n /= 10)
		str[--ch_num] = (n % 10) * sgn + '0';
	if (sgn == -1)
		str[0] = '-';
	return (str);
}
