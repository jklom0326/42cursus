/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shan <shan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 22:24:47 by shan              #+#    #+#             */
/*   Updated: 2022/07/12 22:24:47 by shan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct node
{
	int			value;
	int			index;
	struct node	*next;
	struct node	*previous;
}	t_node;

typedef struct index
{
	long	value;
	int		index;
}	t_index;

typedef struct sort
{
	int	up;
	int	down;
	int	last_up;
	int	last_down;
	int	len;
}	t_sort;

void			errors_handler(int ac, char *av[]);
void			error(void);
void			error_isbigger(int ac, char *av[]);
void			error_isduplic(int ac, char *av[]);
void			error_isnumber(int ac, char *av[]);
void			error_isonearg(int ac);
char			**push_in_t_stack(int ac, char **av, int *i);
char			**args(int ac, char **av);
int				check_tab(char **t);
size_t			count_espace(char *av);
int				check_args(char **v);

int				ischardigit(char var);
int				print_command(char *name);
char			*ft_itoa(int n);
long			ft_atoi(const char *str);
size_t			ft_strlen(const char *pointer);
int				ft_strcmp(char *str1, char *str2);
long long int	ft_atoi_long(const char *str);
char			**ft_split(char const *s, char c);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
int				is_double(char **t);
long long int	ft_isdigit(long long int argument);

t_node			*init_stack(void);
int				more_than_one(t_node *stack);
void			populate(t_node *stack, int size, char *av[], int *indexator);
void			populate_2(t_node *stack, int size, char *argv[], int *idxatr);
void			free_stack(t_node *stack);
int				check_tab(char **t);

void			sort(t_node *stack_a, t_node *stack_b);
int				find_lower(t_node *stack_a);
int				*index_it(int ac, char *av[]);
int				*index_it_2(int ac, char *av[]);
int				stack_length(t_node *stack);
int				ordered(t_node *stack_a);
int				find_next_position(t_node *stack_b);
void			sort_with_3(t_node *stack_a);
void			sort_with_5(t_node *stack_a, t_node *stack_b);
void			sort_with_n(t_node *stack_a, t_node *stack_b, int len);

void			sa(t_node *stack);
void			sb(t_node *stack);
void			ss(t_node *stack_a, t_node *stack_b);
void			pa(t_node *stack_a, t_node *stack_b);
void			pb(t_node *stack_a, t_node *stack_b);
void			ra(t_node *stack);
void			rb(t_node *stack);
void			rr(t_node *stack_a, t_node *stack_b);
void			rra(t_node *stack);
void			rrb(t_node *stack);
void			rrr(t_node *stack_a, t_node *stack_b);

#endif
