/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:39:58 by krocha-h          #+#    #+#             */
/*   Updated: 2024/03/27 14:14:01 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_ordered(const char **argv, int argc)
{
	int	i;

	i = 1;
	while ((i + 1) < argc)
	{
		if (ft_atoi(argv[i + 1]) < ft_atoi(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

void	is_double_or_over_limit(const char **argv, int argc)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		if (ft_atol(argv[i]) > INT_MAX || ft_atol(argv[i]) < INT_MIN)
			ft_error("Error\n");
		j = 1;
		while (j < i)
		{
			if (ft_atol(argv[j]) == ft_atol(argv[i]))
				ft_error("Error\n");
			j++;
		}
		i++;
	}
}

int	is_only_space(const char *str)
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

int	validate_args(const char **argv, int argc)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		if (is_only_space(argv[i]))
			return (0);
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][0] == '\0')
				return (0);
			if ((argv[i][0] == '-' || argv[i][0] == '+')
				&& ft_isdigit(argv[i][1]))
				j++;
			else if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	is_double_or_over_limit(argv, argc);
	return (1);
}
