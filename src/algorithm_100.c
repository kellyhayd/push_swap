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

void	push_back(t_stack **stack_a, t_stack **stack_b, t_data *current)
{
	int		middle;
	int		size_b;
	int		direction;
	t_stack	*node_max;

	size_b = lstsize(*stack_b);
	while (*stack_b)
	{
		middle = size_b / 2;
		node_max = *stack_b;
		while (node_max->num != current->args[size_b - 1])
			node_max = node_max->next;
		if (node_max->idx >= middle)
			direction = 1;
		else
			direction = 2;
		while ((*stack_b)->num != current->args[size_b - 1])
		{
			if (direction == 1)
				rrb(stack_b);
			else if (direction == 2)
				rb(stack_b);
		}
		pa(stack_a, stack_b);
		size_b--;
	}
}

int	send_to_b(t_stack **stack_a, t_stack **stack_b, t_data *current)
{
	int	middle;
	int	direction;
	int	count;

	count = 0;
	middle = (current->size - 1) / 2;
	if (current->idx >= middle)
		direction = 1;
	else
		direction = 2;
	while ((*stack_a)->num != current->num_cur)
	{
		if ((*stack_a)->num < current->num_max)
		{
			pb(stack_a, stack_b);
			count++;
		}
		else if (direction == 1)
			rra(stack_a);
		else if (direction == 2)
			ra(stack_a);
	}
	pb(stack_a, stack_b);
	current->size = lstsize(*stack_a);
	return (++count);
}

void	sort_hundred(t_stack **stack_a, t_stack **stack_b, t_data *cur)
{
	int	div;
	int	parcel;
	int	count;
	t_stack	*tmp;

	div = cur->size / 4;
	parcel = div;
	while (parcel < (div * 4))
	{
		cur->num_max = cur->args[parcel];
		tmp = *stack_a;
		count = 0;
		while (count < div)
		{
			if (tmp->num < cur->num_max)
			{
				cur->idx = tmp->idx;
				cur->num_cur = tmp->num;
				count += send_to_b(stack_a, stack_b, cur);
				tmp = *stack_a;
			}
			else
				tmp = tmp->next;
		}
		parcel += div;
	}
	cur->size = lstsize(*stack_a);
	sort_ten(stack_a, stack_b, cur);
	push_back(stack_a, stack_b, cur);
}
