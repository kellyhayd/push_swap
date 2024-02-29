#include "push_swap.h"

// int	*stack_copy(t_stack *stack_a)
// {
// 	int		*array_copy;
// 	int		i;
// 	int		stack_size;
// 	t_stack	*copy;

// 	copy = stack_a;
// 	stack_size = ft_lstsize(stack_a);
// 	array_copy = malloc(sizeof(int) * stack_size);
// 	if (!array_copy)
// 		return (NULL);
// 	i = 0;
// 	while (copy->next != NULL)
// 	{ 
// 		array_copy[i] = copy->num;
// 		copy = copy->next;
// 		i++;
// 	}
// 	array_copy[i] = copy->num;
// 	return(array_copy);
// }

t_stack	**stack_create(const char **array)
{
	t_stack	**stack;
	t_stack	*new;
	t_stack	*last;
	int		i;

	stack = NULL;
	new = NULL;
	last = NULL;
	i = 0;
	while (array[i])
	{
		if (!ft_isdigit((int)array[i]))
		{
			ft_putstr_fd("Error\n", 2);
			exit(EXIT_FAILURE);
		}
		new = ft_lstnew(ft_atoi(array[i]));
		if (!new)
			exit(EXIT_FAILURE);
		lstadd_back(stack, new);
		i++;
	}
	return (stack);
}
