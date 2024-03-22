/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:04:23 by krocha-h          #+#    #+#             */
/*   Updated: 2024/03/22 13:14:14 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **stack_src, t_stack **stack_dest)
{
	t_stack	*node_to_push;

	if ((*stack_src) == NULL)
		return ;
	node_to_push = *stack_src;
	*stack_src = (*stack_src)->next;
	node_to_push->next = *stack_dest;
	*stack_dest = node_to_push;
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	write(1, "pa\n", 3);
	push(stack_a, stack_b);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	write(1, "pb\n", 3);
	push(stack_b, stack_a);
}
