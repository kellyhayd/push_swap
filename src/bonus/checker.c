/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:52:08 by krocha-h          #+#    #+#             */
/*   Updated: 2024/04/12 11:25:45 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	char	move[5];
	int		ok;

	ok = next_move(move);
	while (move[0])
	{
		if (!push_or_swap(move, a, b) && !rotate_or_reverse_rotate(move, a, b))
			return (0);
		ok = next_move(move);
	}
	return (ok);
}

int	parse_args(int argc, const char **argv, t_stack **a)
{
	if (argc < 2)
		return (0);
	if (!parse(a, argc, argv))
	{
		stack_free(*a);
		return (0);
	}
	if (!non_duplicates(*a))
	{
		stack_free(*a);
		return (0);
	}
	return (1);
}

int	main(int argc, const char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (!parse_args(argc, argv, &a))
		return (ft_error("Error\n"), 1);
	if (!check(&a, &b))
	{
		stack_free(a);
		stack_free(b);
		return (ft_error("Error\n"), 1);
	}
	if (b)
		ft_putstr("KO - b\n");
	if (!is_sorted(a))
		ft_putstr("KO - sorted\n");
	else
		ft_putstr("OK\n");
	stack_free(a);
	stack_free(b);
	return (0);
}
