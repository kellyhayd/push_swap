/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_100.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:13:51 by krocha-h          #+#    #+#             */
/*   Updated: 2024/03/27 17:54:34 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	send_to_b(t_stack **stack_a, t_stack **stack_b, t_data *current)
{
	int	proximity;
	int	direction;

	proximity = (current->size - 1) / 2;
	if (current->idx >= proximity)
		direction = 1;
	else
		direction = 2;
	while ((*stack_a)->num != current->num_cur)
	{
		if ((*stack_a)->num <= current->num_max && (*stack_a)->idx == 0)
			pb(stack_a, stack_b);
		else if (direction == 1)
			rra(stack_a);
		else if (direction == 2)
			ra(stack_a);
	}
	pb(stack_a, stack_b);
}

void	sort_hundred(t_stack **stack_a, t_stack **stack_b, t_data *current)
{
	int	div;
	int	parcel;
	t_stack	*tmp;
	t_stack	*tmp2;

	div = (current->size) / 4;
	parcel = div;
	current->num_max = current->args[div - 1];
	tmp = *stack_a;
	while (tmp)
	{
		while (current->size >= (current->size - div))
		{
			if (tmp->num <= current->num_max)
			{
				current->idx = tmp->idx;
				current->num_cur = tmp->num;
				send_to_b(stack_a, stack_b, current);
				current->size = lstsize(*stack_a);
			}
			else
				tmp = tmp->next;
		}
		parcel += div;
		current->num_max = current->args[parcel - 1];
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
