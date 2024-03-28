/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:03:01 by krocha-h          #+#    #+#             */
/*   Updated: 2024/03/22 13:41:41 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;
	t_stack	*penult;

	if (lstsize(*stack) >= 2)
	{
		tmp = (*stack);
		last = lstlast(*stack);
		penult = last->prev;
		penult->next = NULL;
		last->prev = NULL;
		tmp->prev = last;
		last->next = tmp;
		*stack = last;
		update_idx(stack);
	}
}

void	rra(t_stack **stack)
{
	write(1, "rra\n", 3);
	reverse_rotate(stack);
}

void	rrb(t_stack **stack)
{
	write(1, "rrb\n", 3);
	reverse_rotate(stack);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	write(1, "rrr\n", 3);
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
