/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:31:58 by krocha-h          #+#    #+#             */
/*   Updated: 2024/03/27 16:05:53 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*convert_to_int(char **array, int size_lst)
{
	int	i;
	int	*args;

	args = ft_calloc(sizeof(int), size_lst);
	i = 0;
	while (array[i])
	{
		args[i] = ft_atoi(array[i]);
		i++;
	}
	return (args);
}

void	define_sort(t_stack **stack_a, t_stack **stack_b, char **array, int size_lst)
{
	int	*args;

	// size_lst = (*stack_a)->size;
	printf("size = %d\n", size_lst);
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
		args = convert_to_int(array, size_lst);
		quick_sort(args, 0, size_lst - 1);
		// sort_hundred(stack_a, stack_b, args);
	}
}
