/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:59:15 by krocha-h          #+#    #+#             */
/*   Updated: 2024/03/14 12:30:45 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	char	**array;

	stack_a = NULL;
	array = NULL;
	if (argc <= 1)
		exit(EXIT_FAILURE);
	else if (argc > 2)
	{
		if (!validate_args(argv + 1))
			exit(EXIT_FAILURE);
	}
	else if (argc == 2)
	{
		array = ft_split(argv[1], ' ');
		if (!validate_args(array))
			exit(EXIT_FAILURE);
	}
	stack_create((const char **)argv + 1, &stack_a);
	return (0);
}
