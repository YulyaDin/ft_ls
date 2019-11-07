/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malannys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 20:21:09 by malannys          #+#    #+#             */
/*   Updated: 2019/09/04 21:11:02 by malannys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	swap(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s2;
	*s2 = *s1;
	*s1 = tmp;
}

static int	partition(char **arr, int low, int high)
{
	int		i;
	int		j;
	char	*pivot;

	i = low;
	j = high;
	if (!(pivot = ft_strdup(arr[(low + high) / 2])))
		return (-1);
	while (i < j)
	{
		while ((ft_strcmp(arr[i], pivot) <= 0) && (i < high))
			i++;
		while ((ft_strcmp(arr[j], pivot) >= 0) && (j > low))
			j--;
		if (i >= j)
		{
			free(pivot);
			return (j);
		}
		swap(&arr[i], &arr[j]);
	}
	free(pivot);
	return (j);
}

int			ft_quick_sort(char **arr, int low, int high)
{
	int		pivot;

	if (low >= high)
		return (0);
	if ((pivot = partition(arr, low, high)) == -1)
		return (-1);
	if (ft_quick_sort(arr, low, pivot - 1) == -1)
		return (-1);
	if (ft_quick_sort(arr, pivot + 1, high) == -1)
		return (-1);
	return (0);
}
