/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 10:51:32 by krocha-h          #+#    #+#             */
/*   Updated: 2024/04/01 10:56:40 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int parse(t_stack **stack, int argc, const char **argv)
{
	int i;
	int ok;
	int	num;

	i = 1;
	ok = 1;
	while (ok && i < argc)
	{
		num = ft_atoi(argv[i]);
		ok = stack_addlast(stack, num);
		i++;
	}
	if (!ok && *stack)
		stack_free(*stack);
	return (ok);
}
