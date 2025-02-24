# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbenaali <bbenaali@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/01 15:41:04 by bbenaali          #+#    #+#              #
#    Updated: 2025/02/18 16:26:43 by bbenaali         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = fractol.c ft_strcmp.c for_open_window.c other_function.c parcing.c \
		ft_burning_ship.c other_function_partII.c

OBJC = ${SRC:.c=.o}

NAME = fractol

CC = cc

FLAGS = -Wall -Wextra -Werror

RM = rm -f

all: ${NAME}

${NAME}:${OBJC}
	${CC} ${FLAGS} $(OBJC) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o:%.c fractol.h
	${CC} ${FLAGS} -c $< -o $@

clean:
	${RM} ${OBJC}

fclean: clean
	${RM} ${NAME}

re: fclean all