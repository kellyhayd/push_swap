/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:31:58 by krocha-h          #+#    #+#             */
/*   Updated: 2024/04/11 15:22:22 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_move	move_min(t_move move1, t_move move2)
{
	if (move1.cost < move2.cost)
		return (move1);
	return (move2);
}

t_move	best_move_to_b(t_stack **a, int a_len, t_stack **b, int b_len)
{
	t_stack	*it;
	t_move	best;
	t_move	move;
	int		a_idx;
	int		b_idx;

	it = *a;
	a_idx = 0;
	while (it)
	{
		b_idx = find_greatest_lower_than_index(*b, it->value);
		if (b_idx == -1)
			b_idx = find_max_index(*b);
		move = move_rr_pb(a_idx, b_idx);
		move = move_min(move, move_rrr_pb(a_len - a_idx, b_len - b_idx));
		move = move_min(move, move_ra_rrb_pb(a_idx, b_len - b_idx));
		move = move_min(move, move_rra_rb_pb(a_len - a_idx, b_idx));
		if (a_idx == 0)
			best = move;
		else
			best = move_min(best, move);
		a_idx++;
		it = it->next;
	}
	return (best);
}

int	execute_step(t_step step, t_stack **a, t_stack **b)
{
	if (step.type == RA)
		return (ra(a));
	else if (step.type == RR)
		return (rr(a, b));
	else if (step.type == RB)
		return (rb(b));
	else if (step.type == RRA)
		return (rra(a));
	else if (step.type == RRR)
		return (rrr(a, b));
	else if (step.type == RRB)
		return (rrb(b));
	else if (step.type == PB)
		return (pb(a, b));
	return (1);
}

int	execute_steps(const t_step *steps, t_stack **a, t_stack **b)
{
	int	i;
	int	k;

	i = 0;
	while (steps[i].type != NO_ACTION)
	{
		k = 0;
		while (k < steps[i].times)
		{
			if (!execute_step(steps[i], a, b))
				return (0);
			k++;
		}
		i++;
	}
	return (1);
}
