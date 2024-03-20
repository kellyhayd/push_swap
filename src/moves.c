/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:45:48 by krocha-h          #+#    #+#             */
/*   Updated: 2024/03/20 11:10:33 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_idx(t_stack **stack)
{
	int	i;

	while ((*stack)->next)
	{
		(*stack)->idx = i;
		(*stack) = (*stack)->next;
		i++;
	}
	(*stack)->idx = i;
}

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

void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;
	int		i;

	tmp = *stack;
	last = lstlast(*stack);
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last->next = tmp;
	tmp->prev = last;
	tmp->next = NULL;
	i = 0;
	while ((*stack)->next)
	{
		(*stack)->idx = i;
		i++;
	}
}

void	reverse_rotate(t_stack **stack)
{
	t_stack *tmp;
	t_stack *last;
	// int		i;

	tmp = (*stack);
	last = lstlast(*stack);
	*stack = last;
	(*stack)->prev = NULL;
	(*stack)->next = tmp;

	last = last->prev;
	if (last)
		last->next = NULL;
	// update_idx(stack);
	// i = 0;
	// while (*stack)
	// {
	// 	if (*stack != last)
    //         (*stack)->idx = i;
    //     *stack = (*stack)->next;
    //     i++;
	// }
	printf("%d\n", (*stack)->num);
	printf("%d\n", (*stack)->next->num);
	printf("%d\n", (*stack)->next->next->num);
}
