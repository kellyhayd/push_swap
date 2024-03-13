#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
	int		num;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

//--------------------------------------- Validate

int	validate_args(char **argv);

//--------------------------------------- Format

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

//--------------------------------------- Linked List Functions

t_stack	*lstlast(t_stack *lst);
void	lstadd_back(t_stack **lst, t_stack *new);
t_stack	*lstnew(int content);

#endif
