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

# ==== Path ของ Libraries ====
LIBFT 			= ./libft/libft.a
MLX				= ./mlx/libmlx.a

# ==== Compiler และ Flags ====
CC 				= clang
CFLAGS 			= -Wall -Werror -Wextra -g3 -MMD -MP
MINILIBX_FLAGS	= -L mlx -lmlx -lXext -lX11

# ==== คำสั่งลบไฟล์ ====
REMOVE 			= rm -f

# ==== ไดเรกทอรีของไฟล์ต้นฉบับ และไฟล์ Object ====
SRCS_DIR		= ./src/
OBJ_DIR			= ./obj/

# ==== ไฟล์ต้นฉบับ ====
SRCS 			= main.c						\
				init_map.c					\
				init_game.c					\
				ft_free.c					\
				ft_checkmap.c				\
				utils.c						\
				render.c					\
				ft_handle_input.c			\
				floodfill.c					\
				mlx_closing.c

# ==== สร้าง Path ของไฟล์ Object ====
SRCS := $(addprefix $(SRCS_DIR), $(SRCS))
OBJS := $(SRCS:$(SRCS_DIR)%.c=$(OBJ_DIR)%.o)
DEPS := $(OBJS:.o=.d)  # ไฟล์ Dependency ที่สร้างจาก -MMD

# ==== Include Path ====
INCLUDES		= -I mlx -I libft -I src

# ==== สร้างไฟล์ Object ====
$(OBJ_DIR)%.o: $(SRCS_DIR)%.c
				@mkdir -p $(OBJ_DIR)
				$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# ==== คอมไพล์โปรแกรมหลัก ====
all:			${LIBFT} ${MLX} ${NAME}

${NAME}: 		${OBJS}
				${CC} ${OBJS} ${LIBFT} ${MLX} ${CFLAGS} ${MINILIBX_FLAGS} -o ${NAME}
				@echo "$(NAME): $(NAME) was compiled."
				@echo

# ==== คอมไพล์ Libft และ MLX ====
${LIBFT}:
				make -C libft

${MLX}:
				make -C mlx

# ==== คำสั่งลบไฟล์ ====
clean:
				make clean -C libft
				make clean -C mlx
				${REMOVE} -r ${OBJ_DIR}
				@echo "Object files cleaned."

fclean:			clean
				${REMOVE} ${NAME} ${LIBFT} ${MLX}
				@echo "Executable and libraries cleaned."

re:				fclean all

# ==== ใช้ไฟล์ .d สำหรับ Dependency Tracking ====
-include $(DEPS)

.PHONY:			all clean fclean re