/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:39:58 by krocha-h          #+#    #+#             */
/*   Updated: 2024/03/13 17:12:26 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdlib.h>
#include <stdio.h>

int	is_double(char **argv)
{
	int	i;
	int	j;

	i = 0;
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

int	is_only_space(char *str)
{
	int	i;
	int	ok;

	ok = 0;
	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			ok = 1;
		if (str[i + 1] == '\0' && ok == 0)
			return (1);
		i++;
	}
	return (0);
}

int	validate_args(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		if (is_only_space(argv[i]))
			return (printf("only space\n"), ft_error("Error\n"), 0);
		j = 0;
		while (argv[i][j] && ft_strlen(argv[i]) > 1)
		{
			if (argv[i][0] == '\0')
				return (ft_error("Error\n"), 0);
			if ((argv[i][0] == '-' || argv[i][0] == '+')
				&& ft_isdigit(argv[i][1]))
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
