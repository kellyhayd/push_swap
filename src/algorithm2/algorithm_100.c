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

void	back_to_top(t_stack **stack)
{
	while ((*stack)->prev)
		*stack = (*stack)->prev;
}

int	position_to(t_stack *stack_b, t_stack *stack_a, t_data *data)
{
	data->bsize_now = lstsize(stack_b);
	if (stack_b->next)
	{
		if (stack_b->num > data->num_now)
		{
			while (stack_b->next && stack_b->num > data->num_now)
				(stack_b) = stack_b->next;
			stack_b->cost = stack_b->idx;
		}
		else if (stack_b->num < data->num_now)
		{
			while (stack_b->next && stack_b->num < data->num_now)
				(stack_b) = stack_b->next;
			stack_b->cost = stack_b->idx;
		}
	}
	if (stack_b->idx > (data->bsize_now / 2))
	{
		stack_b->cost = data->bsize_now - stack_b->idx;
		stack_b->direction = 2;
	}
	else
		stack_b->direction = 1;
	stack_a->immediate_b = stack_b;
	return (stack_b->cost);
}

// void	position_b(t_stack **stack_b, t_data *data)
// {
// 	t_stack	*tmp;
// 
// 	position_to(stack_b, data);
// 	tmp = *stack_b;
// 	while (tmp->num != data->immediate)
// 		tmp = tmp->next;
// 	while ((*stack_b)->num != data->immediate)
// 	{
// 		if (ft_strncmp(tmp->move, "rb", 2))
// 			rb(stack_b);
// 		else if (ft_strncmp(tmp->move, "rrb", 3))
// 			rrb(stack_b);
// 	}
// }

// int	send_to_b(t_stack **stack_a, t_stack **stack_b, t_data *data)
// {
// 	int	count;
// 
// 	count = 0;
// 	while ((*stack_a)->num != data->num_now)
// 	{
// 		if (data->direction == 1)
// 			ra(stack_a);
// 		else if (data->direction == 2)
// 			rra(stack_a);
// 	}
// 	if (*stack_b)
// 		position_b(stack_b, data);
// 	pb(stack_a, stack_b);
// 	count++;
// 	data->asize_now = lstsize(*stack_a);
// 	return (count);
// }

// void	define_direction(int cost_top, int cost_tail, t_data *data)
// {
// 	data->direction = -1;
// 	if ((cost_top <= cost_tail && cost_top != -1 ) || cost_tail == -1)
// 		data->direction = 1;
// 	else if ((cost_tail < cost_top && cost_tail != -1) || cost_top == -1)
// 		data->direction = 2;
// }

void	move_individually(t_stack **stack_a, t_stack **stack_b, t_stack *to_move)
{
	while ((*stack_a)->num != to_move->num)
	{
		if ((*stack_a)->direction == 1)
			ra(stack_a);
		if ((*stack_a)->direction == 2)
			rra(stack_a);
	}
	while ((*stack_b)->num != to_move->immediate_b->num)
	{
		if (to_move->immediate_b->direction == 1)
			rb(stack_b);
		if (to_move->immediate_b->direction == 2)
			rrb(stack_b);
	}
	pb(stack_a, stack_b);
}

void	final_move(t_stack **stack, char pile, int times, int move)
{
	while (times > 0)
	{
		if (move == 1)
		{
			if (pile == 'a')
				ra(stack);
			else if (pile == 'b')
				rb(stack);
		}
		else if (move == 2)
		{
			if (pile == 'a')
				ra(stack);
			else if (pile == 'b')
				rb(stack);
		}	
		times--;
	}
}

void	dual_move(t_stack **stack_a, t_stack **stack_b, int times, int move)
{
	while (times > 0)
	{
		if (move == 1)
			rr(stack_a, stack_b);
		else if (move == 2)
			rrr(stack_a, stack_b);
		times--;
	}
}

int	calc_cost_b(t_stack *stack_a, t_stack *stack_b, t_data *data)
{
	int	cost;

	data->num_now = stack_a->num;
	cost = position_to(stack_b, stack_a, data);
	return (cost);
}

void	calculate_cost(t_stack *stack_a, t_stack *stack_b, t_data *data)
{
	while (stack_a)
	{
		while (stack_a->idx <= (data->asize_now / 2))
		{
			stack_a->cost = stack_a->idx + calc_cost_b(stack_a, stack_b, data);
			stack_a->direction = 1;
			stack_a = stack_a->next;
		}
		stack_a->cost = data->asize_now - stack_a->idx + calc_cost_b(stack_a, stack_b, data);
		stack_a->direction = 2;
		stack_a = stack_a->next;
	}
}

void	send_to_b(t_stack **stack_a, t_stack **stack_b, t_data *data)
{
	int	min_cost;
	t_stack	*tmp;
	t_stack	*to_move;

	min_cost = 0;
	while (*stack_a)
	{
		calculate_cost(*stack_a, *stack_b, data);
		tmp = *stack_a;
		to_move = *stack_a;
		min_cost = tmp->cost;
		while (tmp)
		{
			if (tmp->cost < min_cost)
			{
				min_cost = tmp->cost;
				to_move = tmp;
			}
			tmp = tmp->next;
		}
		if (to_move->direction == 1 && to_move->immediate_b->direction == 1)
		{
			if (to_move->cost > to_move->immediate_b->cost)
			{
				dual_move(stack_a, stack_b, to_move->immediate_b->cost, 1);
				final_move(stack_a, 'a', to_move->cost, 1);
				pb(stack_a, stack_b);
			}
			else if (to_move->immediate_b->cost > to_move->cost)
			{
				dual_move(stack_a, stack_b, to_move->cost, 1);
				final_move(stack_b, 'b', to_move->immediate_b->cost, 1);
				pb(stack_a, stack_b);
			}
		}
		else if (to_move->direction == 2 && to_move->immediate_b->direction == 2)
		{
			if (to_move->cost > to_move->immediate_b->cost)
			{
				dual_move(stack_a, stack_b, to_move->immediate_b->cost, 2);
				final_move(stack_a, 'a', to_move->cost, 2);
				pb(stack_a, stack_b);
			}
			else if (to_move->immediate_b->cost > to_move->cost)
			{
				dual_move(stack_a, stack_b, to_move->cost, 2);
				final_move(stack_b, 'b', to_move->immediate_b->cost, 2);
				pb(stack_a, stack_b);
			}
		}
		else
			move_individually(stack_a, stack_b, to_move);
	}
}

// void	calc_moves(t_stack **stack_a, t_stack **stack_b, t_data *data)
// {
// 	int		parcel;
// 	int		count;
// 	t_stack	*tmp;
// 
// 	data->div = data->asize_now / data->def_div;
// 	data->size_init = data->asize_now;
// 	parcel = data->div;
// 	while (*stack_a)
// 	{
// 		data->num_max = data->args[parcel - 1];
// 		count = 0;
// 		while (*stack_a && count < data->div)
// 		{
// 			tmp = *stack_a;
// 			calculate_dir(tmp, data->asize_now, data->num_max, data);
// 			if (data->direction == 1)
// 				data->num_now = data->tmp_top;
// 			else if (data->direction == 2)
// 				data->num_now = data->tmp_tail;
// 			count += send_to_b(stack_a, stack_b, data);
// 		}
// 		parcel += data->div;
// 		if (parcel > data->size_init)
// 			parcel = data->size_init;
// 	}
// }

void	send_three(t_stack **stack_a, t_stack **stack_b)
{
	int	three;

	three = 3;
	while (three > 0)
	{
		pb(stack_a, stack_b);
		three--;
	}
	sort_three_reverse(stack_b);
}

void	sort_hundred(t_stack **stack_a, t_stack **stack_b, t_data *data)
{
	send_three(stack_a, stack_b);
	send_to_b(stack_a, stack_b, data);
	push_back(stack_a, stack_b, data);
}
