/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:59:20 by krocha-h          #+#    #+#             */
/*   Updated: 2024/03/20 16:43:20 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

// void	lstadd_back(t_stack **lst, t_stack *new)
// {
// 	t_stack *last;

// 	if (!last)
// 	{
// 		*lst = new;
// 		new->prev = NULL;
// 		new->next = NULL;
// 	}
// 	else
// 	{
// 		last->next = new;
// 		new->prev = last;
// 		new->next = NULL;
// 	}
// }

t_stack	*lstnew(int content, int idx)
{
	t_stack	*newlst;

	newlst = ft_calloc(sizeof(t_stack), 1);
	if (!newlst)
		return (0);
	newlst->num = content;
	newlst->idx = idx;
	newlst->next = NULL;
	newlst->prev = NULL;
	return (newlst);
}

int	lstsize(t_stack *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

