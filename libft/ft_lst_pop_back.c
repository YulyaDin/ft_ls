/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_pop_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malannys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 09:53:37 by malannys          #+#    #+#             */
/*   Updated: 2019/01/11 14:42:54 by malannys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_pop_back(t_list **alst)
{
	t_list	*tmp;

	if (!alst || !*alst)
		return ;
	tmp = *alst;
	while (tmp->next)
	{
		if ((tmp->next)->next)
		{
			tmp = tmp->next;
			continue ;
		}
		ft_lstdelone(&tmp->next, &ft_del);
		tmp->next = NULL;
		return ;
	}
	ft_lstdelone(&tmp, &ft_del);
}
