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

void	sa(t_stack **stack_a)
{
	int		num_tmp;

	num_tmp = (*stack_a)->num;
	(*stack_a)->num = (*stack_a)->next->num;
	(*stack_a)->next->num = num_tmp;
}
