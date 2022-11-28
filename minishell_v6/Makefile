# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eryilmaz <eryilmaz@student.42kocaeli.com.  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 16:32:59 by eryilmaz          #+#    #+#              #
#    Updated: 2022/10/17 16:33:05 by eryilmaz         ###   ########.tr        #
#                                                                              #
# **************************************************************************** #

NAME	:= minishell
CC		:= gcc
CFLAGS	:= -Wall -Werror -Wextra -I /goinfre/homebrew/opt/readline/include
FILES	:= $(wildcard *.c ./built-in/*.c ./command_process/*.c ./function_process/*.c ./pipe/*.c ./redirect/*.c ./syntax_control/*.c)
OBJ		:= $(FILES:%.c=%.o)
LIBFT	:= ./libft/libft.a

all : $(NAME)

$(NAME) : $(OBJ) makediff
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LIBFT) -lreadline -L /goinfre/homebrew/opt/readline/lib
makediff :
	@make bonus -C libft

clear : go
	@make clean -C libft

go :
	@rm -rf *.o
	@rm -rf ./built-in/*.o
	@rm -rf  ./command_process/*.o
	@rm -rf  ./function_process/*.o
	@rm -rf  ./pipe/*.o
	@rm -rf  ./redirect/*.o
	@rm -rf  ./syntax_control/*.o

fclean : clear
	@make fclean -C libft
	@rm -rf $(NAME)
re : fclean all

.PHONY : all run makediff clear fclean re go
