NAME	= 	fillit

SRC		=	fillit.c free.c ft_affichage.c get_next_line.c\
			map.c parsing.c shift.c shift2.c solve.c

FLAGS	=	-Wall -Wextra -Werror

INC		=	libft

LIBDIR	=	libft

LIB		=	$(LIBDIR)/libft.a

all : $(NAME)

$(NAME)	:	$(LIB)
	@gcc $(FLAGS) $(SRC) $(LIB) -o $(NAME) -I $(INC)

$(LIB) :	
	@make -C $(LIBDIR) all

clean : 
	@make -C $(LIBDIR) clean

fclean :
	@rm -f $(NAME)
	@make -C $(LIBDIR) fclean

re : fclean all

debug : 
	@gcc -fsanitize=address $(SRC) $(LIB) -o $(NAME) -I $(INC)

.PHONY : all, re, clean, fclean, debug
