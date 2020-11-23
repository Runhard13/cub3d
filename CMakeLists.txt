cmake_minimum_required(VERSION 3.12)
project(cub3d C)

set(CMAKE_C_STANDARD 99)
set(SOURCE_EXE srcs/main.c srcs/player/hooks.c srcs/texture/drawing_utils.c srcs/parsing/map_parsing.c srcs/texture/tex_utils.c srcs/sprite/sprite_utils.c
        srcs/player/player_movement.c srcs/parsing/resolution_parsing.c srcs/parsing/path_parsing.c srcs/parsing/player_parsing.c srcs/parsing/color_parsing.c
        srcs/parsing/sprite_parsing.c srcs/utils/game_config.c srcs/texture/tex_drawing.c srcs/sprite/sprite_drawing.c srcs/player/rays.c
        srcs/validation/exit.c srcs/validation/errors.c srcs/validation/map_check.c srcs/validation/map_check2.c
        srcs/utils/screenshot.c srcs/utils/game_config2.c srcs/validation/map_check3.c)




add_executable(cub3d ${SOURCE_EXE})

target_link_libraries(cub3d
        /Users/cdrennan/Desktop/cub3d/libmlx.dylib
        "-framework OpenGL"
        "-framework AppKit"
        /Users/cdrennan/Desktop/cub3d/libft.a)