# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shan <shan@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/09 21:57:35 by shan              #+#    #+#              #
#    Updated: 2022/06/13 14:08:30 by shan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1	= server
NAME2	= client
BONUS1	= server_bonus
BONUS2	= client_bonus

CC		= gcc
CFLAG	= -Wall -Wextra -Werror

RM		= rm -f

INC		= minitalk.h

SRCS	= minitalk_utils.c\

OBJS	= $(SRCS:.c=.o) 

all		:$(NAME1) $(NAME2)

$(NAME1): server.c $(INC)
	 		$(CC) $(CFLAGS) server.c $(SRCS) -o server
$(NAME2): client.c $(INC)
			$(CC) $(CFLAGS) client.c $(SRCS) -o client

bonus	: all $(BONUS1) $(BONUS2)

$(BONUS1): server.c $(INC)
	 		$(CC) $(CFLAGS) server_bonus.c $(SRCS) -o server_bonus
$(BONUS2): client.c $(INC)
			$(CC) $(CFLAGS) client_bonus.c $(SRCS) -o client_bonus

clean	:
		$(RM) $(OBJS)

fclean	: clean
		$(RM) $(NAME1) $(NAME2) $(BONUS1) $(BONUS2)

re		: fclean all
