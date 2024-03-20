/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:45:48 by krocha-h          #+#    #+#             */
/*   Updated: 2024/03/20 17:13:46 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_idx(t_stack **stack)
{
	int		i;
	t_stack	*aux;

	i = 0;
	aux = *stack;
	while (aux)
	{
		aux->idx = i;
		aux = aux->next;
		i++;
	}
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

	if (lstsize(*stack) >= 2)
	{
		tmp = *stack;
		last = lstlast(*stack);
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		last->next = tmp;
		tmp->prev = last;
		tmp->next = NULL;
		update_idx(stack);
		printf("%d\n", (*stack)->num);
		printf("%d\n", (*stack)->next->num);
		printf("%d\n", (*stack)->next->next->num);
	}
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;
	t_stack	*penultimate;

	if (lstsize(*stack) >= 2)
	{
		tmp = (*stack);
		last = lstlast(*stack);
		penultimate = last->prev;
		penultimate->next = NULL;
		last->prev = NULL;
		tmp->prev = last;
		last->next = tmp;
		*stack = last;
	}
}

// printf("%d\n", (*stack)->num);
// printf("%d\n", (*stack)->next->num);
// printf("%d\n", (*stack)->next->next->num);
