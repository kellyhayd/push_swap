/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:59:26 by krocha-h          #+#    #+#             */
/*   Updated: 2024/03/13 17:20:58 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	**stack_create(const char **array)
{
	t_stack	**stack;
	t_stack	*new;
	t_stack	*last;
	int		i;

	stack = NULL;
	new = NULL;
	last = NULL;
	i = 0;
	while (array[i])
	{
		new = lstnew(ft_atoi(array[i]));
		if (!new)
			exit(EXIT_FAILURE);
		lstadd_back(stack, new);
		i++;
	}
	return (stack);
}
