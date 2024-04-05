#include "push_swap.h"

static int	define_case_reverse(t_stack **stack)
{
	if ((*stack)->num < (*stack)->next->num
		&& (*stack)->next->num > (*stack)->next->next->num
		&& (*stack)->next->next->num > (*stack)->num)
		return (1);
	else if ((*stack)->num > (*stack)->next->num
		&& (*stack)->num < (*stack)->next->next->num)
		return (2);
	else if ((*stack)->num < (*stack)->next->num
		&& (*stack)->next->next->num < (*stack)->num)
		return (3);
	else if ((*stack)->num > (*stack)->next->num
		&& (*stack)->next->num < (*stack)->next->next->num
		&& (*stack)->num > (*stack)->next->next->num)
		return (4);
	else if ((*stack)->num > (*stack)->next->num
		&& (*stack)->next->num < (*stack)->next->next->num
		&& (*stack)->num < (*stack)->next->next->num)
		return (5);
	else if ((*stack)->num < (*stack)->next->num
		&& (*stack)->next->num < (*stack)->next->next->num
		&& (*stack)->num < (*stack)->next->next->num)
		return (6);
	return (-1);
}

void	sort_three_reverse(t_stack **stack)
{
	int	n;

	n = define_case_reverse(stack);
	if (n == 1)
		rb(stack);
	else if (n == 2)
		rrb(stack);
	else if (n == 3)
		sb(stack);
	else if (n == 4)
	{
		sb(stack);
		rb(stack);
	}
	else if (n == 5)
		rrb(stack);
	else if (n == 6)
	{
		sb(stack);
		rrb(stack);
	}
}