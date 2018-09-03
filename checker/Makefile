# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srheede <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/26 15:30:46 by srheede           #+#    #+#              #
#    Updated: 2018/07/27 11:38:27 by srheede          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

SRCS = main.c read.c run_op1.c run_op2.c run_op3.c error.c

OBJ = $(SRCS:.c=.o)

FLAG = -Wall -Werror -Wextra

$(NAME):
	@gcc $(FLAG) $(addprefix srcs/, $(SRCS)) -L ../libft -lft -o $(NAME)
	@printf "\e[32m[✓] CHECKER COMPILED\n"
	@make -C ./ clean

.PHONY: all
all: $(NAME)

.PHONY:	clean
clean:
	@rm -f $(OBJ)
	@printf "\e[31m[✓] CHECKER OBJECT FILES REMOVED\n"

.PHONY:	fclean
fclean: clean
	@rm -f $(NAME)
	@printf "\e[31m[✓] CHECKER EXCECUTABLE REMOVED\n"

.PHONY:	re
re: fclean all