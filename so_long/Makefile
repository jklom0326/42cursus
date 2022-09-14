# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shan <shan@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/10 23:19:32 by shan              #+#    #+#              #
#    Updated: 2022/07/11 00:34:54 by shan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
BONUS		= so_long_bonus

CC			= cc
CFLAG		= -Wall -Werror -Wextra

OS			= $(shell uname -s)

MLX		= ./minilibx-linux
LINK	= -L $(MLX) -lmlx -lXext -lX11 -lm -lbsd

SRC			= so_long.c\
			  ft_split.c \
			  ft_strjoin.c \
			  ft_strlcpy.c \
			  ft_utils.c \
			  map_draw.c \
			  read_map.c\
			  so_long_utils1.c\
			  so_long_utils2.c\
			  take_keys.c\

INC			= so_long.h

OBJ			= $(SRC:.c=.o)

all			: $(NAME)

$(NAME)		: $(OBJ) $(INC)
				$(CC) $(CFLAG) $(SRC) -o $(NAME) $(LINK)

clean		:
				rm -rf $(OBJ)

fclean		: clean
				rm -rf $(NAME)

re			: fclean all bonus
