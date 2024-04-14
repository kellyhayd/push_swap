/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:52:08 by krocha-h          #+#    #+#             */
/*   Updated: 2024/04/12 17:05:44 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_or_swap(char *move, t_stack **a, t_stack **b)
{
	if (ft_strncmp(move, "pa\n", 3) == 0)
		push(a, b);
	else if (ft_strncmp(move, "pb\n", 3) == 0)
		push(b, a);
	else if (ft_strncmp(move, "sa\n", 3) == 0)
		swap(a);
	else if (ft_strncmp(move, "sb\n", 3) == 0)
		swap(b);
	else if (ft_strncmp(move, "ss\n", 3) == 0)
	{
		swap(a);
		swap(b);
	}
	else
		return (0);
	return (1);
}

int	rotate_or_reverse_rotate(char *move, t_stack **a, t_stack **b)
{
	if (ft_strncmp(move, "ra\n", 3) == 0)
		rotate(a);
	else if (ft_strncmp(move, "rb\n", 3) == 0)
		rotate(b);
	else if (ft_strncmp(move, "rr\n", 3) == 0)
	{
		rotate(a);
		rotate(b);
	}
	else if (ft_strncmp(move, "rra\n", 4) == 0)
		reverse_rotate(a);
	else if (ft_strncmp(move, "rrb\n", 4) == 0)
		reverse_rotate(b);
	else if (ft_strncmp(move, "rrr\n", 4) == 0)
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
	else
		return (0);
	return (1);
}

int	check(t_stack **a, t_stack **b)
{
	char	*move;

	move = get_next_line(0);
	if (move == NULL)
		return (0);
	while (move[0] != '\0')
	{
		if (!push_or_swap(move, a, b) && !rotate_or_reverse_rotate(move, a, b))
		{
			free(move);
			return (0);
		}
		free(move);
		move = get_next_line(0);
		if (move == NULL)
			return (0);
	}
	free(move);
	return (1);
}

int	is_sorted(const t_stack *stack)
{
	while (stack && stack->next && stack->value < stack->next->value)
		stack = stack->next;
	return (!stack || !stack->next);
}

int	main(int argc, const char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	if (!validate_args(argv, argc))
		ft_error("Error\n");
	if (is_ordered(argv, argc))
		return (0);
	if (!parse(&a, argc, argv) || !check(&a, &b))
	{
		stack_free(a);
		stack_free(b);
		ft_error("Error\n");
	}
	if (b || !is_sorted(a))
		ft_putstr("KO\n");
	else
		ft_putstr("OK\n");
	stack_free(a);
	stack_free(b);
	return (0);
}
