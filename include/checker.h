/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:52:27 by krocha-h          #+#    #+#             */
/*   Updated: 2024/04/11 15:12:42 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

int	is_sorted(const t_stack *stack);
int	non_duplicates(const t_stack *stack);
int	parse_bonus(t_stack **stack, int argc, const char **argv);
// int	new_atoi(int *result, const char *str);
int	ft_write(int fd, const char *str, size_t nbytes);
int	ft_min_int(int x, int y);
int	ft_strcmp(const char *a, const char *b);

#endif
