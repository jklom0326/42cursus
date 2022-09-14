/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shan <shan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 00:24:37 by shan              #+#    #+#             */
/*   Updated: 2022/07/18 00:24:37 by shan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	rra(t_node *stack)
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
	last->previous->next = NULL;
	stack->next = last;
	last->previous = stack;
	last->next->previous = last;
	print_command("rra");
}

void	rrb(t_node *stack)
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
	last->previous->next = NULL;
	stack->next = last;
	last->previous = stack;
	last->next->previous = last;
	print_command("rrb");
}

void	rrr(t_node *stack_a, t_node *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
