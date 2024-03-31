/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_10.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:43:37 by krocha-h          #+#    #+#             */
/*   Updated: 2024/03/27 15:07:57 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_ten(t_stack **stack_a, t_stack **stack_b, t_data *cur)
{
	t_stack	*node_min;
	t_stack	*tmp_b;
	int		min;
	int		middle;
	int		direction;

	tmp_b = *stack_b;
	while (cur->size > 5)
	{
		min = get_min(stack_a);
		node_min = *stack_a;
		while (node_min->num != min)
			node_min = node_min->next;
		middle = cur->size / 2;
		if (node_min->idx >= middle)
			direction = 1;
		else
			direction = 2;
		while ((*stack_a)->num != min)
		{
			if (direction == 1)
				rra(stack_a);
			else if (direction == 2)
				ra(stack_a);
		}
		pb(stack_a, stack_b);
		cur->size = lstsize(*stack_a);
	}
	sort_five(stack_a, stack_b, cur);
	while (*stack_b != tmp_b)
		pa(stack_a, stack_b);
}
