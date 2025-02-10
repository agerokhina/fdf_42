LIB_PATH = ./lib
LIBMLX_PATH = ./lib/MLX42
BUILD_PATH = ./build
SRC_PATH = ./src
GNL_PATH = $(LIB_PATH)/gnl
NAME = fdf
CC = cc
CFLAGS = -I$(LIBMLX_PATH)/include -I./include -I/opt/homebrew/Cellar/glfw/3.4/include -Wall -Wextra -Werror -g # -fsanitize=address

# Указываем все исходные файлы
#SRC = $(wildcard $(SRC_PATH)/*.c)  $(wildcard $(GNL_PATH)/*.c) #$(SRC_PATH)/fdf.c $(SRC_PATH)/ft_fd.c $(SRC_PATH)/ft_graphics.c $(SRC_PATH)/ft_maps.c $(SRC_PATH)/ft_math.c  $(SRC_PATH)/ft_utils.c
SRC = $(SRC_PATH)/fdf.c \
						$(SRC_PATH)/fdf_fd.c \
						$(SRC_PATH)/fdf_free.c \
						$(SRC_PATH)/fdf_init.c \
						$(SRC_PATH)/fdf_graphics.c \
						$(SRC_PATH)/fdf_projections.c \
						$(SRC_PATH)/fdf_maps.c \
						$(SRC_PATH)/fdf_math.c \
						$(SRC_PATH)/fdf_utils.c \
						$(SRC_PATH)/fdf_hooks.c \
						$(SRC_PATH)/fdf_color.c \
						$(GNL_PATH)/get_next_line.c \
						$(GNL_PATH)/get_next_line_utils.c

OBJ = $(SRC:$(SRC_PATH)/%.c=$(BUILD_PATH)/%.o) #$(addprefix $(BUILD_PATH)/, $(notdir $(SRC:.c=.o)))
OBJ := $(OBJ:$(GNL_PATH)/%.c=$(BUILD_PATH)/%.o)

LIBFT = $(LIB_PATH)/libft/libft.a
PRINTFT = $(LIB_PATH)/ft_printf/libftprintf.a

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Darwin)
LIBMLX = $(LIBMLX_PATH)/build/libmlx42.a -lglfw -framework Cocoa -framework OpenGL -framework IOKit
else
LIBMLX = $(LIBMLX_PATH)/build/libmlx42.a -ldl -lglfw -pthread -lm
endif

all: $(NAME)

# Сборка основного исполняемого файла
$(NAME): $(OBJ) $(LIBFT) $(LIBMLX) $(PRINTFT) 
	$(CC)  $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTFT) $(LIBMLX) -o $(NAME)
	@echo "Project $(NAME) created."

# Создание объектных файлов
$(BUILD_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(BUILD_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_PATH)/%.o: $(GNL_PATH)/%.c
	@mkdir -p $(BUILD_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

# Сборка библиотеки MLX42
$(LIBMLX):
	@cmake -S $(LIBMLX_PATH) -B $(LIBMLX_PATH)/build && cmake --build $(LIBMLX_PATH)/build -j4

# Сборка libft
$(LIBFT):
	@$(MAKE) -C $(LIB_PATH)/libft OBJ_DIR=$(BUILD_PATH)

# Сборка ft_printf
$(PRINTFT):
	@$(MAKE) -C $(LIB_PATH)/ft_printf OBJ_DIR=$(BUILD_PATH)

clean:
	@rm -f $(OBJ)
	@rm -rf $(BUILD_PATH)
	@-$(MAKE) clean -C $(LIB_PATH)/libft || echo "libft clean skipped."
	@-$(MAKE) clean -C $(LIB_PATH)/ft_printf || echo "ft_printf clean skipped."
	@-$(MAKE) clean -C $(LIBMLX_PATH) || echo "MLX42 clean skipped."
	@echo "Object files and build directories cleaned."

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C $(LIB_PATH)/libft
	@$(MAKE) fclean -C $(LIB_PATH)/ft_printf

re: fclean all