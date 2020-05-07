# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/13 22:47:57 by pvalleci          #+#    #+#              #
#    Updated: 2019/05/22 14:18:39 by pvalleci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

CC = gcc

FLAGS = -Wall -Werror -Wextra

SRCS_NAME = display.c\
			free_tools.c\
			ft_ls.c\
			ioctl.c\
			parsing.c\
			sort.c\
			tools.c\
			tools2.c\
			tools3.c\
			ft_opt_long.c\
			quicksort.c

SRCS_PATH = srcs/

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJS = $(SRCS_NAME:.c=.o)

LIB_PATH = libft/

LIB = libft/libft.a

all : $(NAME)

$(NAME) : $(OBJS) $(LIB)
	@$(CC)  -o $(NAME) $(OBJS) $(LIB)

$(LIB) : $(LIB_PATH)
	@make -C $(LIB_PATH)

%.o : $(SRCS_PATH)%.c
	@$(CC)  -c $(SRCS)

clean :
	@make -C $(LIB_PATH) clean
	@rm -rf $(OBJS)

fclean : clean
	@make -C $(LIB_PATH) clean
	@rm -rf $(NAME)

re : fclean all

fsanitize : $(OBJS)
	gcc -fsanitize=address -o binari_sanitize $(OBJS) $(LIB)
