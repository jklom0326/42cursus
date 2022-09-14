/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shan <shan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 02:50:05 by shan              #+#    #+#             */
/*   Updated: 2022/07/18 02:50:05 by shan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

# define EOL			1
# define FT_EOF			0
# define ERROR			-1
# define BUFFER_SIZE	1
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
	int	value;
	int	index;
}	t_index;

typedef struct sort
{
	int	up;
	int	down;
	int	last_up;
	int	last_down;
	int	len;
}	t_sort;

int				get_next_line(int fd, char **line);
void			*ft_memcpy(void *dest, const void *src, size_t n);
size_t			ft_strlen(const char *pointer);
char			*ft_strjoin_g(char *s1, char const *s2);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_substr(char const *s, unsigned int start, size_t len);
void			ft_strdel(char **str);
int				init_error(char *buffer);
int				check_tab(char **t);

void			errors_handler(int ac, char *av[]);
void			error(void);
void			error_isbigger(int ac, char *av[]);
void			error_isduplic(int ac, char *av[]);
void			error_isnumber(int ac, char *av[]);
void			error_isonearg(int ac);
char			**push_in_t_stack(int ac, char *av[], int *i);
char			**args(int ac, char **av);
void			gnl_command_checker(t_node *stack_a, t_node *stack_b);
void			ordered_checker(t_node *stack_a, t_node *stack_b);
void			populate_checker(t_node *stack, int size, char *av[]);
void			populate_checker_2(t_node *stack, int size, char *av[]);
void			exec_command(char *line, t_node *stack_a, t_node *stack_b);

int				ischardigit(char var);
int				print_command(char *name);
char			*ft_itoa(int n);
int				ft_atoi(const char *str);
size_t			ft_strlen(const char *pointer);
int				ft_strcmp(char *str1, char *str2);
long long int	ft_atoi_long(const char *str);
char			**ft_split(char const *s, char c);

t_node			*init_stack(void);
int				more_than_one(t_node *stack);
void			populate(t_node *stack, int size, char *av[], int *indexator);
void			free_stack(t_node *stack);

void			sort(t_node *stack_a, t_node *stack_b);
int				find_lower(t_node *stack_a);
int				*index_it(int ac, char *av[]);
int				stack_length(t_node *stack);
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

void			sa_checker(t_node *stack);
void			sb_checker(t_node *stack);
void			ss_checker(t_node *stack_a, t_node *stack_b);
void			pa_checker(t_node *stack_a, t_node *stack_b);
void			pb_checker(t_node *stack_a, t_node *stack_b);
void			ra_checker(t_node *stack);
void			rb_checker(t_node *stack);
void			rr_checker(t_node *stack_a, t_node *stack_b);
void			rra_checker(t_node *stack);
void			rrb_checker(t_node *stack);
void			rrr_checker(t_node *stack_a, t_node *stack_b);

#endif
