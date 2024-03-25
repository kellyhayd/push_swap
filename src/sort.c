/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:31:58 by krocha-h          #+#    #+#             */
/*   Updated: 2024/03/25 17:01:46 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	define_sort(t_stack **stack_a, t_stack **stack_b, int size_lst)
{
	if (size_lst == 3)
		sort_three(stack_a);
	if (size_lst == 4)
		sort_four(stack_a, stack_b);
	if (size_lst == 5)
		sort_five(stack_a, stack_b);
}
