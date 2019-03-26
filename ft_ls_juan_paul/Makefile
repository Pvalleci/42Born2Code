NAME		=	ft_ls

FLAGS		=	-Wall -Wextra -Werror

SOURCE		=	sources/

SRC			=	free\
				ft_ls\
				ls_recur\
				option_sort\
				parsing\
				tools\
				print_all\
				display\
				ioctl_display\

LIBFT		=	libft/libft.a

LIBMAKE		=	libft/

INCLUDES	=	includes/

OBJS		=	$(foreach ft,$(SRC),$(ft).o)

SRCS		=	$(foreach fun,$(SRC),$(SOURCE)$(fun).c)

all : $(NAME)

$(NAME) :
	@make -C $(LIBMAKE)
	@gcc $(FLAGS) -c $(SRCS) -I $(INCLUDES)
	@gcc $(FLAGS) -o $(NAME) $(LIBFT) $(SRCS) -I $(INCLUDES)

clean :
	@make -C $(LIBMAKE) clean
	@rm -rf $(OBJS)

fclean : clean
	@make -C $(LIBMAKE) fclean
	@rm -rf $(NAME)

re : fclean all

.PHONY: all fclean clean re