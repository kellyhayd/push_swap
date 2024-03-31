/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:44:26 by krocha-h          #+#    #+#             */
/*   Updated: 2024/03/27 10:49:40 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_stack **stack)
{
	int		min;
	t_stack	*tmp;

	tmp = (*stack);
	min = (*stack)->num;
	while (tmp && tmp->next)
	{
		tmp = tmp->next;
		if (min > tmp->num)
			min = tmp->num;
	}
	return (min);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char	**copy_argv(char **argv)
{
	char	**array;
	int		i;

	i = 0;
	while (argv[i])
		i++;
	array = ft_calloc(i + 1, sizeof(char *));
	if (!array)
		return (NULL);
	i = 0;
	while (argv[i])
	{
		array[i] = ft_calloc(ft_strlen(argv[i]) + 1, 1);
		if (!array[i])
			return (free_array(array), NULL);
		ft_strcpy(array[i], argv[i]);
		i++;
	}
	array[i] = NULL;
	return (array);
}
