# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkoval <kkoval@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 14:51:08 by kkoval            #+#    #+#              #
#    Updated: 2024/04/15 19:01:34 by kkoval           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS_S = server.c utils.c
SRCS_C = client.c


OBJS_S = ${SRCS_S:.c=.o}
DEPS_S = ${SRCS_S:.c=.d}

OBJS_C = ${SRCS_C:.c=.o}
DEPS_C = ${SRCS_C:.c=.d}

HEADER = minitalk.h
INCS = -I./Libft
LIBS = -LLibft -lft

NAME_S = server
NAME_C = client

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -MMD #-g -fsanitize=address 

all: lib $(NAME_S) $(NAME_C)

lib:
	make -C ./Libft

${NAME_S}:	${OBJS_S} ./Libft/libft.a Makefile
	${CC} ${CFLAGS} ${LIBS} ${OBJS_S}  -o ${NAME_S}

${NAME_C}:	${OBJS_C} ./Libft/libft.a Makefile
	${CC} ${CFLAGS} ${LIBS} ${OBJS_C}  -o ${NAME_C}

%.o: %.c
	${CC} ${CFLAGS} ${INCS} -c $< -o $@

clean:
			${RM} ${OBJS_S} ${OBJS_C} ${DEPS_S} ${DEPS_C}
			make -C ./Libft clean



fclean:     clean
			${RM} ${NAME_S} ${NAME_C}
			make -C ./Libft fclean

re:         fclean all

-include $(DEPS_S) $(DEPS_C)
