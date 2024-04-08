// #include "checker.h"
#include "push_swap.h"

#define OK 0
#define KO 1
#define ERROR 2

int	is_sorted(const t_stack *stack)
{
	while (stack && stack->next && stack->value < stack->next->value)
		stack = stack->next;
	return (!stack || !stack->next);
}

int	check(t_stack **a)
{
	t_stack	*b;
	int		a_len;
	int		b_len;
	char	*move;

	b = NULL;
	a_len = lstsize(*a);
	b_len = lstsize(b);
	while ((move = get_next_line(0)))
	{
		if (ft_strncmp(move, "ra\n", 3))
			rotate(a);
		else if (ft_strncmp(move, "rb\n", 3))
			rotate(&b);	
		else if (ft_strncmp(move, "rr\n", 3))
		{
			rotate(&b);
			rotate(a);
		}
		else if (ft_strncmp(move, "rra\n", 4))
			reverse_rotate(a);
		else if (ft_strncmp(move, "rrb\n", 4))
			reverse_rotate(&b);
		else if (ft_strncmp(move, "rrr\n", 4))
		{
			reverse_rotate(&b);
			reverse_rotate(a);
		}
		else if (ft_strncmp(move, "sa\n", 3))
			swap(a);
		else if (ft_strncmp(move, "sb\n", 3))
			swap(&b);
		else if (ft_strncmp(move, "ss\n", 3))
		{
			swap(&b);
			swap(a);
		}
		else if (ft_strncmp(move, "pa\n", 3))
		{
			push(a, &b);
			a_len++;
			b_len--;
		}
		else if (ft_strncmp(move, "pb\n", 3))
		{	push(&b, a);
			a_len--;
			b_len++;
		}
		else
			return (ERROR);
		free(move);
	}
	if (b_len != 0)
	{
		stack_free(b);
		return (KO);
	}
	if (!is_sorted(*a))
		return (KO);
	return (OK);
}

int main(int argc, const char **argv)
{
	t_stack *stack;
	int		check_result;

	stack = NULL;
	if (argc < 2)
		return (0);
	if (!validate_args(argv, argc))
		ft_error("Error\n");
	if (!parse(&stack, argc, argv))
		return (1);
	check_result = check(&stack);
	if (check_result == ERROR)
		ft_error("Error\n");
	else if (check_result == KO)
		ft_error("KO\n");
	else if (check_result == OK)
		ft_putstr_fd("OK", 1);
	stack_free(stack);
	return (0);
}