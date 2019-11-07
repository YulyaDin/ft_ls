/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 16:40:56 by abartole          #+#    #+#             */
/*   Updated: 2019/09/04 21:18:35 by abartole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_group(t_node *tmp, int *options, int *maxlen)
{
	int				len;
	int				i;
	struct group	*gp;

	gp = getgrgid(tmp->stats.st_gid);
	if (!gp)
		error(GETGRGID_FAILURE, tmp->name);
	if (FLAG_N & *options)
	{
		len = nb_len(gp->gr_gid);
		i = maxlen[MAX_GID] + 2;
		ft_putnbr(gp->gr_gid);
	}
	else
	{
		len = ft_strlen(gp->gr_name);
		i = maxlen[MAX_GP] + 2;
		write(1, gp->gr_name, len);
	}
	while (len < i)
	{
		write(1, " ", 1);
		len++;
	}
}

void	print_string_helper(t_node *tmp)
{
	ft_putstr(tmp->name);
	ft_putstr(", ");
}

void	print_string(t_node *tmp)
{
	struct winsize	ws;
	size_t			len;
	int				atty;

	atty = isatty(1);
	ioctl(1, TIOCGWINSZ, &ws);
	len = 0;
	ws.ws_col = (atty == 0) ? 80 : ws.ws_col;
	while (tmp)
	{
		if (len + ft_strlen(tmp->name) + 3 > ws.ws_col)
		{
			ft_putchar('\n');
			len = 0;
		}
		if (tmp->next)
		{
			print_string_helper(tmp);
			len += (ft_strlen(tmp->name) + 2);
		}
		else
			ft_putstr(tmp->name);
		tmp = tmp->next;
	}
	ft_putchar('\n');
}
