/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 20:32:16 by abartole          #+#    #+#             */
/*   Updated: 2019/09/06 22:13:52 by abartole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	check_all_flags1(int *options)
{
	if (*options & FLAG_F)
	{
		*options |= FLAG_A;
		*options &= ~(FLAG_SS);
	}
	if (*options & FLAG_SS)
	{
		*options &= ~(FLAG_U);
		*options &= ~(FLAG_UU);
		*options &= ~(FLAG_C);
	}
}

void		check_all_flags(int *options)
{
	if (!(*options & FLAG_L))
	{
		*options |= FLAG_HH;
		*options &= ~(FLAG_TT);
		*options &= ~(FLAG_EA);
	}
	if (!((*options & FLAG_L) || (*options & FLAG_T)))
	{
		*options &= ~(FLAG_C);
		*options &= ~(FLAG_U);
		*options &= ~(FLAG_UU);
	}
	if ((*options & FLAG_F) || (*options & FLAG_SS))
	{
		*options &= ~(FLAG_T);
		*options &= ~(FLAG_C);
		*options &= ~(FLAG_U);
		*options &= ~(FLAG_UU);
	}
	if (*options & FLAG_F)
		*options &= ~(FLAG_R);
	check_all_flags1(options);
}

static int	get_index(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		++i;
	}
	return (-1);
}

static int	get_options(char *src, char *str, int *options)
{
	int	n;

	while (*(++str))
	{
		if ((n = get_index("1AaCcfglmnoRrSTtuU@H", *str)) == -1)
			error_usage(src, str, 1);
		*options |= (1 << n);
		check_options(str, options);
	}
	return (1);
}

int			opt_parser(int ac, char **av, int *options)
{
	int i;

	i = 0;
	while (++i < ac && av[i][0] == '-' && av[i][1])
	{
		if (av[i][1] == '-' && !av[i][2])
			return (i + 1);
		if (!get_options(av[0], av[i], options))
			return (-1);
	}
	check_all_flags(options);
	return (i);
}
