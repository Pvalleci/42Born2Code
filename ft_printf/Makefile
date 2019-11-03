# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/29 06:52:45 by pvalleci          #+#    #+#              #
#    Updated: 2019/10/30 12:59:29 by pvalleci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_aff_resultat.c ft_get.c ft_printf.c ft_toa.c ft_flag.c ft_get_type.c \
	  ft_result_1.c ft_result_2.c tools.c ft_flag_2.c base.c ft_precision.c \
	  ft_free.c ft_float.c check_format.c \

DIR_OBJ = obj/

DIR_SRC = src/

LIBFT = libft

INC = include

FLAG  = -Werror -Wall -Wextra

SRCS = $(addprefix $(DIR_SRC), $(SRC))

OBJS =  $(addprefix $(DIR_OBJ), $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	cp libft/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(DIR_OBJ)%.o: $(DIR_SRC)%.c
	mkdir -p $(DIR_OBJ)
	gcc $(FLAG) -I $(INC) -I libft -o $@ -c $<

clean:
	rm -rf $(DIR_OBJ)
	make -C $(LIBFT) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT) fclean

norm:
	norminette $(SRCS)

re: fclean all

.PHONY : all, re, clean, fclean, norm
