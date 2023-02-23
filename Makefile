# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pealexan <pealexan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/02 12:26:28 by pealexan          #+#    #+#              #
#    Updated: 2023/02/23 15:01:28 by pealexan         ###   ########.fr        #
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
		
BONUS_SRC = 

#--------COMMANDS--------#
CC = cc
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
		cd $(LIBFTDIR) && $(MAKE)

$(MLX):
		cd $(MLXDIR) && $(MAKE)
	
$(NAME): 	$(OBJ) $(LIBFT) $(MLX)
		$(CC) $(CFLAGS) $(OBJ) $(LIBFTDIR)$(LIBFT) $(MLXDIR)$(MLX) $(EXTRA) -o $(NAME)

bonus:		$(BONUS_OBJ) $(LIBFT)
		$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIBFTDIR)$(LIBFT) -o $(BONUS)

clean:
		@$(RM) $(OBJ) $(BONUS_OBJ)
		@cd $(LIBFTDIR) && $(MAKE) clean

fclean: 	clean
		@$(RM) $(NAME) $(BONUS) $(LIBFT)
		@cd $(LIBFTDIR) && $(MAKE) fclean
		@cd $(MLXDIR) && $(MAKE) clean
	
aclean: all clean

re: fclean all
