/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:45:56 by krocha-h          #+#    #+#             */
/*   Updated: 2024/03/25 16:05:41 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **stack)
{
	if ((*stack)->num > (*stack)->next->num)
		sa(stack);
	else
		return ;
}

static int	define_case(t_stack **stack)
{
	if ((*stack)->num < (*stack)->next->num
		&& (*stack)->next->num > (*stack)->next->next->num
		&& (*stack)->next->next->num > (*stack)->num)
		return (1);
	else if ((*stack)->num > (*stack)->next->num
		&& (*stack)->num < (*stack)->next->next->num)
		return (2);
	else if ((*stack)->num < (*stack)->next->num
		&& (*stack)->next->next->num < (*stack)->num)
		return (3);
	else if ((*stack)->num > (*stack)->next->num
		&& (*stack)->next->num < (*stack)->next->next->num)
		return (4);
	else if ((*stack)->num > (*stack)->next->num
		&& (*stack)->next->num > (*stack)->next->next->num)
		return (5);
	return (-1);
}

void	sort_three(t_stack **stack, t_data *cur)
{
	int	n;

	if (cur->size == 3)
	{
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
	else if (cur->size == 2)
		sort_two(stack);
}
