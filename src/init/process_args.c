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

char	**args_string(char **argv)
{
	char	**array;

	array = NULL;
	array = ft_split((const char *)argv[1], ' ');
	if (!array || array[0] == NULL)
	{
		free_array(array);
		return (ft_error("Error\n"), NULL);
	}
	if (!validate_args(array))
	{
		free_array(array);
		return (ft_error("Error\n"), NULL);
	}
	return (array);
}

char	**args_individuals(char **argv)
{
	char	**array;

	array = NULL;
	if (!validate_args(argv + 1))
		return (ft_error("Error\n"), NULL);
	array = copy_argv(argv + 1);
	if (!array || !array[0])
		free(array);
	return (array);
}
