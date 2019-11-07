/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_maxlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 23:28:26 by abartole          #+#    #+#             */
/*   Updated: 2019/09/03 22:33:29 by abartole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		get_maxlen_name(t_node *tmp)
{
	int	maxlen;
	int	len;

	maxlen = 0;
	len = 0;
	while (tmp)
	{
		len = (int)ft_strlen(tmp->name);
		if (len > maxlen)
			maxlen = len;
		tmp = tmp->next;
	}
	return (maxlen);
}

void	get_maxlen_user(t_node *tmp, int *max, int *options)
{
	struct passwd	*pwd;

	errno = 0;
	if (!(pwd = getpwuid(tmp->stats.st_uid)))
	{
		error(GETPWUID_FAILURE, tmp->name);
		return ;
	}
	if (FLAG_N & *options)
		max[MAX_UID] = MAX(nb_len(pwd->pw_uid), max[MAX_UID]);
	else
		max[MAX_PWD] = MAX((int)ft_strlen(pwd->pw_name), max[MAX_PWD]);
}

void	get_maxlen_group(t_node *tmp, int *max, int *options)
{
	struct group	*gp;

	errno = 0;
	if (!(gp = getgrgid(tmp->stats.st_gid)))
	{
		error(GETGRGID_FAILURE, tmp->name);
		return ;
	}
	if (FLAG_N & *options)
		max[MAX_GID] = MAX(nb_len(gp->gr_gid), max[MAX_GID]);
	else
		max[MAX_GP] = MAX((int)ft_strlen(gp->gr_name), max[MAX_GP]);
}

void	get_maxlen(t_node *tmp, int *max, int *options)
{
	while (tmp)
	{
		max[MAX_LNK] = MAX(nb_len(tmp->stats.st_nlink), max[MAX_LNK]);
		if (S_ISBLK(tmp->stats.st_mode))
			max[MAX_SZ] = MAX(8, max[MAX_SZ]);
		else
			max[MAX_SZ] = MAX(nb_len(tmp->stats.st_size), max[MAX_SZ]);
		if (!(FLAG_G & *options))
			get_maxlen_user(tmp, max, options);
		if (!(FLAG_O & *options))
			get_maxlen_group(tmp, max, options);
		tmp = tmp->next;
	}
}

int		nb_len(long long n)
{
	int	i;

	i = 1;
	while ((n = n / 10))
		i++;
	return (i);
}
