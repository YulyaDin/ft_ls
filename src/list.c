/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malannys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 15:18:12 by malannys          #+#    #+#             */
/*   Updated: 2019/09/06 21:23:29 by abartole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	push_back(t_node **head, t_node *node)
{
	if (!head || !node)
		return ;
	node->tail = node;
	if (!*head)
		*head = node;
	else
	{
		(*head)->tail->next = node;
		(*head)->tail = node;
	}
}

t_node	*create_node(char *path, char *name, int *options, int follow_link)
{
	t_node	*node;
	int		failed;

	errno = 0;
	if (!(node = (t_node *)malloc(sizeof(t_node))))
		error(MALLOC_FAILURE, NULL);
	if (!(node->path = add_path(path, name)))
		error(MALLOC_FAILURE, NULL);
	if (follow_link && (FLAG_HH & *options))
		failed = stat(node->path, &node->stats);
	else
		failed = lstat(node->path, &node->stats);
	if ((follow_link || (FLAG_L & *options)
			|| (FLAG_SS & *options) || (FLAG_RR & *options) ||
			(FLAG_T & *options)) && failed == -1)
	{
		if (follow_link)
			error(LSTAT_FAILURE, name);
		free(node->path);
		free(node);
		return (NULL);
	}
	ft_strcpy(node->name, name);
	node->next = NULL;
	return (node);
}

void	lst_join(t_node **head1, t_node **tail1, t_node **head2, t_node **tail2)
{
	if (!(*head1 || *head2))
		return ;
	if (!*head1)
	{
		(*tail2)->next = NULL;
		*head1 = *head2;
		*tail1 = *tail2;
	}
	else if (!*head2)
	{
		(*tail1)->next = NULL;
		*head2 = *head1;
		*tail2 = *tail1;
	}
	else
	{
		(*tail1)->next = *head2;
		(*tail2)->next = NULL;
	}
}

void	append(t_node **head, t_node **tail, t_node *tmp)
{
	if (!tmp)
		return ;
	if (!*head)
		*head = tmp;
	else
		(*tail)->next = tmp;
	*tail = tmp;
}

void	free_list(t_node **head)
{
	t_node	*tmp;
	t_node	*prev;

	prev = *head;
	while (prev)
	{
		tmp = prev->next;
		free(prev->path);
		free(prev);
		prev = tmp;
	}
	*head = NULL;
}
