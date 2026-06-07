#include "push_swap.h"

void	sort_three(t_node **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->value;
	second = ((*stack)->next)->value;
	third = ((*stack)->next->next)->value;
	if (first < second && second < third && third > first)
		return ;
	else if (first < second && second > third && third > first)
	{
		rra(stack);
		sa(stack);
	}
	else if (first > second && second < third && third > first)
		sa(stack);
	else if (first < second && second > third && third < first)
		rra(stack);
	else if (first > second && second < third && third < first)
		ra(stack);
	else
	{
		ra(stack);
		sa(stack);
	}
}
