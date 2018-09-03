# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srheede <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/26 15:30:46 by srheede           #+#    #+#              #
#    Updated: 2018/08/24 16:52:14 by srheede          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = *.c

OBJ = $(SRCS:.c=.o)

FLAG = -Wall -Werror -Wextra

$(NAME):
	@gcc $(FLAG) $(addprefix srcs/, $(SRCS)) -L ../libft -lft -o $(NAME)
	@printf "\e[32m[✓] PUSH_SWAP COMPILED\n"
	@make -C ./ clean

.PHONY: all
all: $(NAME)

.PHONY:	clean
clean:
	@rm -f $(OBJ)
	@printf "\e[31m[✓] PUSH_SWAP OBJECT FILES REMOVED\n"

.PHONY:	fclean
fclean: clean
	@rm -f $(NAME)
	@printf "\e[31m[✓] PUSH_SWAP EXCECUTABLE REMOVED\n"

.PHONY:	re
re: fclean all
