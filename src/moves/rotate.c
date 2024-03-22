/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:02:27 by krocha-h          #+#    #+#             */
/*   Updated: 2024/03/22 13:41:47 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;

	if (lstsize(*stack) >= 2)
	{
		tmp = *stack;
		last = lstlast(*stack);
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		last->next = tmp;
		tmp->prev = last;
		tmp->next = NULL;
		update_idx(stack);
	}
}

void	ra(t_stack **stack)
{
	write(1, "ra\n", 3);
	rotate(stack);
}

void	rb(t_stack **stack)
{
	write(1, "rb\n", 3);
	rotate(stack);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	write(1, "rr\n", 3);
	rotate(stack_a);
	rotate(stack_b);
}
