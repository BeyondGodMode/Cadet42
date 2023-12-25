# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsongtra <tsongtra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/25 10:48:19 by tsongtra          #+#    #+#              #
#    Updated: 2023/12/25 11:21:43 by tsongtra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRCS	=	ft_printf.c \
			print_char.c \
			print_hex.c \
			print_int.c \
			print_percent.c \
			print_pointer.c \
			print_string.c \
			print_uint.c \

OBJS	=		$(SRCS:.c=.o)

CC	=		cc

RM	=		rm -f

CFLAGS =	-Wall -Wextra -Werror -I.

all	:		$(NAME)

$(NAME) :	$(OBJS)
			ar rcs $(NAME) $(OBJS)

clean :
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re :		fclean $(NAME)

.PHONY:			all clean fclean re
