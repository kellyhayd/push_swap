#include "push_swap.h"

void	lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	last = ft_lstlast(*lst);
	if (!last)
	{
		*lst = new;
		new->prev = NULL;
	}
	else
	{
		last->next = new;
		new->prev = last;
	}
}