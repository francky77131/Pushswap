# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frgojard <frgojard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/14 14:20:55 by frgojard          #+#    #+#              #
#    Updated: 2022/10/19 11:13:16 by frgojard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

CFLAGS = -Wall -g3 -Wextra -Werror

RM = rm -f

LIBFT = ./libft/libft.a

SRC =	main.c \
		check_error.c \
		move.c \
		lst_swap.c \
		lst_rotate.c \
		lst_reverse_rotate.c \
		lst_push.c \
		attribute.c \
		utils.c \
		do_cheap_move.c
		

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(LIBFT) $(OBJ)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ) -L./libft -lft

$(LIBFT) :
	make -C libft
		
.c.o:
	$(CC) $(CFLAGS) -o $@ -c $< -I . -I libft

random_100 :
	seq 1 100 | sort -R | tr "\n" " "; echo

random_500 :
	seq 1 500 | sort -R | tr "\n" " "; echo
test5 : $(NAME)
	$(eval ARG = $(shell shuf -i 0-1000 -n 5))
		./push_swap $(ARG) | ./checker_linux $(ARG)
		@echo -n "Instructions: "
		@./push_swap $(ARG) | wc -l
test100 : $(NAME)
	$(eval ARG = $(shell shuf -i 0-1000 -n 100))
		./push_swap $(ARG) | ./checker_linux $(ARG)
		@echo -n "Instructions: "
		@./push_swap $(ARG) | wc -l

test500 : $(NAME)
	$(eval ARG = $(shell shuf -i 0-2000 -n 500))
		./push_swap $(ARG) | ./checker_linux $(ARG)
		@echo -n "Instructions: "
		@./push_swap $(ARG) | wc -l

clean:
	$(RM) $(OBJ)
	make clean -C libft

fclean:	clean
	$(RM) $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
