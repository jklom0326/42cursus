/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shan <shan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 00:19:53 by shan              #+#    #+#             */
/*   Updated: 2022/07/18 00:19:53 by shan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sa(t_node *stack)
{
	int	value1;

	if (stack->next)
	{
		if (stack->next->next)
		{
			value1 = stack->next->value;
			stack->next->value = stack->next->next->value;
			stack->next->next->value = value1;
			value1 = stack->next->index;
			stack->next->index = stack->next->next->index;
			stack->next->next->index = value1;
			print_command("sa");
		}
	}
}

void	sb(t_node *stack)
{
	int	value1;

	if (stack->next)
	{
		if (stack->next->next)
		{
			value1 = stack->next->value;
			stack->next->value = stack->next->next->value;
			stack->next->next->value = value1;
			value1 = stack->next->index;
			stack->next->index = stack->next->next->index;
			stack->next->next->index = value1;
			print_command("sb");
		}
	}
}

void	ss(t_node *stack_a, t_node *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
