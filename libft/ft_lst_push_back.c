/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malannys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 09:37:19 by malannys          #+#    #+#             */
/*   Updated: 2019/01/11 13:57:41 by malannys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_push_back(t_list **alst, t_list *new)
{
	t_list	*current;

	if (!alst)
		return ;
	if (!*alst)
	{
		*alst = new;
		return ;
	}
	current = *alst;
	while (current->next)
		current = current->next;
	current->next = new;
}
