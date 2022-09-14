/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shan <shan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 02:53:27 by shan              #+#    #+#             */
/*   Updated: 2022/07/18 02:53:27 by shan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap_bonus.h"

void	ordered_checker(t_node *stack_a, t_node *stack_b)
{
	stack_a = stack_a->next;
	while (stack_a->next)
	{
		if (stack_a->value > stack_a->next->value)
		{
			write(1, "KO\n", 3);
			return ;
		}
		stack_a = stack_a->next;
	}
	if (stack_length(stack_b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

void	populate_checker(t_node *stack, int size, char *av[])
{
	int	i;

	i = 0;
	stack->next = (t_node *)malloc(sizeof(t_node));
	stack->next->previous = stack;
	stack->previous = NULL;
	stack = stack->next;
	while (i < size - 2)
	{
		stack->next = (t_node *)malloc(sizeof(t_node));
		stack->next->previous = stack;
		stack->value = ft_atoi(av[i + 1]);
		stack = stack->next;
		i++;
	}
	stack->value = ft_atoi(av[i + 1]);
	stack->next = NULL;
}

void	populate_checker_2(t_node *stack, int size, char *av[])
{
	int	i;

	i = 0;
	stack->next = (t_node *)malloc(sizeof(t_node));
	stack->next->previous = stack;
	stack->previous = NULL;
	stack = stack->next;
	while (i < size - 1)
	{
		stack->next = (t_node *)malloc(sizeof(t_node));
		stack->next->previous = stack;
		stack->value = ft_atoi(av[i]);
		stack = stack->next;
		i++;
	}
	stack->value = ft_atoi(av[i]);
	stack->next = NULL;
}

int	main(int ac, char *av[])
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	**tab;
	int		i;

	stack_a = init_stack();
	stack_b = init_stack();
	if (ac == 2)
	{
		tab = push_in_t_stack(ac, av, &i);
		populate_checker_2(stack_a, i, tab);
	}
	else
	{
		errors_handler(ac, av);
		populate_checker(stack_a, ac, av);
	}
	gnl_command_checker(stack_a, stack_b);
	ordered_checker(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
}
