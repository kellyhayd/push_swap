/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:02:27 by krocha-h          #+#    #+#             */
/*   Updated: 2024/04/11 15:23:18 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	if (!(*stack)->next->next)
		swap(stack);
	else
	{
		last = (*stack)->next;
		while (last->next)
			last = last->next;
		last->next = *stack;
		*stack = (*stack)->next;
		last->next->next = NULL;
	}
}

int	ra(t_stack **stack)
{
	if (!ft_write(1, "ra\n", 3))
		return (0);
	rotate(stack);
	return (1);
}

int	rb(t_stack **stack)
{
	if (!ft_write(1, "rb\n", 3))
		return (0);
	rotate(stack);
	return (1);
}

int	rr(t_stack **a, t_stack **b)
{
	if (!ft_write(1, "rr\n", 3))
		return (0);
	rotate(a);
	rotate(b);
	return (1);
}
