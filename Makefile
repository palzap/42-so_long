# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/02 12:26:28 by pealexan          #+#    #+#              #
#    Updated: 2023/02/02 12:26:30 by pealexan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
BONUS		= so_long_bonus
LIBFT		= libft.a

#----------DIRS----------#
SRCDIR = ./src/
LIBFTDIR = ./libft/
HEADERDIR = ./headers/

SRC = 
		
BONUS_SRC = 

#--------COMMANDS--------#
CC = cc
CFLAGS = -Wall -Wextra -Werror
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
	
$(NAME): 	$(OBJ) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJ) $(LIBFTDIR)$(LIBFT) -o $(NAME)

bonus:		$(BONUS_OBJ) $(LIBFT)
		$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIBFTDIR)$(LIBFT) -o $(BONUS)

clean:
		@$(RM) $(OBJ) $(BONUS_OBJ)
		@cd $(LIBFTDIR) && $(MAKE) clean

fclean: 	clean
		@$(RM) $(NAME) $(BONUS) $(LIBFT)
		@cd $(LIBFTDIR) && $(MAKE) fclean
	
aclean: all clean

re: fclean all
