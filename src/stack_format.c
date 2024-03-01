/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:59:26 by krocha-h          #+#    #+#             */
/*   Updated: 2024/03/01 14:27:42 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	*stack_copy(t_stack *stack_a)
// {
// 	int		*array_copy;
// 	int		i;
// 	int		stack_size;
// 	t_stack	*copy;

// 	copy = stack_a;
// 	stack_size = ft_lstsize(stack_a);
// 	array_copy = malloc(sizeof(int) * stack_size);
// 	if (!array_copy)
// 		return (NULL);
// 	i = 0;
// 	while (copy->next != NULL)
// 	{
// 		array_copy[i] = copy->num;
// 		copy = copy->next;
// 		i++;
// 	}
// 	array_copy[i] = copy->num;
// 	return(array_copy);
// }

// t_stack	**stack_create(const char **array)
// {
// 	t_stack	**stack;
// 	t_stack	*new;
// 	t_stack	*last;
// 	int		i;

// 	stack = NULL;
// 	new = NULL;
// 	last = NULL;
// 	i = 0;
// 	while (array[i])
// 	{
// 		if (ft_strlen(array[i] > 1))
// 		{

// 		}
// 		if (!ft_isdigit(array[i]))
// 		{
// 			ft_putstr_fd("Error\n", 2);
// 			exit(EXIT_FAILURE);
// 		}
// 		new = lstnew(ft_atoi(array[i]));
// 		if (!new)
// 			exit(EXIT_FAILURE);
// 		lstadd_back(stack, new);
// 		i++;
// 	}
// 	return (stack);
// }
