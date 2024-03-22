/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:31:18 by krocha-h          #+#    #+#             */
/*   Updated: 2024/03/22 15:10:38 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/* Converts string to an integer */
int	ft_atoi(const char *str)
{
	int	i;
	int	n;
	int	result;

	if (str[i] == '\0')
		return (NULL);
	i = 0;
	n = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * n);
}
