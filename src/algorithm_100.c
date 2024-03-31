/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_100.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:13:51 by krocha-h          #+#    #+#             */
/*   Updated: 2024/03/27 17:54:34 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	send_to_b(t_stack **stack_a, t_stack **stack_b, t_data *current)
{
	int	proximity;
	int	direction;
	int	count;

	count = 0;
	proximity = (current->size - 1) / 2;
	if (current->idx >= proximity)
		direction = 1;
	else
		direction = 2;
	while ((*stack_a)->num != current->num_cur)
	{
		if ((*stack_a)->num < current->num_max)
		{
			pb(stack_a, stack_b);
			count++;
		}
		else if (direction == 1)
			rra(stack_a);
		else if (direction == 2)
			ra(stack_a);
	}
	pb(stack_a, stack_b);
	count++;
	current->size = lstsize(*stack_a);
	return (count);
}

void	sort_hundred(t_stack **stack_a, t_stack **stack_b, t_data *current)
{
	int	div;
	int	parcel;
	int	count;
	t_stack	*tmp;
	t_stack	*tmp2;

	div = (current->size) / 4;
	parcel = div;
	while (parcel < (div * 4))
	{
		current->num_max = current->args[parcel];
		tmp = *stack_a;
		count = 0;
		while (count < div)
		{
			if (tmp->num < current->num_max)
			{
				current->idx = tmp->idx;
				current->num_cur = tmp->num;
				count += send_to_b(stack_a, stack_b, current);
			}
			else
				tmp = tmp->next;
		}
		parcel += div;
	}
	tmp = *stack_a;
	printf("\nstack_a ");
	while (tmp)
	{
		printf("%d ", (tmp)->num);
		(tmp) = (tmp)->next;
	}
	printf("\nstack_b ");
	tmp2 = *stack_b;
	while (tmp2)
	{
		printf("%d ", (tmp2)->num);
		(tmp2) = (tmp2)->next;
	}
}
