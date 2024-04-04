/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_100.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:13:51 by krocha-h          #+#    #+#             */
/*   Updated: 2024/04/03 15:53:58 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_top(t_stack **stack_b, t_data *data, int size)
{
	while ((*stack_b)->num != data->args[size - 1])
	{
		if ((*stack_b)->next
			&& (*stack_b)->next->num == data->args[size - 1])
			sb(stack_b);
		else if (data->direction == 1)
			rrb(stack_b);
		else if (data->direction == 2)
			rb(stack_b);
	}
}

void	push_back(t_stack **stack_a, t_stack **stack_b, t_data *data)
{
	int		middle;
	int		size_b;
	t_stack	*node_max;

	size_b = lstsize(*stack_b);
	while (*stack_b)
	{
		middle = size_b / 2;
		node_max = *stack_b;
		while (node_max->num != data->args[size_b - 1])
			node_max = node_max->next;
		if (node_max->idx >= middle)
			data->direction = 1;
		else
			data->direction = 2;
		move_to_top(stack_b, data, size_b);
		pa(stack_a, stack_b);
		size_b--;
	}
}

void	define_direction(int cost_top, int cost_tail, t_data *data)
{
	data->direction = -1;
	if ((cost_top <= cost_tail && cost_top != -1 ) || cost_tail == -1)
		data->direction = 1;
	else if ((cost_tail < cost_top && cost_tail != -1) || cost_top == -1)
		data->direction = 2;
}

void	calculate_dir(t_stack *stack, int size, int num, t_data *data)
{
	int	cost_top;
	int	cost_tail;

	cost_top = -1;
	cost_tail = -1;
	while (stack->idx <= (size / 2) && stack->num > num)
		stack = stack->next;
	if (stack->num <= num)
	{
		cost_top = stack->idx;
		data->tmp_top = stack->num;
	}
	while (stack->next)
		stack = stack->next;
	while (stack->idx > (size / 2) && stack->num > num)
		stack = stack->prev;
	if (stack->num <= num)
	{
		cost_tail = size - stack->idx;
		data->tmp_tail = stack->num;
	}
	define_direction(cost_top, cost_tail, data);
}

int	send_to_b(t_stack **stack_a, t_stack **stack_b, t_data *data)
{
	int	count;

	count = 0;
	while ((*stack_a)->num != data->num_now)
	{
		if (data->direction == 1)
			ra(stack_a);
		else if (data->direction == 2)
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
	t_stack	*tmp;

	data->div = data->size_now / data->def_algo;
	data->size_init = data->size_now;
	parcel = data->div;
	while (*stack_a)
	{
		data->num_max = data->args[parcel - 1];
		count = 0;
		while (*stack_a && count < data->div)
		{
			tmp = *stack_a;
			calculate_dir(tmp, data->size_now, data->num_max, data);
			if (data->direction == 1)
				data->num_now = data->tmp_top;
			else if (data->direction == 2)
				data->num_now = data->tmp_tail;
			count += send_to_b(stack_a, stack_b, data);
		}
		parcel += data->div;
		if (parcel > data->size_init)
			parcel = data->size_init;
	}
}

void	sort_hundred(t_stack **stack_a, t_stack **stack_b, t_data *data)
{
	calc_moves(stack_a, stack_b, data);
	push_back(stack_a, stack_b, data);
}
