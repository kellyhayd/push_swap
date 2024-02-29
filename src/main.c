#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	**stack_a;

	if (argc <= 1)
		exit(EXIT_FAILURE);
	*stack_a = stack_create((const char)(argv + 1));
	return (0);
}