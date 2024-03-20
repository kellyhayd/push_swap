/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:45:48 by krocha-h          #+#    #+#             */
/*   Updated: 2024/03/14 17:50:21 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	int	num_tmp;
	int	idx_tmp;

	num_tmp = (*stack)->num;
	idx_tmp = (*stack)->idx;
	(*stack)->num = (*stack)->next->num;
	(*stack)->idx = (*stack)->next->idx;
	(*stack)->next->num = num_tmp;
	(*stack)->next->idx = idx_tmp;
}

void	rotate(t_stack **stack, t_data *lst)
{
	t_stack *last = lst->last;
    t_stack *new_first = NULL;
    t_stack *tmp;
	t_stack	*print;
    int     i;

    last->next = NULL;
    new_first->prev = NULL;
    tmp = *stack;
    *stack = (*stack)->next;
    lst->last = tmp;
	lst->last->next = NULL;
	lst->last->prev = last;

    i = 0;
	tmp = *stack;
   	while ((*stack)->next)
    {
        tmp->idx = i;
		*stack = (*stack)->next;
        i++;
    }

	// print = lstlast(*stack);
	printf("\nnode 1 = %d\nnode last = %d\n", (*stack)->num, lst->last->num);
	// printf("\nlast node: num = %d | idx = %d\n", print->num, print->idx);
}
