/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:03:57 by krocha-h          #+#    #+#             */
/*   Updated: 2024/04/12 10:24:04 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define NO_ACTION 0
# define RA 1
# define RRA 2
# define RB 3
# define RRB 4
# define RR 5
# define RRR 6
# define PB 7

# include "libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

typedef struct step
{
	int	type;
	int	times;
}	t_step;

typedef struct move
{
	int		cost;
	t_step	steps[5];
}	t_move;

void	stack_free(t_stack *stack);
int		stack_addlast(t_stack **stack, int value);
int		lstsize(t_stack *lst);

int		parse(t_stack **stack, int argc, const char **argv);
int		sort(t_stack **a);

void	push(t_stack **dst, t_stack **src);
void	reverse_rotate(t_stack **stack);
void	swap(t_stack **stack);
void	rotate(t_stack **stack);
int		pa(t_stack **a, t_stack **b);
int		pb(t_stack **a, t_stack **b);
int		rra(t_stack **stack);
int		rrb(t_stack **stack);
int		rrr(t_stack **a, t_stack **b);
int		ra(t_stack **stack);
int		rb(t_stack **stack);
int		rr(t_stack **a, t_stack **b);
void	swap(t_stack **stack);
int		sa(t_stack **stack);
int		sb(t_stack **stack);
int		ss(t_stack **a, t_stack **b);

t_move	move_rr_pb(int i, int j);
t_move	move_rrr_pb(int i, int j);
t_move	move_ra_rrb_pb(int i, int j);
t_move	move_rra_rb_pb(int i, int j);

int		find_max_index(const t_stack *stack);
int		find_greatest_lower_than_index(const t_stack *stack, int value);

t_move	best_move_to_b(t_stack **a, int a_len, t_stack **b, int b_len);
int		execute_step(t_step step, t_stack **a, t_stack **b);
int		execute_steps(const t_step *steps, t_stack **a, t_stack **b);

// int		ft_write(int fd, const char *str, size_t nbytes);
int		get_min(t_stack **stack);
int		ft_min_int(int x, int y);

int		validate_args(const char **argv, int argc);
int		is_ordered(const char **argv, int argc);

void	sort_three(t_stack **stack);
void	sort_two(t_stack **stack);
void	sort_four(t_stack **stack_a, t_stack **stack_b);
void	sort_five(t_stack **stack_a, t_stack **stack_b);

#endif
