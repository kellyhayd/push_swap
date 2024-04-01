/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:59:15 by krocha-h          #+#    #+#             */
/*   Updated: 2024/04/01 10:56:47 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_data	*current;
	char	**array;

	stack_a = NULL;
	stack_b = NULL;
	array = NULL;
	current = ft_calloc(sizeof(t_data), 1);
	if (argc <= 1)
		return (ft_error("Error\n"), 0);
	else if (argc > 2)
		array = args_individuals(argv);
	else if (argc == 2)
		array = args_string(argv);
	if (is_ordered(array))
		return (0);
	current->size = stack_create(array, &stack_a);
	def_sort(&stack_a, &stack_b, array, current);
	free_array(array);
	lstclear(&stack_a, free);
	return (0);
}
