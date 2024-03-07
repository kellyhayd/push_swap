/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:39:58 by krocha-h          #+#    #+#             */
/*   Updated: 2024/03/06 16:24:29 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "push_swap.h"

#include <stdlib.h>
#include <stdio.h>

int	is_double(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (j < i)
		{
			if (ft_atoi(argv[j]) == ft_atoi(argv[i]))
				return (ft_error("Error\n"), 0);
			j++;
		}
		i++;
	}
	return (1);
}

int	validate_args(char **argv, int argc)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (j < argc)
		{
			if (argv[i][0] ==  '\0' || argv[i] == " ")
				return (ft_error("Error\n"), 0);
			if (argv[i][0] == '-')
				j++;
			if (!ft_isdigit(argv[i][j]) && !ft_isspace(argv[i][j]))
				return (ft_error("Error\n"), 0);
			j++;
		}
		i++;
	}
	if (!is_double(argv))
		return (ft_error("Error\n"), 0);
	return (1);
}
