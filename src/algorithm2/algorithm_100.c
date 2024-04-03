/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_100.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:13:51 by krocha-h          #+#    #+#             */
/*   Updated: 2024/04/03 15:25:36 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int		define_direction(t_stack **stack, t_data *data, int	idx)
{
	int	size;
	int	middle;
	int	direction;

	size = lstsize(stack);
	middle = size / 2;
	if (idx <= middle)
		direction = 1;
	if (idx > middle)
		direction = 2;
}

void	define_position(t_stack **stack_a, t_stack **stack_b, t_data *data)
{
	t_stack	*tmp;
	int		cost;
	int		imediate;
	int		idx;
	int		size_b;

	size_b = lstsize(*stack_b);
	tmp = *stack_b;
	if (tmp->num > data->num_now)
	{
		cost = 0;
		while (tmp->num > data->num_now && tmp->idx <= (size_b / 2))
			tmp = tmp->next;
		cost = tmp->idx;
		imediate = tmp->num;
		idx = tmp->idx;
	}
	tmp = *stack_b;
	if (tmp->num < data->num_now)
	{
		while (tmp->num < data->num_now)
			tmp = tmp->next;
		cost = size_b - tmp->idx;
		imediate = tmp->num;
		idx = tmp->idx;
	}

}

int	send_to_b(t_stack **stack_a, t_stack **stack_b, t_data *data, int direction)
{
	int	count;

	count = 0;
	while ((*stack_a)->num != data->num_now)
	{
		if (direction == 1)
			ra(stack_a);
		else if (direction == 2)
			rra(stack_a);
	}
	pb(stack_a, stack_b);
	count++;
	data->size_now = lstsize(*stack_a);
	return (count);
}

void	calc_moves(t_stack **stack_a, t_stack **stack_b, t_data *data)
{
	int		parcel;
	int		count;
	int		cost_up;
	int		cost_down;
	int		tmp_up;
	int		tmp_down;
	int		direction;
	t_stack	*tmp;

	data->div = data->size_now / data->def_algo;
	data->size_init = data->size_now;
	parcel = data->div;
	while (*stack_a)
	{
		data->num_max = data->args[parcel - 1];
		tmp = *stack_a;
		count = 0;
		while (count < data->div)
		{
			cost_up = -1;
			cost_down = -1;
			tmp = *stack_a;
			while (tmp->idx < (data->size_now / 2) && tmp->num > data->num_max)
				tmp = tmp->next;
			if (tmp->num <= data->num_max)
			{
				cost_up = tmp->idx;
				tmp_up = tmp->num;
			}
			while (tmp->next)
				tmp = tmp->next;
			while (tmp->idx > (data->size_now / 2) && tmp->num > data->num_max)
				tmp = tmp->prev;
			if (tmp->num <= data->num_max)
			{
				cost_down = data->size_now - tmp->idx;
				tmp_down = tmp->num;
			}
			if (cost_up <= cost_down || cost_down == -1)
			{
				direction = 1;
				data->num_now = tmp_up;
				count += send_to_b(stack_a, stack_b, data, direction);
			}
			else if (cost_down < cost_up || cost_up == -1)
			{
				direction = 2;
				data->num_now = tmp_down;
				count += send_to_b(stack_a, stack_b, data, direction);
			}
		}
		parcel += data->div;
		if (parcel > data->size_init)
			parcel = data->size_now;
	}
}

void	sort_hundred(t_stack **stack_a, t_stack **stack_b, t_data *data)
{
	calc_moves(stack_a, stack_b, data);
	// sort_ten(stack_a, stack_b, data);
	push_back(stack_a, stack_b, data);
}
