/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_100.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:13:51 by krocha-h          #+#    #+#             */
/*   Updated: 2024/04/01 11:03:05 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_back(t_stack **stack_a, t_stack **stack_b, t_data *info)
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
		while (node_max->num != info->args[size_b - 1])
			node_max = node_max->next;
		if (node_max->idx >= middle)
			direction = 1;
		else
			direction = 2;
		while ((*stack_b)->num != info->args[size_b - 1])
		{
			if ((*stack_b)->next
				&& (*stack_b)->next->num == info->args[size_b - 1])
				sb(stack_b);
			else if (direction == 1)
				rrb(stack_b);
			else if (direction == 2)
				rb(stack_b);
		}
		pa(stack_a, stack_b);
		size_b--;
	}
}

int	send_to_b(t_stack **stack_a, t_stack **stack_b, t_data *info)
{
	int	middle;
	int	direction;
	int	count;

	count = 0;
	middle = (info->size_now - 1) / 2;
	if (info->idx_now >= middle)
		direction = 1;
	else
		direction = 2;
	while ((*stack_a)->num != info->num_now)
	{
		if ((*stack_a)->num < info->num_max)
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
	info->size_now = lstsize(*stack_a);
	return (++count);
}

void	sort_hundred(t_stack **stack_a, t_stack **stack_b, t_data *info)
{
	int		div;
	int		parcel;
	int		count;
	t_stack	*tmp;

	div = info->size_now / 5;
	parcel = div;
	while (parcel < (div * 5))
	{
		info->num_max = info->args[parcel];
		tmp = *stack_a;
		count = 0;
		while (count < div)
		{
			if (tmp->num < info->num_max)
			{
				info->idx_now = tmp->idx;
				info->num_now = tmp->num;
				count += send_to_b(stack_a, stack_b, info);
				tmp = *stack_a;
			}
			else
				tmp = tmp->next;
		}
		parcel += div;
	}
	info->size_now = lstsize(*stack_a);
	sort_ten(stack_a, stack_b, info);
	push_back(stack_a, stack_b, info);
}
