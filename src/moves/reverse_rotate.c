/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:03:01 by krocha-h          #+#    #+#             */
/*   Updated: 2024/03/22 13:18:41 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;
	t_stack	*penultimate;

	if (lstsize(*stack) >= 2)
	{
		tmp = (*stack);
		last = lstlast(*stack);
		penultimate = last->prev;
		penultimate->next = NULL;
		last->prev = NULL;
		tmp->prev = last;
		last->next = tmp;
		*stack = last;
	}
}

void	rra(t_stack **stack)
{
	write(1, "ra\n", 3);
	reverse_rotate(stack);
}

void	rrb(t_stack **stack)
{
	write(1, "rb\n", 3);
	reverse_rotate(stack);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	write(1, "rr\n", 3);
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
