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

NAME = visualizer

SRCS = *.c

OBJ = $(SRCS:.c=.o)

MLX = -L. -lmlx -framework OpenGL -framework APPKit

FLAG = -Wall -Werror -Wextra

$(NAME):
	@gcc $(FLAG) $(MLX) $(addprefix srcs/, $(SRCS)) -L ../libft -lft -o $(NAME)
	@printf "\e[32m[✓] VISUALIZER COMPILED\n"
	@make -C ./ clean

.PHONY: all
all: $(NAME)

.PHONY:	clean
clean:
	@rm -f $(OBJ)
	@printf "\e[31m[✓] VISUALIZER OBJECT FILES REMOVED\n"

.PHONY:	fclean
fclean: clean
	@rm -f $(NAME)
	@printf "\e[31m[✓] VISUALIZER EXCECUTABLE REMOVED\n"

.PHONY:	re
re: fclean all