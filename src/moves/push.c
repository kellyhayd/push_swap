/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:04:23 by krocha-h          #+#    #+#             */
/*   Updated: 2024/04/12 10:24:38 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **dst, t_stack **src)
{
	t_stack	*tmp;

	if (!*src)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dst;
	*dst = *src;
	(*src) = tmp;
}

int	pa(t_stack **a, t_stack **b)
{
	if (!ft_putstr("pa\n"))
		return (0);
	push(a, b);
	return (1);
}

int	pb(t_stack **a, t_stack **b)
{
	if (!ft_putstr("pb\n"))
		return (0);
	push(b, a);
	return (1);
}
