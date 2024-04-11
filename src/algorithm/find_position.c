/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:13:51 by krocha-h          #+#    #+#             */
/*   Updated: 2024/04/11 15:20:16 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_index(const t_stack *stack)
{
	int	i;
	int	max_index;
	int	max_value;

	max_index = 0;
	i = 0;
	while (stack)
	{
		if (i == 0 || stack->value > max_value)
		{
			max_index = i;
			max_value = stack->value;
		}
		i++;
		stack = stack->next;
	}
	return (max_index);
}

int	find_greatest_lower_than_index(const t_stack *stack, int value)
{
	int	i;
	int	greatest_idx;
	int	greatest_value;

	if (!stack)
		return (0);
	i = 0;
	greatest_idx = -1;
	greatest_value = INT_MIN;
	while (stack)
	{
		if (stack->value < value && stack->value > greatest_value)
		{
			greatest_idx = i;
			greatest_value = stack->value;
		}
		i++;
		stack = stack->next;
	}
	return (greatest_idx);
}
