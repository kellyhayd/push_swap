/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:57:00 by krocha-h          #+#    #+#             */
/*   Updated: 2024/04/11 15:25:25 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	new_atoi(int *result, const char *str)
{
	int	sign;
	int	tmp;

	if (!str || !str[0])
		return (0);
	sign = 1;
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[0] == '-')
			sign = -1;
		str++;
	}
	*result = 0;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		tmp = (*result) * 10 + *str - '0';
		if (tmp < (*result))
			return (0);
		(*result) = tmp;
		str++;
	}
	*result *= sign;
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
