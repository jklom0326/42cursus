/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shan <shan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 11:46:22 by shan              #+#    #+#             */
/*   Updated: 2022/07/23 11:46:22 by shan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	check_tab(char **t)
{
	int	i;
	int	j;

	i = -1;
	while (t[++i])
	{
		j = 0;
		while (t[i][j])
		{
			if (t[i][j] == '-' || t[i][j] == '+')
			{
				if (ft_atoi(&t[i][j]) == -2147483648)
					return (1);
				j++;
			}
			if (!ft_isdigit(t[i][j]) || is_double(t) == 0
				|| ft_atoi(&t[i][j]) < -2147483648
				|| ft_atoi(&t[i][j]) > 2147483647)
				return (0);
			while (ft_isdigit(t[i][++j]) == 1)
				if (t[i][j + 1] == '-' || t[i][j + 1] == '+')
					return (0);
		}
	}
	return (1);
}

size_t	count_espace(char *av)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	while (av[i])
	{
		if (av[i] == 32)
			j++;
		i++;
	}
	return (j);
}

int	check_args(char **v)
{
	int	i;

	i = 1;
	while (v[i])
	{
		if (ft_strlen(v[i]) == count_espace(v[i]))
			return (0);
		i++;
	}
	return (1);
}

char	**args(int ac, char **av)
{
	char	**t;
	char	*s;
	char	*arg;
	int		i;

	i = 1;
	s = (char *)malloc(1 * sizeof(char));
	if (!s)
		return (NULL);
	s[0] = '\0';
	if (check_args(av) == 0)
	{
		write (1, "Error\n", 6);
		exit (1);
	}
	while (i < ac)
	{
		arg = ft_strjoin(s, av[i++]);
		free (s);
		s = ft_strjoin(arg, " ");
		free(arg);
	}
	t = ft_split(s, ' ');
	free (s);
	return (t);
}

char	**push_in_t_stack(int ac, char **av, int *i)
{
	char	**tab;

	if (ac <= 1)
		exit (1);
	tab = args(ac, av);
	if (check_tab(tab) == 0)
	{
		write (1, "Error\n", 6);
		exit (1);
	}
	while (tab[*i])
	{
		(*i)++;
	}
	return (tab);
}
