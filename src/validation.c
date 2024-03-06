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

void	ft_error(char *msg)
{
	printf("%s\n", msg);
	// ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}

void	is_empty(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] == " " || argv[i][0] == '\0')
			ft_error("Error\n");
		i++;
	}
}

void	is_double(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i] != 0)
	{
		j = 0;
		while (j < i)
		{
			if (ft_atoi(argv[j]) == ft_atoi(argv[i]))
				ft_error("Error\n");
			j++;
		}
		i++;
	}
}
