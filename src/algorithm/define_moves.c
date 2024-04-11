/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:59:23 by krocha-h          #+#    #+#             */
/*   Updated: 2024/04/11 15:17:43 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	steps_cost(const t_step *steps)
{
	int	i;
	int	cost;

	cost = 0;
	i = 0;
	while (steps[i].type != NO_ACTION)
	{
		cost += steps[i].times;
		i++;
	}
	return (cost);
}

t_move	move_rr_pb(int a_times, int b_times)
{
	t_move	move;

	move.steps[0].type = RR;
	move.steps[0].times = ft_min_int(a_times, b_times);
	move.steps[1].type = RA;
	move.steps[1].times = a_times - ft_min_int(a_times, b_times);
	move.steps[2].type = RB;
	move.steps[2].times = b_times - ft_min_int(a_times, b_times);
	move.steps[3].type = PB;
	move.steps[3].times = 1;
	move.steps[4].type = NO_ACTION;
	move.steps[4].times = 0;
	move.cost = steps_cost(move.steps);
	return (move);
}

t_move	move_rrr_pb(int a_times, int b_times)
{
	t_move	move;

	move.steps[0].type = RRR;
	move.steps[0].times = ft_min_int(a_times, b_times);
	move.steps[1].type = RRA;
	move.steps[1].times = a_times - ft_min_int(a_times, b_times);
	move.steps[2].type = RRB;
	move.steps[2].times = b_times - ft_min_int(a_times, b_times);
	move.steps[3].type = PB;
	move.steps[3].times = 1;
	move.steps[4].type = NO_ACTION;
	move.steps[4].times = 0;
	move.cost = steps_cost(move.steps);
	return (move);
}

t_move	move_ra_rrb_pb(int a_times, int b_times)
{
	t_move	move;

	move.steps[0].type = RA;
	move.steps[0].times = a_times;
	move.steps[1].type = RRB;
	move.steps[1].times = b_times;
	move.steps[2].type = PB;
	move.steps[2].times = 1;
	move.steps[3].type = NO_ACTION;
	move.steps[3].times = 0;
	move.cost = steps_cost(move.steps);
	return (move);
}

t_move	move_rra_rb_pb(int a_times, int b_times)
{
	t_move	move;

	move.steps[0].type = RRA;
	move.steps[0].times = a_times;
	move.steps[1].type = RB;
	move.steps[1].times = b_times;
	move.steps[2].type = PB;
	move.steps[2].times = 1;
	move.steps[3].type = NO_ACTION;
	move.steps[3].times = 0;
	move.cost = steps_cost(move.steps);
	return (move);
}
