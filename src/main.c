/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:59:15 by krocha-h          #+#    #+#             */
/*   Updated: 2024/03/14 14:42:42 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**copy_argv(char **argv)
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

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_data	*lst;
	char	**array;

	stack_a = NULL;
	array = NULL;
	lst = ft_calloc (sizeof(t_data), 1);
	if (argc <= 1)
		return (ft_error("Error\n"), 1);
	else if (argc > 2)
	{
		if (!validate_args(argv + 1))
			return (ft_error("Error\n"), 1);
		array = copy_argv(argv + 1);
	}
	else if (argc == 2)
	{
		array = ft_split((const char *)argv[1], ' ');
		if (!array || array[0] == NULL)
			return (ft_error("Error\n"), EXIT_FAILURE);
		if (!validate_args(array))
			return (ft_error("Error\n"), 1);
	}
	if (is_ordered(array))
		return (1);
	stack_create((const char **)array, &stack_a, lst);
	rotate(&stack_a, lst);
	return (0);
}
