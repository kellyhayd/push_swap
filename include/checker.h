/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:52:27 by krocha-h          #+#    #+#             */
/*   Updated: 2024/04/12 10:45:36 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

int	is_sorted(const t_stack *stack);
int	non_duplicates(const t_stack *stack);
int	parse_bonus(t_stack **stack, int argc, const char **argv);
int	next_move(char *move);
int	ft_min_int(int x, int y);
int	ft_strcmp(const char *a, const char *b);

#endif
