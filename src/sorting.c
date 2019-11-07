/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malannys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 15:19:51 by malannys          #+#    #+#             */
/*   Updated: 2019/08/21 19:32:42 by malannys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	initialize_for_sort_start(t_node **node, t_node **head)
{
	ft_bzero(node, sizeof(t_node *) * 8);
	node[6] = *head;
	node[7] = *head;
}

static void	initialize_for_sort_end(t_node **node, t_node **head, t_node **tail)
{
	*head = node[0];
	*tail = node[5];
}

/*
** 	t_node	*less_head = NULL; -- node[0]
**	t_node	*less_tail = NULL; -- node[1]
**	t_node	*equ_head = NULL;  -- node[2]
**	t_node	*equ_tail = NULL;  -- node[3]
**	t_node	*lar_head = NULL;  -- node[4]
**	t_node	*lar_tail = NULL;  -- node[5]
**	t_node	*tmp = *head;      -- node[6]
**	t_node	*pivot = *head;    -- node[7]
*/

void		sort(t_node **head, t_node **tail, int *options)
{
	t_node	*node[8];
	int		compare;

	initialize_for_sort_start(node, head);
	if (node[6] == NULL)
		return ;
	while (node[6] != NULL)
	{
		compare = cmp(node[6], node[7], options);
		if (compare < 0)
			append(&node[0], &node[1], node[6]);
		else if (compare > 0)
			append(&node[4], &node[5], node[6]);
		else
			append(&node[2], &node[3], node[6]);
		if (node[6] == *tail)
			break ;
		node[6] = node[6]->next;
	}
	sort(&node[0], &node[1], options);
	sort(&node[4], &node[5], options);
	lst_join(&node[0], &node[1], &node[2], &node[3]);
	lst_join(&node[0], &node[3], &node[4], &node[5]);
	initialize_for_sort_end(node, head, tail);
}
