# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avieira <avieira@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/10 12:48:43 by avieira           #+#    #+#              #
#    Updated: 2019/11/14 18:18:43 by avieira          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ${wildcard *.c}
CC		= gcc
RM		= rm -f
NAME	= libftprintf.a
CTFLAGS	= -Wall -Werror -Wextra -I./includes
OBJS	= ${SRCS:.c=.o}

$(NAME):	${OBJS}
			ar rc ${NAME} $?
			ranlib ${NAME}

all:	$(NAME)

%.o: %.c
			$(CC) $(CTFLAGS) -c $^ -o $@

clean: 
			${RM} ${OBJS} ${OBJS_B}

fclean:		clean
			${RM} ${NAME} ${OBJS_B}

re:			fclean all

.PHONY:		all clean fclean re

