/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:59:15 by krocha-h          #+#    #+#             */
/*   Updated: 2024/04/01 15:06:17 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, const char **argv)
{
	t_stack *stack;

	stack = NULL;
	if (argc < 2)
		return (0);
	if (!validate_args(argv, argc))
		ft_error("Error\n");
	if (is_ordered(argv, argc))
		return (0);
	if (!parse(&stack, argc, argv))
		return (1);
	if (!sort(&stack))
	{
		stack_free(stack);
		return (1);
	}
	stack_free(stack);
	return (0);
}
