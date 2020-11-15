# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/03 22:13:29 by cdrennan          #+#    #+#              #
#    Updated: 2020/11/14 20:03:42 by cdrennan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= Cub3D

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror
LIBS	= -L libft/ -lft ${MLX_LNK} -lm

INC		= -I . -I libft/ -I $(MLX_DIR)

OBJS	= ${SRCS:.c=.o}

SRCS	= main.c player/hooks.c texture/drawing_utils.c parsing/map_parsing.c texture/tex_utils.c sprite/sprite_utils.c \
 player/player_movement.c parsing/resolution_parsing.c parsing/path_parsing.c parsing/player_parsing.c parsing/color_parsing.c \
 parsing/sprite_parsing.c player/player_direction_init.c game_config.c texture/tex_drawing.c sprite/sprite_drawing.c \
 player/rays.c validation/exit.c validation/errors.c validation/map_check.c validation/map_check2.c

MLX_DIR	= minilibx_mms_20200219
MLX_LNK	= -L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) $(INC)

${NAME}: $(OBJS) ft mlx
	${CC} ${CFLAGS} ${INC} ${OBJS} ${LIBS} -o ${NAME}

mlx:
	make -C $(MLX_DIR)

ft:
	make -C libft

all: ${NAME}

clean:
	rm -f $(OBJS)

fclean: clean
	make fclean -C libft
	make clean -C $(MLX_DIR)
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus mlx ft