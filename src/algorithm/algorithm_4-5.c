/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_4-5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:58:23 by krocha-h          #+#    #+#             */
/*   Updated: 2024/04/01 14:42:14 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	int	min;
	int	needs_pa;

	min = get_min(stack_a);
	needs_pa = 0;
	if ((*stack_a)->next->value == min)
		sa(stack_a);
	else if ((*stack_a)->next->next->value == min)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if ((*stack_a)->next->next->next->value == min)
		rra(stack_a);
	pb(stack_a, stack_b);
	needs_pa = 1;
	sort_three(stack_a);
	if (needs_pa)
		pa(stack_a, stack_b);
}

void	move_five(t_stack **stack_a, t_stack **stack_b, int min)
{
	if ((*stack_a)->next->value == min)
		sa(stack_a);
	else if ((*stack_a)->next->next->value == min)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if ((*stack_a)->next->next->next->value == min)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if ((*stack_a)->next->next->next->next->value == min)
		rra(stack_a);
	pb(stack_a, stack_b);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	min;
	int	needs_pa;

	min = get_min(stack_a);
	needs_pa = 0;
	move_five(stack_a, stack_b, min);
	needs_pa = 1;
	sort_four(stack_a, stack_b);
	if (needs_pa)
		pa(stack_a, stack_b);
}
