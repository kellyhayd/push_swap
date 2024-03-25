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

static void	swap(t_stack **stack)
{
	int	num_tmp;
	int	idx_tmp;

	num_tmp = (*stack)->num;
	idx_tmp = (*stack)->idx;
	(*stack)->num = (*stack)->next->num;
	(*stack)->idx = (*stack)->next->idx;
	(*stack)->next->num = num_tmp;
	(*stack)->next->idx = idx_tmp;
}

void	sa(t_stack **stack)
{
	write(1, "sa\n", 3);
	swap(stack);
}

void	sb(t_stack **stack)
{
	write(1, "sb\n", 3);
	swap(stack);
}

void	s_stack(t_stack **stack_a, t_stack **stack_b)
{
	write(1, "ss\n", 3);
	swap(stack_a);
	swap(stack_b);
}
