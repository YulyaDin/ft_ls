/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malannys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 21:48:43 by malannys          #+#    #+#             */
/*   Updated: 2019/01/10 18:53:01 by malannys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

void		ft_putnbr_fd(int n, int fd)
{
	char sign;

	sign = n < 0 ? -1 : 1;
	if (sign == -1)
		ft_putchar('-', fd);
	if (n / 10 != 0)
		ft_putnbr_fd(sign * (n / 10), fd);
	ft_putchar(sign * (n % 10) + '0', fd);
}
