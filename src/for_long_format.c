/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_long_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 23:29:55 by abartole          #+#    #+#             */
/*   Updated: 2019/09/04 23:50:22 by abartole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	get_size2(t_node *tmp, int maxlen)
{
	int	len;

	len = nb_len(tmp->stats.st_size);
	while (len < maxlen)
	{
		write(1, " ", 1);
		len++;
	}
	ft_putnbr(tmp->stats.st_size);
}

void		get_size(t_node *tmp, int maxlen)
{
	int	max;
	int	min;

	if (S_ISBLK(tmp->stats.st_mode) || S_ISCHR(tmp->stats.st_mode))
	{
		max = nb_len(major(tmp->stats.st_rdev));
		min = nb_len(minor(tmp->stats.st_rdev));
		while (max++ < 3)
			write(1, " ", 1);
		ft_putnbr(major(tmp->stats.st_rdev));
		if (major(tmp->stats.st_rdev) == 0 || major(tmp->stats.st_rdev))
			ft_putchar(',');
		ft_putchar(' ');
		while (min++ < 3)
			write(1, " ", 1);
		ft_putnbr(minor(tmp->stats.st_rdev));
	}
	else
		get_size2(tmp, maxlen);
	write(1, " ", 1);
}

void		get_name(t_node *tmp, int *options, int *maxlen)
{
	int				len;
	int				i;
	struct passwd	*pwd;

	pwd = getpwuid(tmp->stats.st_uid);
	if (!pwd)
		error(GETPWUID_FAILURE, tmp->name);
	if (FLAG_N & *options)
	{
		len = nb_len(pwd->pw_uid);
		i = maxlen[MAX_UID] + 2;
		ft_putnbr(pwd->pw_uid);
	}
	else
	{
		len = ft_strlen(pwd->pw_name);
		i = maxlen[MAX_PWD] + 2;
		write(1, pwd->pw_name, len);
	}
	while (len < i)
	{
		write(1, " ", 1);
		len++;
	}
}

time_t		get_correct_time(t_node *tmp, int *options)
{
	time_t	time_sec;

	if (FLAG_U & *options)
		time_sec = tmp->stats.st_atime;
	else if (FLAG_UU & *options)
		time_sec = tmp->stats.st_birthtime;
	else if (FLAG_C & *options)
		time_sec = tmp->stats.st_ctime;
	else
		time_sec = tmp->stats.st_mtime;
	return (time_sec);
}

void		get_time(t_node *tmp, int *options)
{
	char	*print_time;
	char	*tmp_time;
	time_t	time_sec;

	print_time = NULL;
	time_sec = get_correct_time(tmp, options);
	print_time = (FLAG_TT & *options) ? ft_memalloc(21) : ft_memalloc(13);
	tmp_time = ctime(&time_sec);
	if (FLAG_TT & *options)
		print_time = ft_strncpy(print_time, &(tmp_time[4]), 20);
	else
	{
		print_time = ft_strncpy(print_time, &(tmp_time[4]), 6);
		if ((time(NULL) - time_sec < 15897600) && (time(NULL) - time_sec >= 0))
			print_time = ft_strncat(print_time, &(tmp_time[10]), 6);
		else
		{
			print_time[6] = ' ';
			print_time = ft_strncat(print_time, &(tmp_time[19]), 5);
		}
	}
	ft_putstr(print_time);
	write(1, " ", 1);
	ft_strdel(&print_time);
}
