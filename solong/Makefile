# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/28 20:37:12 by acesar-l          #+#    #+#              #
#    Updated: 2022/07/14 19:14:16 by acesar-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= so_long
NAME_BONUS		= so_long_bonus

LIBFT 			= ./libft/libft.a

CC 				= clang

STANDARD_FLAGS 	= -Wall -Werror -Wextra
MINILIBX_FLAGS	= -lmlx -lXext -lX11

VALGRIND		= @valgrind --leak-check=full --show-leak-kinds=all \
--track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes

REMOVE 			= rm -f

SRCS_DIR		= ./src/
# BONUS_SRCS_DIR	= ./srcbonus/

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

# SRCS_BONUS 		= $(addprefix $(BONUS_SRCS_DIR),\
# 				so_long_bonus.c				\
# 				ft_check_map_bonus.c		\
# 				ft_close_game_bonus.c		\
# 				ft_free_memory_bonus.c		\
# 				ft_handle_input_bonus.c		\
# 				ft_init_game_bonus.c		\
# 				ft_init_map_bonus.c			\
# 				ft_render_map_bonus.c		\
# 				ft_utils_bonus.c)

all:			${LIBFT} ${NAME}

${NAME}: 		
				${CC} ${SRCS} ${LIBFT} ${STANDARD_FLAGS} ${MINILIBX_FLAGS} -o ${NAME}
				@echo "$(NAME): $(GREEN)$(NAME) was compiled.$(RESET)"
				@echo

# bonus:			${LIBFT} ${NAME_BONUS}

# ${NAME_BONUS}:		
# 				${CC} ${SRCS_BONUS} ${LIBFT} ${STANDARD_FLAGS} ${MINILIBX_FLAGS} -o ${NAME_BONUS}
# 				@echo "\n$(NAME): $(GREEN)$(NAME) was compiled with Bonus.$(RESET)"
# 				@echo

${LIBFT}:
				@echo
				make  -C libft

clean:
				make clean -C libft
				@echo

fclean:
				${REMOVE} ${NAME} ${NAME_BONUS} ${LIBFT}
				@echo "${NAME}: ${RED}${NAME} and ${NAME_BONUS} were deleted${RESET}"
				@echo

re:				fclean all

# rebonus:		fclean ${NAME_BONUS}

run:			${NAME}
				${VALGRIND} ./${NAME} assets/maps/valid/map4.ber

# run_bonus:		${NAME_BONUS}
# 				${VALGRIND} ./${NAME_BONUS} assets/maps/valid/bonus/map5.ber

.PHONY:			all clean fclean re rebonus valgrind run run_bonus
