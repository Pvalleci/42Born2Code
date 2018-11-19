NAME = libft.a

FLAGS = -Wall -Werror -Wextra

SOURCES = ft_memchr.c ft_putstr.c ft_strjoin.c ft_strsplit.c ft_memcmp.c \
ft_putstr_fd.c ft_strlcat.c ft_strstr.c ft_atoi.c ft_memcpy.c ft_strcat.c \
ft_strlen.c ft_strsub.c ft_bzero.c ft_memdel.c ft_strchr.c ft_strmap.c \
ft_strtrim.c ft_isalnum.c ft_memmove.c ft_strclr.c ft_strmapi.c ft_tolower.c \
ft_isalpha.c ft_memset.c ft_strcmp.c ft_strncat.c ft_toupper.c ft_isascii.c \
ft_putchar.c ft_strcpy.c ft_strncmp.c ft_isdigit.c ft_putchar_fd.c ft_strdel.c \
ft_strncpy.c ft_isprint.c ft_putendl.c ft_strdup.c ft_strnequ.c ft_itoa.c \
ft_putendl_fd.c ft_strequ.c ft_strnew.c ft_memalloc.c ft_putnbr.c \
ft_striter.c ft_strnstr.c ft_memccpy.c ft_putnbr_fd.c ft_striteri.c ft_strrchr.c \
ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c \
ft_strrev.c ft_putnbr_base.c ft_strndup.c ft_print_table.c

OBJETS = ft_memchr.o ft_putstr.o ft_strjoin.o ft_strsplit.o ft_memcmp.o \
ft_putstr_fd.o ft_strlcat.o ft_strstr.o ft_atoi.o ft_memcpy.o ft_strcat.o \
ft_strlen.o ft_strsub.o ft_bzero.o ft_memdel.o ft_strchr.o ft_strmap.o \
ft_strtrim.o ft_isalnum.o ft_memmove.o ft_strclr.o ft_strmapi.o ft_tolower.o \
ft_isalpha.o ft_memset.o ft_strcmp.o ft_strncat.o ft_toupper.o ft_isascii.o \
ft_putchar.o ft_strcpy.o ft_strncmp.o ft_isdigit.o ft_putchar_fd.o ft_strdel.o \
ft_strncpy.o ft_isprint.o ft_putendl.o ft_strdup.o ft_strnequ.o ft_itoa.o \
ft_putendl_fd.o ft_strequ.o ft_strnew.o ft_memalloc.o ft_putnbr.o ft_striter.o \
ft_strnstr.o ft_memccpy.o ft_putnbr_fd.o ft_striteri.o ft_strrchr.o \
ft_lstadd.o ft_lstdel.o ft_lstdelone.o ft_lstiter.o ft_lstmap.o ft_lstnew.o \
ft_strrev.o ft_putnbr_base.o ft_strndup.o ft_print_table.o

$(NAME) :
	gcc $(FLAGS) -c $(SOURCES)
	ar rcs $(NAME) $(OBJETS)

all : $(NAME)

re :
	gcc $(FLAGS) -c $(SOURCES)
	ar rcs $(NAME) $(OBJETS)

clean:
	rm -rf $(OBJETS)

fclean: clean
	rm -rf $(NAME)
