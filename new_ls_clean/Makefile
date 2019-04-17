NAME		=	ft_ls

FLAGS		=	-Wall -Wextra -Werror

SOURCE		=	sources/

SRC			=	display\
				ft_ls\
				ioctl\
				parsing\
				recursive\
				sort\
				tools\
				free_tools\

LIBFT		=	libft/libft.a

LIBMAKE		=	libft/

INCLUDES	=	.

OBJS		=	$(foreach ft,$(SRC),$(ft).o)

SRCS		=	$(foreach fun,$(SRC),$(SOURCE)$(fun).c)

all : $(NAME)

$(NAME) :
	make -C $(LIBMAKE)
	gcc $(FLAGS) -c $(SRCS) -I $(INCLUDES)
	gcc $(FLAGS) -o $(NAME) $(LIBFT) $(SRCS) -I $(INCLUDES) -fsanitize=address

clean :
	make -C $(LIBMAKE) clean
	rm -rf $(OBJS)

fclean : clean
	make -C $(LIBMAKE) fclean
	rm -rf $(NAME)

re : fclean all

.PHONY: all fclean clean re