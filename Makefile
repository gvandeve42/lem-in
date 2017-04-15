#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/15 12:06:25 by gvandeve          #+#    #+#              #
#    Updated: 2017/04/15 12:08:33 by gvandeve         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	lem-in
DIRSRC		=	./srcs
INCLUDE		=	./includes
SRC			=	$(DIRSRC)/*.c
OBJ			=	*.o
LIB			=	libft/libftprintf.a
CFLAGS		=	-Wall -Wextra -Werror
CC			=	gcc

all: $(NAME)

$(NAME):
	@make -C libft re
	@$(CC) -c $(FLAGS) $(SRC) -I $(INCLUDE)
	@$(CC) -g $(FLAGS) -o $(NAME) $(OBJ) $(LIB)
	@make -C libft fclean

clean:
	@find . \( -name "#*#" -o -name "*~" \) -print -delete
	@rm -rf $(OBJ)
	@rm -f filler.trace

fclean: clean
	@rm -f $(NAME)

re: fclean all
