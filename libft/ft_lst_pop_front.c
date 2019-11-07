/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_pop_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malannys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 10:09:10 by malannys          #+#    #+#             */
/*   Updated: 2019/01/11 14:42:57 by malannys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_pop_front(t_list **alst)
{
	t_list	*tmp;

	if (!alst || !*alst)
		return ;
	tmp = *alst;
	*alst = tmp->next;
	ft_lstdelone(&tmp, &ft_del);
}
