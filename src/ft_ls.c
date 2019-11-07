/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malannys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 19:09:50 by malannys          #+#    #+#             */
/*   Updated: 2019/09/06 21:23:06 by abartole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	dir_recursive(t_node **head, int *options)
{
	t_node	*node;

	errno = 0;
	node = *head;
	while (node)
	{
		if (ft_strcmp(".", node->name) && ft_strcmp("..", node->name) \
				&& S_ISDIR(node->stats.st_mode))
		{
			write(1, "\n", 1);
			ft_putstr_fd(node->path, 1);
			write(1, ":\n", 3);
			read_dir(node->path, node, options);
		}
		node = node->next;
	}
}

void	read_dir(char *path, t_node *node, int *options)
{
	DIR				*dirp;
	struct dirent	*dp;
	t_node			*head;

	head = NULL;
	errno = 0;
	if (!(dirp = opendir(node->path)))
	{
		error(OPENDIR_FAILURE, node->name);
		return ;
	}
	while ((dp = readdir(dirp)))
		if (check_options_a(dp->d_name, options))
			push_back(&head, create_node(node->path, dp->d_name, options, 0));
	closedir(dirp);
	if (!(FLAG_F & *options))
		sort(&head, (head ? &head->tail : NULL), options);
	print(path, head, options, 1);
	if (FLAG_RR & *options)
		dir_recursive(&head, options);
	free_list(&head);
}

/*
** Make 2 lists: for directories and for other types, sort each and
** display other types list first, and dirs second.
** If there is only one arg, don't display the path
*/

void	read_args_dir(int check, int *options,
						t_node *head_dir, t_node *head_file)
{
	t_node	*tmp;

	tmp = head_dir;
	while (tmp)
	{
		if (!check)
			read_dir(NULL, tmp, options);
		else
		{
			ft_putstr_fd(tmp->name, 1);
			write(1, ":\n", 3);
			read_dir(tmp->name, tmp, options);
		}
		tmp = tmp->next;
		if (tmp)
			write(1, "\n", 1);
	}
	free_list(&head_dir);
	free_list(&head_file);
}

void	read_args(int ac, char **av, int *options, int arg)
{
	int			i;
	t_node		*tmp;
	t_node		*head_file;
	t_node		*head_dir;

	i = arg - 1;
	head_dir = NULL;
	head_file = NULL;
	while (++i < ac)
	{
		tmp = create_node(NULL, av[i], options, 1);
		if (tmp && S_ISDIR(tmp->stats.st_mode))
			push_back(&head_dir, tmp);
		else if (tmp)
			push_back(&head_file, tmp);
	}
	if (!(FLAG_F & *options))
	{
		sort(&head_file, (head_file ? &head_file->tail : NULL), options);
		sort(&head_dir, (head_dir ? &head_dir->tail : NULL), options);
	}
	print(NULL, head_file, options, 0);
	if (head_file && head_dir)
		write(1, "\n", 1);
	read_args_dir(arg - ac + 1, options, head_dir, head_file);
}

int		main(int ac, char **av)
{
	int		options;
	int		i;
	t_node	tmp;

	options = 0;
	i = opt_parser(ac, av, &options);
	if (i == ac)
	{
		tmp.path = ".";
		ft_strcpy(tmp.name, ".");
		read_dir(NULL, &tmp, &options);
	}
	else
	{
		if ((ft_quick_sort(&av[i], 0, ac - i - 1)) == -1)
			error(MALLOC_FAILURE, NULL);
		read_args(ac, av, &options, i);
	}
	return (0);
}
