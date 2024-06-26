/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:03:01 by krocha-h          #+#    #+#             */
/*   Updated: 2024/04/12 10:25:10 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*prev;

	if (!*stack || !(*stack)->next)
		return ;
	if (!(*stack)->next->next)
		swap(stack);
	else
	{
		prev = *stack;
		last = (*stack)->next;
		while (last->next)
		{
			prev = last;
			last = last->next;
		}
		prev->next = NULL;
		last->next = *stack;
		*stack = last;
	}
}

int	rra(t_stack **stack)
{
	if (!ft_putstr("rra\n"))
		return (0);
	reverse_rotate(stack);
	return (1);
}

int	rrb(t_stack **stack)
{
	if (!ft_putstr("rrb\n"))
		return (0);
	reverse_rotate(stack);
	return (1);
}

int	rrr(t_stack **a, t_stack **b)
{
	if (!ft_putstr("rrr\n"))
		return (0);
	reverse_rotate(a);
	reverse_rotate(b);
	return (1);
}
