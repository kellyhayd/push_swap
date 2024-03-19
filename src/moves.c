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

	num_tmp = (*stack)->num;
	(*stack)->num = (*stack)->next->num;
	(*stack)->next->num = num_tmp;
}
