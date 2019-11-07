/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 16:36:33 by abartole          #+#    #+#             */
/*   Updated: 2019/09/04 21:14:32 by abartole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		get_symlink(nlink_t st_nlink, int maxlen)
{
	int	len;

	len = nb_len(st_nlink);
	while (len < maxlen)
	{
		write(1, " ", 1);
		len++;
	}
	ft_putnbr(st_nlink);
	write(1, " ", 1);
}

static int	get_total(t_node *head, int *options)
{
	t_node	*tmp;
	int		blocks;

	tmp = head;
	blocks = 0;
	while (tmp)
	{
		if (!(FLAG_A & *options) && tmp->name[0] != '.')
			blocks += tmp->stats.st_blocks;
		else if (FLAG_A & *options)
			blocks += tmp->stats.st_blocks;
		tmp = tmp->next;
	}
	return (blocks);
}

void		print_total(t_node *tmp, int *options)
{
	ft_putstr("total ");
	ft_putnbr(get_total(tmp, options));
	write(1, "\n", 1);
}

void		print_link(t_node *tmp)
{
	char	link[256];
	int		i;

	ft_bzero(link, 256);
	i = readlink(tmp->path, link, 255);
	if (i < 0 && i > tmp->stats.st_size + 1)
		error(READLINK_FAILURE, tmp->name);
	ft_putstr(tmp->name);
	link[i] = '\0';
	ft_putstr(" -> ");
	ft_putstr(link);
}

void		print_info(t_node *tmp, int *maxlen, int *options)
{
	type_perm(tmp->path, tmp->stats.st_mode);
	get_symlink(tmp->stats.st_nlink, maxlen[MAX_LNK]);
	if (!(FLAG_G & *options))
		get_name(tmp, options, maxlen);
	if (!(FLAG_O & *options))
		get_group(tmp, options, maxlen);
	get_size(tmp, maxlen[MAX_SZ]);
	get_time(tmp, options);
	if (S_ISLNK(tmp->stats.st_mode))
		print_link(tmp);
	else
		ft_putstr(tmp->name);
	write(1, "\n", 1);
	if (FLAG_EA & *options)
		print_attr(tmp, options);
}
