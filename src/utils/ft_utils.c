/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:25:53 by krocha-h          #+#    #+#             */
/*   Updated: 2024/04/11 15:25:54 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min_int(int x, int y)
{
	if (x < y)
		return (x);
	return (y);
}

int	ft_write(int fd, const char *str, size_t nbytes)
{
	size_t	i;
	ssize_t	res;

	i = 0;
	while (nbytes != 0 && (res = write(fd, &str[i], nbytes)) >= 0)
	{
		nbytes -= (size_t) res;
		i += (size_t) res;
	}
	return (res >= 0);
}
