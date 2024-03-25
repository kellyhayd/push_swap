/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:58:23 by krocha-h          #+#    #+#             */
/*   Updated: 2024/03/25 17:13:15 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_stack **stack)
{
	int		min;
	t_stack *tmp;

	tmp = (*stack);
	min = (*stack)->num;
	while (tmp && tmp->next)
	{
		tmp = tmp->next;
		if (min > tmp->num)
			min = tmp->num;
	}
	return (min);
}

void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	int	min;

	min = get_min(stack_a);
	if ((*stack_a)->next->num == min)
		sa(stack_a);
	else if ((*stack_a)->next->next->num == min)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if ((*stack_a)->next->next->next->num == min)
		rra(stack_a);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	min;

	min = get_min(stack_a);
	if ((*stack_a)->next->num == min)
		sa(stack_a);
	else if ((*stack_a)->next->next->num == min)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if ((*stack_a)->next->next->next->num == min)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if ((*stack_a)->next->next->next->next->num == min)
		rra(stack_a);
	pb(stack_a, stack_b);
	sort_four(stack_a, stack_b);
	pa(stack_a, stack_b);
}
