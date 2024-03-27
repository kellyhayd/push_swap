/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_100.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:13:51 by krocha-h          #+#    #+#             */
/*   Updated: 2024/03/27 17:48:20 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	send_to_b(t_stack **stack_a, t_stack **stack_b, int size, int tmp_max)
{
	int	proximity;
	int	direction;

	proximity = (size - 1) / 2;
	if ((*stack_a)->idx >= proximity)
		direction = 1;
	else
		direction = 2;
	while ((*stack_a)->idx != 0 && (*stack_a)->num > tmp_max)
	{
		if (direction == 1)
			ra(stack_a);
		else
			rra(stack_a);
	}
	pb(stack_a, stack_b);
}

void	sort_hundred(t_stack **stack_a, t_stack **stack_b, int *args, int size)
{
	int	div;
	int	tmp_max;
	t_stack	*tmp;
	t_stack	*tmp2;

	div = (size - 1) / 4;
	tmp_max = args[div];
	while (size >= div)
	{
		while ((*stack_a))
		{
			if ((*stack_a)->num <= tmp_max)
				send_to_b(stack_a, stack_b, size, tmp_max);
			else
				(*stack_a) = (*stack_a)->next;
		}
		size = lstsize((*stack_a));
		div += div;
		tmp_max = args[div];
	}
	tmp = *stack_a;
	printf("\nstack_a ");
	while (tmp)
	{
		printf("%d ", (tmp)->num);
		(tmp) = (tmp)->next;
	}
	printf("\nstack_b ");
	tmp2 = *stack_b;
	while (tmp2)
	{
		printf("%d ", (tmp2)->num);
		(tmp2) = (tmp2)->next;
	}
}
