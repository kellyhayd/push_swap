/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_10.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:43:37 by krocha-h          #+#    #+#             */
/*   Updated: 2024/04/01 11:14:35 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	order_to_b(t_stack **stack_a, t_stack **stack_b, t_data *data)
{
	t_stack	*node_min;
	int		min;
	int		middle;
	int		direction;

	min = get_min(stack_a);
	node_min = *stack_a;
	while (node_min->num != min)
		node_min = node_min->next;
	middle = data->size_now / 2;
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
	data->size_now = lstsize(*stack_a);
}

void	sort_ten(t_stack **stack_a, t_stack **stack_b, t_data *data)
{
	t_stack	*tmp_b;

	tmp_b = *stack_b;
	while (data->size_now > 5)
		order_to_b(stack_a, stack_b, data);
	sort_five(stack_a, stack_b, data);
	while (*stack_b != tmp_b)
		pa(stack_a, stack_b);
}
