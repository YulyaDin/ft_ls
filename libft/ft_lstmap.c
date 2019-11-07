/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malannys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 19:31:29 by malannys          #+#    #+#             */
/*   Updated: 2019/01/11 16:20:00 by malannys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_lst;

	if (!lst || !f)
		return (NULL);
	new_lst = (*f)(lst);
	if (!(new_lst = ft_lstnew(new_lst->content, new_lst->content_size)))
	{
		ft_lstdelone(&new_lst, &ft_del);
		return (NULL);
	}
	if (new_lst)
	{
		new_lst->next = ft_lstmap(lst->next, f);
		if (!new_lst->next && lst->next)
		{
			ft_lstdelone(&new_lst, &ft_del);
			return (NULL);
		}
	}
	return (new_lst);
}
