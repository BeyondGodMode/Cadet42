# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: beyondq <beyondq@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/06 09:25:36 by beyondq           #+#    #+#              #
#    Updated: 2025/03/06 09:25:36 by beyondq          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= so_long

LIBFT 			= ./libft/libft.a

CC 				= clang

STANDARD_FLAGS 	= -Wall -Werror -Wextra
MINILIBX_FLAGS	= -lmlx -lXext -lX11

VALGRIND		= @valgrind --leak-check=full --show-leak-kinds=all \
--track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes

REMOVE 			= rm -f

SRCS_DIR		= ./src/

SRCS 			= $(addprefix $(SRCS_DIR),\
				main.c						\
				init_map.c					\
				init_game.c					\
				ft_free.c					\
				ft_checkmap.c				\
				utils.c						\
				render.c					\
				ft_handle_input.c			\
				mlx_closing.c)


all:			${LIBFT} ${NAME}

${NAME}: 		
				${CC} ${SRCS} ${LIBFT} ${STANDARD_FLAGS} ${MINILIBX_FLAGS} -o ${NAME}
				@echo "$(NAME): $(NAME) was compiled."
				@echo

${LIBFT}:
				@echo
				make  -C libft

clean:
				make clean -C libft
				@echo

fclean:
				${REMOVE} ${NAME} ${LIBFT}
				@echo "${NAME}:${NAME} were deleted"
				@echo

re:				fclean all


.PHONY:			all clean fclean re valgrind
