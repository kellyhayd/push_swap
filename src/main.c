/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:59:15 by krocha-h          #+#    #+#             */
/*   Updated: 2024/03/22 15:22:51 by krocha-h         ###   ########.fr       */
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
		return (ft_error("Error\n"), 1);
	else if (argc > 2)
	{
		if (!validate_args(argv + 1))
			return (ft_error("Error\n"), 1);
		array = copy_argv(argv + 1);
		if (!array || !array[0])
			free(array);
	}
	else if (argc == 2)
	{
		array = ft_split((const char *)argv[1], ' ');
		if (!array || array[0] == NULL)
		{
			free_array(array);
			return (ft_error("Error\n"), EXIT_FAILURE);
		}
		if (!validate_args(array))
		{
			free_array(array);
			return (ft_error("Error\n"), 1);
		}
	}
	if (is_ordered(array))
		return (1);
	stack_create((const char **)array, &stack_a);
	free_array(array);
	// rotate(&stack_a);
	return (0);
}
