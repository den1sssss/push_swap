# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/12 21:53:10 by dshirely          #+#    #+#              #
#    Updated: 2022/03/12 21:53:11 by dshirely         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS=-Werror -Wextra -Wall
NAME=push_swap
SRC=*.c
INCLUDES=libft/libft.a

all:
	@make -C libft/ all
	@gcc $(SRC) -o $(NAME) $(FLAGS) $(INCLUDES) 

clean:
	@make -C libft/ clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re bonus