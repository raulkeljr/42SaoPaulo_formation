SRC=ft_atoi.c ft_memccpy.c ft_putnbr_fd.c ft_strncmp.c ft_bzero.c ft_memchr.c ft_putstr_fd.c \
    ft_strnstr.c ft_calloc.c ft_memcmp.c ft_strchr.c ft_strrchr.c ft_isalnum.c ft_memcpy.c ft_lstsize.c ft_lstlast.c ft_lstdelone.c ft_lstclear.c \
    ft_strdup.c ft_strtrim.c ft_isalpha.c ft_memmove.c ft_strjoin.c ft_substr.c ft_isascii.c ft_itoa.c ft_strmapi.c ft_lstadd_back.c ft_lstiter.c \
    ft_memset.c ft_strlcat.c ft_tolower.c ft_isdigit.c ft_putchar_fd.c ft_strlcpy.c ft_toupper.c ft_split.c ft_lstnew.c ft_lstadd_front.c \
    ft_isprint.c ft_putendl_fd.c ft_strlen.c ft_lstmap.c 

HEADER=libft.h

NAME=libft.a

OBJS=$(SRC:.c=.o)

$(NAME):
	@gcc -Wall -Wextra -Werror -I $(HEADER) -c $(SRC)
	@ar rcs $(NAME) $(OBJS)
	@echo "DEU CERTO!!!"

all: $(NAME)

clean:
	@rm -f $(OBJS)

fclean:clean
	@rm -f $(NAME)

re: fclean all
