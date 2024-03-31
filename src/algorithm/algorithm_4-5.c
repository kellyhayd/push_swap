/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_4-5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:58:23 by krocha-h          #+#    #+#             */
/*   Updated: 2024/03/27 10:49:35 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_four(t_stack **stack_a, t_stack **stack_b, t_data *cur)
{
	int	min;
	int	needs_pa;

	min = get_min(stack_a);
	needs_pa = 0;
	if (cur->size == 4)
	{
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
		needs_pa = 1;
	}
	cur->size = lstsize(*stack_a);
	sort_three(stack_a, cur);
	if (needs_pa)
		pa(stack_a, stack_b);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b, t_data *cur)
{
	int	min;
	int	needs_pa;

	min = get_min(stack_a);
	needs_pa = 0;
	if (cur->size == 5)
	{
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
		needs_pa = 1;
	}
	cur->size = lstsize(*stack_a);
	sort_four(stack_a, stack_b, cur);
	if (needs_pa)
		pa(stack_a, stack_b);
}
