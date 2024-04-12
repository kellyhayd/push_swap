/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 10:51:32 by krocha-h          #+#    #+#             */
/*   Updated: 2024/04/12 16:46:06 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse(t_stack **stack, int argc, const char **argv)
{
	int	i;
	int	ok;
	int	num;

	i = 1;
	ok = 1;
	while (ok && i < argc)
	{
		if (ft_strncmp(argv[i], "", 1) == 0)
			return (0);
		num = ft_atoi(argv[i]);
		ok = stack_addlast(stack, num);
		i++;
	}
	if (!ok && *stack)
		stack_free(*stack);
	return (ok);
}
