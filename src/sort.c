/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:31:58 by krocha-h          #+#    #+#             */
/*   Updated: 2024/03/27 17:16:03 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	convert_to_int(char **arr, t_data *current)
{
	int	i;

	current->args = ft_calloc(sizeof(int), current->size);
	i = 0;
	while (arr[i])
	{
		current->args[i] = ft_atoi(arr[i]);
		i++;
	}
}

void	def_sort(t_stack **stack_a, t_stack **stack_b, char **arr, t_data *cur)
{
	int	size_lst;

	size_lst = cur->size;
	if (size_lst == 3)
		sort_three(stack_a);
	if (size_lst == 4)
		sort_four(stack_a, stack_b);
	if (size_lst == 5)
		sort_five(stack_a, stack_b);
	if (size_lst > 5 && size_lst <= 10)
		sort_ten(stack_a, stack_b);
	if (size_lst > 10 && size_lst <= 100)
	{
		convert_to_int(arr, cur);
		quick_sort(cur->args, 0, size_lst - 1);
		sort_hundred(stack_a, stack_b, cur);
	}
}
