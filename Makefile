# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/02 12:26:28 by pealexan          #+#    #+#              #
#    Updated: 2023/02/25 03:12:52 by pealexan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
BONUS		= so_long_bonus
LIBFT		= libft.a
MLX		= libmlx_Linux.a

#----------DIRS----------#
SRCDIR = ./src/
LIBFTDIR = ./libft/
MLXDIR = ./minilibx-linux/
HEADERDIR = ./headers/

SRC = 	src/free.c \
		src/graphics.c \
		src/map.c \
		src/path.c \
		src/so_long.c \
		
BONUS_SRC = src_bonus/animation_bonus.c \
			src_bonus/free_bonus.c \
			src_bonus/graphics_bonus.c \
			src_bonus/hostile_bonus.c \
			src_bonus/map_bonus.c \
			src_bonus/path_bonus.c \
			src_bonus/player_bonus.c \
			src_bonus/so_long_bonus.c \

#--------COMMANDS--------#
CC = clang
CFLAGS = -Wall -Wextra -Werror
EXTRA = -lXext -lX11
AR = ar rcs
RM = rm -rf

OBJ = ${SRC:.c=.o}
BONUS_OBJ = ${BONUS_SRC:.c=.o}

#---------RULES---------#
.c.o:
			$(CC) $(CFLAGS) -c -I$(HEADERDIR) $< -o ${<:.c=.o}

all: 		$(NAME)

$(LIBFT):
			@$(MAKE) -C $(LIBFTDIR)

$(MLX):
			@$(MAKE) -C $(MLXDIR)
	
$(NAME): 	$(OBJ) $(LIBFT) $(MLX)
			$(CC) $(CFLAGS) $(OBJ) $(LIBFTDIR)$(LIBFT) $(MLXDIR)$(MLX) $(EXTRA) -o $(NAME)

bonus:		$(BONUS_OBJ) $(LIBFT) $(MLX)
			$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIBFTDIR)$(LIBFT) $(MLXDIR)$(MLX) $(EXTRA) -o $(BONUS)

clean:
			@$(RM) $(OBJ) $(BONUS_OBJ)
			@cd $(LIBFTDIR) && $(MAKE) clean

fclean: 	clean
			@$(RM) $(NAME) $(BONUS) $(LIBFT)
			@cd $(LIBFTDIR) && $(MAKE) fclean
			@cd $(MLXDIR) && $(MAKE) clean
	
aclean: all clean

re: fclean all
