/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malannys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 20:48:32 by malannys          #+#    #+#             */
/*   Updated: 2018/12/18 21:42:55 by malannys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	size_t	i;
	char	sgn;
	long	res;

	i = 0;
	res = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		sgn = *str / 44;
		str++;
	}
	while (*str && ft_isdigit(*str))
	{
		res = res * 10 + (*str++ - '0');
		if (res < 0)
			return (sgn == 1 ? 0 : -1);
	}
	return (sgn == 1 ? -res : res);
}
