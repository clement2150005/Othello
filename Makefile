# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/14 16:24:52 by ccolin            #+#    #+#              #
#    Updated: 2024/09/14 16:29:57 by ccolin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= Othello

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -Iincludes #-fsanitize=address

MLX_DIR	= minilibx_opengl_20191021
MLX_LIB	= $(MLX_DIR)/libmlx.a
MLX_INC	= -I$(MLX_DIR)
MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
LIBFT_INC = -I$(LIBFT_DIR) -I$(LIBFT_DIR)/includes

SRC_DIR	= src
SRCS	= $(wildcard $(SRC_DIR)/*.c)

OBJS	= $(SRCS:.c=.o)

RM		= rm -f

%.o: %.c
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) $(MLX_INC) $(LIBFT_INC) -c $< -o $@

$(NAME): $(MLX_LIB) $(LIBFT_LIB) $(OBJS)
	@echo "Linking $(NAME)..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_LIB) $(LIBFT_LIB) $(MLX_FLAGS)

$(LIBFT_LIB):
	@echo "Compiling libft..."
	@make -C $(LIBFT_DIR) --silent

$(MLX_LIB):
	@echo "Compiling MiniLibX..."
	@make -C $(MLX_DIR) CFLAGS=-w --silent

all: $(NAME)

clean:
	@echo "Cleaning object files..."
	@$(RM) $(OBJS)
	@make clean -C $(LIBFT_DIR) --silent
	@make clean -C $(MLX_DIR) --silent

fclean: clean
	@echo "Removing $(NAME)..."
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT_DIR) --silent
	@make clean -C $(MLX_DIR) --silent

re: fclean all

.PHONY: all clean fclean re
