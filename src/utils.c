/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:44:26 by krocha-h          #+#    #+#             */
/*   Updated: 2024/03/22 13:39:00 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**copy_argv(char **argv)
{
	char	**array;
	int		i;
	int		j;

	i = 0;
	while (argv[i])
		i++;
	array = ft_calloc(i + 1, sizeof(char *));
	i = 0;
	while (argv[i])
	{
		array[i] = ft_calloc(ft_strlen(argv[i] + 1), 1);
		if (!array[i])
		{
			j = -1;
			while (++j < i)
				free(array[j]);
			free(array);
			return (NULL);
		}
		ft_strcpy(array[i], argv[i]);
		i++;
	}
	array[i] = NULL;
	return (array);
}
