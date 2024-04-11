/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:52:08 by krocha-h          #+#    #+#             */
/*   Updated: 2024/04/11 15:22:36 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

// int main(int argc, const char **argv)
// {
// 	t_stack *stack;
// 	int		check_result;

// 	stack = NULL;
// 	if (argc < 2)
// 		return (0);
// 	if (!validate_args(argv, argc))
// 		ft_error("Error\n");
// 	if (!parse(&stack, argc, argv))
// 		return (1);
// 	check_result = check(&stack);
// 	if (check_result == ERROR)
// 		ft_error("Error\n");
// 	else if (check_result == KO)
// 		ft_error("KO\n");
// 	else if (check_result == OK)
// 		ft_putstr_fd("OK", 1);
// 	stack_free(stack);
// 	return (0);
// }

int	next_move(char *move)
{
	ssize_t	nbytes;

	move[0] = '\0';
	nbytes = read(0, move, 3);
	if (nbytes < 3)
		return (nbytes == 0);
	if (move[2] == '\n')
	{
		move[3] = '\0';
		return (1);
	}
	nbytes = read(0, &move[3], 1);
	if (nbytes < 1)
		return (0);
	move[4] = '\0';
	return (1);
}

int	push_or_swap(char *move, t_stack **a, t_stack **b)
{
	if (ft_strncmp(move, "pa\n", 3))
		push(a, b);
	else if (ft_strncmp(move, "pb\n", 3))
		push(b, a);
	else if (ft_strncmp(move, "sa\n", 3))
		swap(a);
	else if (ft_strncmp(move, "sb\n", 3))
		swap(b);
	else if (ft_strncmp(move, "ss\n", 3))
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
	if (ft_strncmp(move, "ra\n", 3))
		rotate(a);
	else if (ft_strncmp(move, "rb\n", 3))
		rotate(b);
	else if (ft_strncmp(move, "rr\n", 3))
	{
		rotate(a);
		rotate(b);
	}
	else if (ft_strncmp(move, "rra\n", 4))
		reverse_rotate(a);
	else if (ft_strncmp(move, "rrb\n", 4))
		reverse_rotate(b);
	else if (ft_strncmp(move, "rrr\n", 4))
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

	ok = 0;
	while ((ok = next_move(move)) && move[0])
	{
		if (!push_or_swap(move, a, b) && !rotate_or_reverse_rotate(move, a, b))
			return (0);
	}
	return (ok);
}

int	main(int argc, const char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		ok;

	a = NULL;
	b = NULL;
	ok = 0;
	ok = argc >= 2;
	ok = ok && parse(&a, argc, argv);
	ok = ok && non_duplicates(a);
	ok = ok && check(&a, &b);
	if (!ok)
		ft_write(2, "Error\n", 6);
	else if (b || !is_sorted(a))
		ft_write(1, "KO\n", 3);
	else
		ft_write(1, "OK\n", 3);
	if (a)
		stack_free(a);
	if (b)
		stack_free(b);
	if (!ok)
		return (1);
	return (0);
}
