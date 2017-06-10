#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/15 12:06:25 by gvandeve          #+#    #+#              #
#    Updated: 2017/06/10 14:07:34 by gvandeve         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	lem-in
DIRSRC		=	./srcs
INCLUDE		=	./includes
SRC			=	$(DIRSRC)/build.c \
	$(DIRSRC)/build2.c \
	$(DIRSRC)/build_way.c \
	$(DIRSRC)/calc.c \
	$(DIRSRC)/check.c \
	$(DIRSRC)/check2.c \
	$(DIRSRC)/format.c \
	$(DIRSRC)/format_way.c \
	$(DIRSRC)/free.c \
	$(DIRSRC)/init.c \
	$(DIRSRC)/lem_in.c \
	$(DIRSRC)/lst.c \
	$(DIRSRC)/manip_frm.c \
	$(DIRSRC)/proceed.c \
	$(DIRSRC)/utils.c \
	$(DIRSRC)/utils2.c
OBJ			=	build.o \
	build2.o \
	build_way.o \
	calc.o \
	check.o \
	check2.o \
	format.o \
	format_way.o \
	free.o \
	init.o \
	lem_in.o \
	lst.o \
	manip_frm.o \
	proceed.o \
	utils.o \
	utils2.o
LIB			=	libft/libftprintf.a
CFLAGS		=	-g -Wall -Wextra -Werror
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
