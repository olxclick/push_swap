# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbranco- <jbranco-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/21 15:30:00 by jbranco-          #+#    #+#              #
#    Updated: 2023/04/29 16:14:10 by jbranco-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c src/actions.c src/stack_org.c src/sort.c src/destroyer.c src/args_checker.c src/args_utils.c src/init_stack.c src/utils.c
OBJS = $(SRC:.c=.o)
CFLAGS =  -Wall -Wextra -Werror -fPIE
FT_PRINTF_A = ./ft_printf/libftprintf.a

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS) $(FT_PRINTF_A)
	cc $(CFLAGS) $(OBJS) -L. ./ft_printf/libftprintf.a -o $(NAME) 

$(FT_PRINTF_A):
	make -C ft_printf

clean:
	rm -rf $(OBJS) $(OBJS_BONUS)
	make clean -C ft_printf

fclean: clean
	rm -rf $(NAME) $(FT_PRINTF_A)
        
re: clean all
