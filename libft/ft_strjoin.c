/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malannys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 19:46:42 by malannys          #+#    #+#             */
/*   Updated: 2019/01/10 16:09:31 by malannys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 && s2)
	{
		new_str = ft_strdup(s2);
		return (new_str);
	}
	if (s1 && !s2)
	{
		new_str = ft_strdup(s1);
		return (new_str);
	}
	new_str = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (new_str)
	{
		new_str = ft_strcat(new_str, s1);
		new_str = ft_strcat(new_str, s2);
	}
	return (new_str);
}
