/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_column.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 19:33:56 by abartole          #+#    #+#             */
/*   Updated: 2019/09/06 22:13:37 by abartole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	get_number(t_node *head)
{
	int		i;
	t_node	*tmp;

	tmp = head;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

static void	print_spaces(int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		ft_putchar(' ');
		i++;
	}
}

static void	print_columns(t_node *head, t_point max, t_point index)
{
	t_node	*tmp;
	int		row;
	int		col;
	int		i;

	i = index.y;
	while (head && i--)
	{
		col = index.x;
		tmp = head->next;
		while (head && col--)
		{
			ft_putstr(head->name);
			if (col && max.x > (int)ft_strlen(head->name))
				print_spaces(max.x - (int)ft_strlen(head->name));
			row = index.y;
			while (head && row--)
				head = head->next;
		}
		ft_putchar('\n');
		head = tmp;
	}
}

void		print_default(t_node *head)
{
	t_point			max;
	t_point			index;
	struct winsize	ws;
	int				atty;

	atty = isatty(1);
	max.x = get_maxlen_name(head) + (8 - ((get_maxlen_name(head) % 8)));
	max.y = 0;
	ioctl(0, TIOCGWINSZ, &ws);
	index.y = get_number(head);
	if (atty == 0)
	{
		print_column(head);
		return ;
	}
	index.x = ws.ws_col / max.x;
	if (index.x == 0)
		index.x = 1;
	index.y = (index.y % index.x ? 1 : 0) + index.y / index.x;
	print_columns(head, max, index);
}

void		print_column(t_node *tmp)
{
	while (tmp)
	{
		ft_putstr(tmp->name);
		write(1, "\n", 1);
		tmp = tmp->next;
	}
}
