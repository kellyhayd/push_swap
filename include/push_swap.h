#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
	int		num;
	t_stack	*next;
	t_stack	*prev;
}	t_stack;

int	*stack_copy(t_stack *stack_a);

/*
 * @brief Creates a linked list from an array of strings
 * that result from the given arguments
 * 
 * @param array A pointer to a null-terminated array of strings.
 * Each string will be an element in the created linked list
 * 
 * @result A pointer to the first element of the newly created linked list
 * 
 * @detail This function iterates through the provided array and creates
 * a new (node) for each string using ft_lstnew. If the list is empty,
 * the first element becomes the head. Otherwise, it is appended to
 * the end of the existing list
 */
t_stack	**stack_create(const char **array);



#endif