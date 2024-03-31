/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:59:15 by krocha-h          #+#    #+#             */
/*   Updated: 2024/03/27 16:44:22 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	// t_stack	*tmp;
	t_data	*current;
	char	**array;

	stack_a = NULL;
	stack_b = NULL;
	array = NULL;
	current = ft_calloc(sizeof(t_data), 1);
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
	current->size = stack_create(array, &stack_a);
	// tmp = stack_a;
	// while (tmp)
	// {
	// 	printf("%d ", tmp->num);
	// 	tmp = tmp->next;
	// }
	def_sort(&stack_a, &stack_b, array, current);
	free_array(array);
	// printf("\n");
	// tmp = stack_a;
	// while (tmp)
	// {
	// 	printf("%d ", tmp->num);
	// 	tmp = tmp->next;
	// }
	// printf("\n");
	lstclear(&stack_a, free);
	return (0);
}
