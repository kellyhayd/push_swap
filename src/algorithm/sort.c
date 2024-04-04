/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:31:58 by krocha-h          #+#    #+#             */
/*   Updated: 2024/04/02 14:55:51 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	convert_to_int(char **arr, t_data *data)
{
	int	i;

	data->args = ft_calloc(sizeof(int), data->asize_now);
	i = 0;
	while (arr[i])
	{
		data->args[i] = ft_atoi(arr[i]);
		i++;
	}
}

void	prep(t_stack **stack_a, t_stack **stack_b, char **arr, t_data *data)
{
	convert_to_int(arr, data);
	quick_sort(data->args, 0, data->asize_now - 1);
	sort_hundred(stack_a, stack_b, data);
}

void	def_sort(t_stack **stack_a, t_stack **stack_b, char **arr, t_data *data)
{
	int	size_lst;

	size_lst = data->asize_now;
	if (size_lst == 2)
		sort_two(stack_a);
	if (size_lst == 3)
		sort_three(stack_a, data);
	if (size_lst == 4)
		sort_four(stack_a, stack_b, data);
	if (size_lst == 5)
		sort_five(stack_a, stack_b, data);
	if (size_lst > 5 && size_lst <= 10)
		sort_ten(stack_a, stack_b, data);
	if (size_lst > 10 && size_lst <= 100)
	{
		data->def_div = 4;
		prep(stack_a, stack_b, arr, data);
	}
	if (size_lst > 100)
	{
		data->def_div = 11;
		prep(stack_a, stack_b, arr, data);
	}
	free(data->args);
}
