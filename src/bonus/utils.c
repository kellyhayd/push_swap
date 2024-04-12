/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:57:00 by krocha-h          #+#    #+#             */
/*   Updated: 2024/04/12 10:47:06 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	next_move(char *move)
{
	ssize_t	nbytes;

	move[0] = '\0';
	nbytes = read(0, move, 3);
	if (nbytes < 3)
		return (nbytes == 0);
	if (move[2] == '\n')
	{
		move[3] = '\0';
		return (1);
	}
	nbytes = read(0, &move[3], 1);
	if (nbytes < 1)
		return (0);
	move[4] = '\0';
	return (1);
}

int	is_sorted(const t_stack *stack)
{
	while (stack && stack->next && stack->value < stack->next->value)
		stack = stack->next;
	return (!stack || !stack->next);
}

int	non_duplicates(const t_stack *stack)
{
	const t_stack	*it;
	const t_stack	*jt;

	it = stack;
	while (it)
	{
		jt = stack;
		while (jt != it)
		{
			if (jt->value == it->value)
				return (0);
			jt = jt->next;
		}
		it = it->next;
	}
	return (1);
}
