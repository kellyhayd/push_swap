/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:04:23 by krocha-h          #+#    #+#             */
/*   Updated: 2024/03/25 17:14:03 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void push(t_stack **dst, t_stack **src)
{
	t_stack *tmp;

	if (!*src)
		return;
	tmp = (*src)->next;
	(*src)->next = *dst;
	*dst = *src;
	(*src) = tmp;
}

int pa(t_stack **a, t_stack **b)
{
	if (!ft_write(1, "pa\n", 3))
		return (0);
	push(a, b);
	return (1);
}

int pb(t_stack **a, t_stack **b)
{
	if (!ft_write(1, "pb\n", 3))
		return (0);
	push(b, a);
	return (1);
}