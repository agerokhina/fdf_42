NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/libft.a
SRC = ft_printf.c ft_my_prints.c ft_printf_helping.c ft_memfuncs.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@cp $(LIBFT) $(NAME)
	@ar -crs $(NAME) $(OBJ)
	@echo "Library $(NAME) created."

$(LIBFT): 
	$(MAKE) -C $(LIBFTDIR)
	$(MAKE) -C $(LIBFTDIR) clean

test: $(NAME)
	cc -Wall -Wextra -Werror ft_printf.c  $(NAME)
	./a.out

clean:
	@rm -f $(OBJ)
	@echo ">Object files cleaned."

fclean: clean
	@rm -f $(NAME) 
	$(MAKE) -C $(LIBFTDIR) fclean
	@echo "Library $(NAME) and object files cleaned."

re: fclean all

.PHONY: all clean fclean re test