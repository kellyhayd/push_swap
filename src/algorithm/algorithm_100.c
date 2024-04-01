/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_100.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:13:51 by krocha-h          #+#    #+#             */
/*   Updated: 2024/04/01 13:08:52 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_top(t_stack **stack_b, t_data *data, int dir, int size)
{
	while ((*stack_b)->num != data->args[size - 1])
	{
		if ((*stack_b)->next
			&& (*stack_b)->next->num == data->args[size - 1])
			sb(stack_b);
		else if (dir == 1)
			rrb(stack_b);
		else if (dir == 2)
			rb(stack_b);
	}
}

void	push_back(t_stack **stack_a, t_stack **stack_b, t_data *data)
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
		while (node_max->num != data->args[size_b - 1])
			node_max = node_max->next;
		if (node_max->idx >= middle)
			direction = 1;
		else
			direction = 2;
		move_to_top(stack_b, data, direction, size_b);
		pa(stack_a, stack_b);
		size_b--;
	}
}

int	send_to_b(t_stack **stack_a, t_stack **stack_b, t_data *data)
{
	int	middle;
	int	direction;
	int	count;

	count = 0;
	middle = (data->size_now - 1) / 2;
	if (data->idx_now >= middle)
		direction = 1;
	else
		direction = 2;
	while ((*stack_a)->num != data->num_now)
	{
		if ((*stack_a)->num < data->num_max)
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
	data->size_now = lstsize(*stack_a);
	return (++count);
}

void	move_hundred(t_stack **stack_a, t_stack **stack_b, t_data *data)
{
	int		parcel;
	int		count;
	t_stack	*tmp;

	data->div = data->size_now / data->def_algo;
	parcel = data->div;
	while (parcel < (data->div * data->def_algo))
	{
		data->num_max = data->args[parcel];
		tmp = *stack_a;
		count = 0;
		while (count < data->div)
		{
			if (tmp->num < data->num_max)
			{
				data->idx_now = tmp->idx;
				data->num_now = tmp->num;
				count += send_to_b(stack_a, stack_b, data);
				tmp = *stack_a;
			}
			else
				tmp = tmp->next;
		}
		parcel += data->div;
	}
}

void	sort_hundred(t_stack **stack_a, t_stack **stack_b, t_data *data)
{
	move_hundred(stack_a, stack_b, data);
	data->size_now = lstsize(*stack_a);
	sort_ten(stack_a, stack_b, data);
	push_back(stack_a, stack_b, data);
}
