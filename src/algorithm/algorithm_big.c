/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_big.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:43:37 by krocha-h          #+#    #+#             */
/*   Updated: 2024/04/11 15:19:27 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	move_all_to_b(t_stack **a, int *a_len, t_stack **b, int *b_len)
{
	t_move	move;

	while (*a)
	{
		move = best_move_to_b(a, *a_len, b, *b_len);
		if (!execute_steps(move.steps, a, b))
			return (0);
		(*a_len)--;
		(*b_len)++;
	}
	return (1);
}

int	move_max_in_b_to_head(t_stack **a, t_stack **b, int b_len)
{
	int		b_idx;
	t_step	step;

	b_idx = find_max_index(*b);
	if (b_idx < b_len - b_idx)
	{
		step.type = RB;
		step.times = b_idx;
	}
	else
	{
		step.type = RRB;
		step.times = b_len - b_idx;
	}
	while (step.times)
	{
		if (!execute_step(step, a, b))
			return (0);
		step.times--;
	}
	return (1);
}

void	define_sort_small(t_stack **a, t_stack **b)
{
	int	a_len;

	a_len = lstsize(*a);
	if (a_len == 5)
		sort_five(a, b);
	else if (a_len == 4)
		sort_four(a, b);
	else if (a_len == 3)
		sort_three(a);
	else if (a_len == 2)
		sort_two(a);
}

int	sort(t_stack **a)
{
	t_stack	*b;
	int		a_len;
	int		b_len;
	int		ok;

	b = NULL;
	ok = 1;
	a_len = lstsize(*a);
	b_len = lstsize(b);
	if (a_len <= 5)
		define_sort_small(a, &b);
	else
	{
		ok = move_all_to_b(a, &a_len, &b, &b_len);
		if (ok)
			ok = move_max_in_b_to_head(a, &b, b_len);
		while (ok && b)
			ok = pa(a, &b);
		if (!ok)
			stack_free(b);
	}
	return (ok);
}
