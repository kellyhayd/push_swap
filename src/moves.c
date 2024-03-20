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
	t_stack	*tmp;
	t_stack	*last;

	tmp = *stack;
	last = lst->last;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last->next = tmp;
	tmp->prev = last;
	tmp->next = NULL;
	lst->last = tmp;
}

void	reverse_rotate(t_stack **stack, t_data *lst)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!*stack || !lst)
		return ;
	tmp = malloc(sizeof(t_stack));
	last = malloc(sizeof(t_stack));
	tmp = *stack;
	last = lst->last;

	*stack = last;
	(*stack)->prev = NULL;
	(*stack)->next = tmp;

	last = last->prev;
	last->next = NULL;
	lst->last = last;

	printf("%d\n", lst->last->num);
	

}
