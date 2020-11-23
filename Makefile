# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/03 22:13:29 by cdrennan          #+#    #+#              #
#    Updated: 2020/11/23 15:08:09 by cdrennan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= Cub3D

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror
LIBS	= -L libft/ -lft ${MLX_LNK}

INC		= -I srcs/ -I libft/ -I $(MLX_DIR)

OBJS	= ${SRCS:.c=.o}

SRCS	= srcs/main.c srcs/player/hooks.c srcs/texture/drawing_utils.c srcs/parsing/map_parsing.c srcs/texture/tex_utils.c srcs/sprite/sprite_utils.c\
                  srcs/player/player_movement.c srcs/parsing/resolution_parsing.c srcs/parsing/path_parsing.c srcs/parsing/player_parsing.c srcs/parsing/color_parsing.c\
                  srcs/parsing/sprite_parsing.c srcs/utils/game_config.c srcs/texture/tex_drawing.c srcs/sprite/sprite_drawing.c srcs/player/rays.c\
                  srcs/validation/exit.c srcs/validation/errors.c srcs/validation/map_check.c srcs/validation/map_check2.c\
                  srcs/utils/screenshot.c srcs/utils/game_config2.c srcs/validation/map_check3.c


MLX_DIR	= minilibx_mms_20200219
MLX_LNK	= -L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

${NAME}: $(OBJS) ft mlx
	@$(CC) $(CFLAGS) $(INC) $(OBJS) $(LIBS) -o $(NAME)

mlx:
	make -C $(MLX_DIR)

ft:
	make -C libft

all: ${NAME}

clean:
	rm -f $(OBJS)
	make clean -C libft

fclean: clean
	make fclean -C libft
	make clean -C $(MLX_DIR)
	rm -f ${NAME}

re: fclean all

run:
	./cub3D srcs/maps/map.cub

.PHONY: all clean fclean re  mlx ft