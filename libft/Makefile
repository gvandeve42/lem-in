#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/22 19:11:41 by gvandeve          #+#    #+#              #
#    Updated: 2017/04/06 16:51:38 by gvandeve         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	=	libftprintf.a
SRCS	=	srcs/
INC		=	includes/
SRC		=	$(SRCS)ft_ans.c \
$(SRCS)ft_conv.c \
$(SRCS)ft_conv3.c \
$(SRCS)ft_d.c \
$(SRCS)ft_init_flags.c \
$(SRCS)ft_init_flags3.c \
$(SRCS)ft_printf.c \
$(SRCS)ft_utils.c \
$(SRCS)ft_utils3.c \
$(SRCS)ft_wstr.c \
$(SRCS)ft_c.c \
$(SRCS)ft_conv2.c \
$(SRCS)ft_conv4.c \
$(SRCS)ft_flags.c \
$(SRCS)ft_init_flags2.c \
$(SRCS)ft_o.c \
$(SRCS)ft_str.c \
$(SRCS)ft_utils2.c \
$(SRCS)ft_wcmask.c \
$(SRCS)ft_x.c \

OBJS	=	ft_ans.o \
ft_conv.o \
ft_conv3.o \
ft_d.o \
ft_init_flags.o \
ft_init_flags3.o \
ft_printf.o \
ft_utils.o \
ft_utils3.o \
ft_wstr.o \
ft_c.o \
ft_conv2.o \
ft_conv4.o \
ft_flags.o \
ft_init_flags2.o \
ft_o.o \
ft_str.o \
ft_utils2.o \
ft_wcmask.o \
ft_x.o \

COMP	=	gcc
FLAGS	=	-Wall -Wextra -Werror -g
GREEN	=	\033[32;1m
RED		=	\033[31;1m
ENDC	=	\033[0m

all: $(NAME)

$(NAME):
	@echo "[COMPILATION DE LA LIBFT] "
	@make -C libft/ re && echo "$(GREEN)[REUSSI]$(ENDC)" || echo "$(RED)[FAIL]$(ENDC)"
	@echo "[COMPILATION DU GNL]"
	@$(COMP) -c $(FLAGS) libft/get_next_line.c libft/ft_free_list.c -I $(INC) && echo "$(GREEN)[REUSSI]$(ENDC)" || echo "$(RED)[FAIL]$(ENDC)"
	@echo "[COMPILATION DE LA LIB PRINTF] "
	@$(COMP) -c $(FLAGS) $(SRC) -I $(INC) && echo "$(GREEN)[REUSSI]$(ENDC)" || echo "$(RED)[FAIL]$(ENDC)"
	@echo "[CREATION DE FT_PRINTF.A]"
	@ar r $(NAME) $(OBJS) libft/*.o get_next_line.o ft_free_list.o && echo "$(GREEN)[REUSSI]$(ENDC)" || echo "$(RED)[FAIL]$(ENDC)"
	@echo "[NETTOYAGE DU DOSSIER LIBFT]"
	@make -C libft/ fclean && echo "$(GREEN)[REUSSI]$(ENDC)" || echo "$(RED)[FAIL]$(ENDC)"

clean:
	@find . \( -name "#*#" -o -name "*~" \) -print -delete && echo "$(GREEN)[ECLEAN DONE]$(ENDC)" || echo "$(RED)[ECLEAN FAIL]$(ENDC)"
	rm -f $(OBJS) get_next_line.o ft_free_list.o

fclean: clean
	rm -f $(NAME)

re: fclean all
