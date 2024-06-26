/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_2-3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:45:56 by krocha-h          #+#    #+#             */
/*   Updated: 2024/04/01 11:14:35 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **stack)
{
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
	else
		return ;
}

static int	define_case(t_stack **stack)
{
	if ((*stack)->value < (*stack)->next->value
		&& (*stack)->next->value > (*stack)->next->next->value
		&& (*stack)->next->next->value > (*stack)->value)
		return (1);
	else if ((*stack)->value > (*stack)->next->value
		&& (*stack)->value < (*stack)->next->next->value)
		return (2);
	else if ((*stack)->value < (*stack)->next->value
		&& (*stack)->next->next->value < (*stack)->value)
		return (3);
	else if ((*stack)->value > (*stack)->next->value
		&& (*stack)->next->value < (*stack)->next->next->value)
		return (4);
	else if ((*stack)->value > (*stack)->next->value
		&& (*stack)->next->value > (*stack)->next->next->value)
		return (5);
	return (-1);
}

void	sort_three(t_stack **stack)
{
	int	n;

	n = define_case(stack);
	if (n == 1)
	{
		sa(stack);
		ra(stack);
	}
	else if (n == 2)
		sa(stack);
	else if (n == 3)
		rra(stack);
	else if (n == 4)
		ra(stack);
	else if (n == 5)
	{
		sa(stack);
		rra(stack);
	}
}
