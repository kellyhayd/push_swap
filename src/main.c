/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:59:15 by krocha-h          #+#    #+#             */
/*   Updated: 2024/03/13 17:12:45 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// char	**copy_argv(char **array)
// {
// 	int		i;
// 	char	**copy;

// 	copy = NULL;
// 	i = 0;
// 	while (array[i])
// 		copy[i] = array[i];
// 	copy[i] = "\0";
// 	return (copy);
// }

int	sizeof_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (1);
}

int	main(int argc, char **argv)
{
	// t_stack	**stack_a;
	char	**array;

	// stack_a = NULL;
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
	// create_stack(argv);
	return (0);
}
