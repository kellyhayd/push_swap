/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:45:48 by krocha-h          #+#    #+#             */
/*   Updated: 2024/03/22 13:03:34 by krocha-h         ###   ########.fr       */
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

// printf("%d\n", (*stack)->num);
// printf("%d\n", (*stack)->next->num);
// printf("%d\n", (*stack)->next->next->num);
