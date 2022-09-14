# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shan <shan@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/18 18:34:49 by shan              #+#    #+#              #
#    Updated: 2022/04/26 17:45:53 by shan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

CC			=	gcc
CFLAG		=	-Wall -Wextra -Werror

RM			=	rm -f

AR			=	ar rcs

SRCS		=	ft_printf.c\
				ft_printf_utils.c

OBJS		=	$(SRCS:.c=.o)


%.o		:	%.c
			$(CC) $(CFLAG) -c -o $*.o $<
	

$(NAME)		: 	$(OBJS)
			@ $(AR) $(NAME) $(OBJS)
all			:	$(NAME)

clean		:
				$(RM) $(OBJS)

fclean		:	clean
				$(RM) $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re
