CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SOURCE_FILES = ft_isprint.c ft_isascii.c ft_tolower.c ft_toupper.c ft_isalnum.c \
				ft_isalpha.c ft_isdigit.c ft_strrchr.c ft_strncmp.c ft_strchr.c \
				ft_atoi.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_strnstr.c \
				ft_strlcpy.c ft_strlcat.c ft_memmove.c ft_memchr.c ft_memcmp.c \
				ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c \
				ft_itoa.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
				ft_split.c ft_strmapi.c ft_striteri.c

OBJECT_FILES = $(SOURCE_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECT_FILES)
	ar rcs $(NAME) $(OBJECT_FILES)

.PHONY: clean all fclean re

clean:
	rm -f $(OBJECT_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all