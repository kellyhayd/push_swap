/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:59:26 by krocha-h          #+#    #+#             */
/*   Updated: 2024/03/14 12:41:38 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_create(const char **array, t_stack **stack, t_data *lst)
{
	t_stack		*last;
	t_stack		*new;
	int			i;
	static int	idx;

	new = NULL;
	last = NULL;
	i = -1;
	while (array[++i])
	{
		new = lstnew(ft_atoi(array[i]), idx);
		if (!new)
			exit(EXIT_FAILURE);
		if (!last)
			*stack = new;
		else
		{
			last->next = new;
			new->next = NULL;
			new->prev = last;
		}
		last = new;
		lst->last = new;
		printf("%d\n", last->num);
		printf("idx = %d\n", last->idx);
		idx++;
	}
}
