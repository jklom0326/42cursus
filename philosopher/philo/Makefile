# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shan <shan@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/30 23:00:21 by shan              #+#    #+#              #
#    Updated: 2022/08/30 23:00:21 by shan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = -rm -rf

INC = philo.h

SRCS = philo.c \
		philos_init.c\
		philos_action.c\
		times.c\
		parse.c\
		thread_init.c\
		routine.c\
		utils.c\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS) $(INC) 
	$(CC) -pthread $(CFLAGS) $^ -o $@

clean:
	rm -rf $(OBJS)
fclean: clean
	rm -rf $(NAME)

re: fclean all
