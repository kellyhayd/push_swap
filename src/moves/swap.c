/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:01:42 by krocha-h          #+#    #+#             */
/*   Updated: 2024/03/25 11:25:45 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (!*stack || !(*stack)->next)
		return;
	first = (*stack)->next;
	second = *stack;
	third = (*stack)->next->next;
	first->next = second;
	second->next = third;
	*stack = first;
}

int	sa(t_stack **stack)
{
	if (!ft_write(1, "sa\n", 3))
		return (0);
	swap(stack);
	return (1);
}

int	sb(t_stack **stack)
{
	if (!ft_write(1, "sb\n", 3))
		return (0);
	swap(stack);
	return (1);
}

int	ss(t_stack **a, t_stack **b)
{
	if (!ft_write(1, "ss\n", 3))
		return (0);
	swap(a);
	swap(b);
	return (1);
}
