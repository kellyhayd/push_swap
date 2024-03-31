/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:04:23 by krocha-h          #+#    #+#             */
/*   Updated: 2024/03/25 17:14:03 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **stack_src, t_stack **stack_dest)
{
	t_stack	*node_to_push;

	if ((*stack_src) == NULL)
		return ;
	node_to_push = *stack_src;
	*stack_src = (*stack_src)->next;
	if (*stack_src)
		(*stack_src)->prev = NULL;
	node_to_push->next = *stack_dest;
	if (*stack_dest)
		(*stack_dest)->prev = node_to_push;
	*stack_dest = node_to_push;
	update_idx(stack_src);
	update_idx(stack_dest);
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
}
