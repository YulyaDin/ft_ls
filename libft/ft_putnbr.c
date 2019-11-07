/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malannys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 19:55:18 by malannys          #+#    #+#             */
/*   Updated: 2019/01/10 18:51:27 by malannys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putnbr(int n)
{
	char sign;

	sign = n < 0 ? -1 : 1;
	if (sign == -1)
		ft_putchar('-');
	if (n / 10 != 0)
		ft_putnbr(sign * (n / 10));
	ft_putchar(sign * (n % 10) + '0');
}
