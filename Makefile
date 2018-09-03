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

NAME = push_swap.checker

$(NAME):
	@make -C libft/
	@make -C checker/
	@make -C push_swap/
	@make -C visualizer/

.PHONY: all
all: $(NAME)

.PHONY:	clean
clean:
	@make -C libft/ clean
	@make -C checker/ clean
	@make -C push_swap/ clean
	@make -C visualizer/ clean

.PHONY:	fclean
fclean: clean
	@make -C libft/ fclean
	@make -C checker/ fclean
	@make -C push_swap/ fclean
	@make -C visualizer/ fclean

.PHONY:	re
re: fclean all