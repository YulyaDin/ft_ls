/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 21:00:14 by abartole          #+#    #+#             */
/*   Updated: 2019/09/04 23:41:07 by abartole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	check_options3(char *str, int *options)
{
	if (*str == 'o')
	{
		*options |= FLAG_L;
		*options &= ~(FLAG_CC);
		*options &= ~(FLAG_HH);
		*options &= ~(FLAG_M);
		*options &= ~(FLAG_ONE);
	}
	else if (*str == 'C')
	{
		*options &= ~(FLAG_L);
		*options &= ~(FLAG_O);
		*options &= ~(FLAG_M);
		*options &= ~(FLAG_ONE);
		*options &= ~(FLAG_N);
		*options &= ~(FLAG_G);
	}
}

static void	check_options2(char *str, int *options)
{
	if (*str == 'n')
	{
		*options |= FLAG_L;
		*options &= ~(FLAG_HH);
		*options &= ~(FLAG_CC);
		*options &= ~(FLAG_M);
		*options &= ~(FLAG_ONE);
	}
	else if (*str == 'g')
	{
		*options |= FLAG_L;
		*options &= ~(FLAG_CC);
		*options &= ~(FLAG_HH);
		*options &= ~(FLAG_M);
		*options &= ~(FLAG_ONE);
	}
	check_options3(str, options);
}

static void	check_options1(char *str, int *options)
{
	if (*str == 'm')
	{
		*options &= ~(FLAG_ONE);
		*options &= ~(FLAG_CC);
		*options &= ~(FLAG_N);
		*options &= ~(FLAG_O);
		*options &= ~(FLAG_G);
		*options &= ~(FLAG_L);
	}
	else if (*str == '1')
	{
		*options &= ~(FLAG_L);
		*options &= ~(FLAG_CC);
		*options &= ~(FLAG_M);
		*options &= ~(FLAG_N);
		*options &= ~(FLAG_O);
		*options &= ~(FLAG_G);
	}
	else if (*str == 'u')
		*options &= ~(FLAG_C);
	check_options2(str, options);
}

void		check_options(char *str, int *options)
{
	*options |= FLAG_HH;
	if (*str == 'l')
	{
		*options &= ~(FLAG_ONE);
		*options &= ~(FLAG_CC);
		*options &= ~(FLAG_M);
		*options &= ~(FLAG_HH);
		*options &= ~(FLAG_N);
		*options &= ~(FLAG_O);
		*options &= ~(FLAG_G);
	}
	else if (*str == 'C')
	{
		*options &= ~(FLAG_ONE);
		*options &= ~(FLAG_L);
		*options &= ~(FLAG_M);
		*options &= ~(FLAG_N);
		*options &= ~(FLAG_O);
		*options &= ~(FLAG_G);
	}
	else if (*str == 'c')
		*options &= ~(FLAG_U);
	check_options1(str, options);
}
