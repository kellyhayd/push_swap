/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:59:23 by krocha-h          #+#    #+#             */
/*   Updated: 2024/03/25 11:28:25 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	partition(int *array, int start, int end)
{
	int	i;
	int	j;
	int	pivot;

	pivot = array[end];
	i = start -1;
	j = start;
	while (j < end)
	{
		if (array[j] < pivot)
		{
			i++;
			ft_swap(&array[i], &array[j]);
		}
		j++;
	}
	ft_swap(&array[i + 1], &array[end]);
	return (i + 1);
}

void	quick_sort(int *array, int start, int end)
{
	int	pivot_idx;

	if (start < end)
	{
		pivot_idx = partition(array, start, end);
		quick_sort(array, start, pivot_idx - 1);
		quick_sort(array, pivot_idx + 1, end);
	}
}
