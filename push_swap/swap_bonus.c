/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shan <shan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 02:53:09 by shan              #+#    #+#             */
/*   Updated: 2022/07/18 02:53:09 by shan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sa_checker(t_node *stack)
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
		}
	}
}

void	sb_checker(t_node *stack)
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
		}
	}
}

void	ss_checker(t_node *stack_a, t_node *stack_b)
{
	sa_checker(stack_a);
	sb_checker(stack_b);
}
