/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shan <shan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 02:52:43 by shan              #+#    #+#             */
/*   Updated: 2022/07/18 02:52:43 by shan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap_bonus.h"

void	ra_checker(t_node *stack)
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
		sa_checker(stack);
		return ;
	}
	last->next = stack->next;
	stack->next = stack->next->next;
	last->next->next = NULL;
	last->next->previous = last;
	stack->next->previous = stack;
}

void	rb_checker(t_node *stack)
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
		sb_checker(stack);
		return ;
	}
	last->next = stack->next;
	stack->next = stack->next->next;
	last->next->next = NULL;
	last->next->previous = last;
	stack->next->previous = stack;
}

void	rr_checker(t_node *stack_a, t_node *stack_b)
{
	ra_checker(stack_a);
	rb_checker(stack_b);
}
