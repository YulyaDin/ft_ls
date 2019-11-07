/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malannys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 13:52:18 by malannys          #+#    #+#             */
/*   Updated: 2019/01/11 16:02:52 by malannys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_pow(int nb, int power)
{
	int	count;
	int	res;

	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	count = 1;
	res = nb;
	while (count < power)
	{
		res *= nb;
		count++;
	}
	return (res);
}
