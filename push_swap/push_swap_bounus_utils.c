/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bounus_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shan <shan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 00:15:57 by shan              #+#    #+#             */
/*   Updated: 2022/08/04 00:15:57 by shan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap_bonus.h"

void	errors_handler(int ac, char *av[])
{
	error_isonearg(ac);
	error_isnumber(ac, av);
	error_isbigger(ac, av);
	error_isduplic(ac, av);
}

void	exec_command(char *line, t_node *stack_a, t_node *stack_b)
{
	if (ft_strcmp(line, "sa"))
		sa_checker(stack_a);
	else if (ft_strcmp(line, "sb"))
		sb_checker(stack_b);
	else if (ft_strcmp(line, "ss"))
		ss_checker(stack_a, stack_b);
	else if (ft_strcmp(line, "pa"))
		pa_checker(stack_a, stack_b);
	else if (ft_strcmp(line, "pb"))
		pb_checker(stack_a, stack_b);
	else if (ft_strcmp(line, "ra"))
		ra_checker(stack_a);
	else if (ft_strcmp(line, "rb"))
		rb_checker(stack_b);
	else if (ft_strcmp(line, "rr"))
		rr_checker(stack_a, stack_b);
	else if (ft_strcmp(line, "rra"))
		rra_checker(stack_a);
	else if (ft_strcmp(line, "rrb"))
		rrb_checker(stack_b);
	else if (ft_strcmp(line, "rrr"))
		rrr_checker(stack_a, stack_b);
	else
		error();
}

void	gnl_command_checker(t_node *stack_a, t_node *stack_b)
{
	int		i;
	char	*line;

	i = 1;
	while (i)
	{
		i = get_next_line(0, &line);
		if (!i)
		{
			free(line);
			break ;
		}
		exec_command(line, stack_a, stack_b);
		free(line);
	}
}
