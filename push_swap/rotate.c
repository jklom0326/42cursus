/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shan <shan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 00:24:11 by shan              #+#    #+#             */
/*   Updated: 2022/07/18 00:24:11 by shan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ra(t_node *stack)
{
	t_node	*start;
	t_node	*last;
	int		counter;

	if (more_than_one(stack))
		return ;
	counter = 0;
	start = stack;
	while (stack->next && ++counter)
		stack = stack->next;
	last = stack;
	stack = start;
	if (counter == 2)
	{
		sa(stack);
		return ;
	}
	last->next = stack->next;
	stack->next = stack->next->next;
	last->next->next = NULL;
	last->next->previous = last;
	stack->next->previous = stack;
	print_command("ra");
}

void	rb(t_node *stack)
{
	t_node	*start;
	t_node	*last;
	int		counter;

	if (more_than_one(stack))
		return ;
	counter = 0;
	start = stack;
	while (stack->next && ++counter)
		stack = stack->next;
	last = stack;
	stack = start;
	if (counter == 2)
	{
		sb(stack);
		return ;
	}
	last->next = stack->next;
	stack->next = stack->next->next;
	last->next->next = NULL;
	last->next->previous = last;
	stack->next->previous = stack;
	print_command("rb");
}

void	rr(t_node *stack_a, t_node *stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
