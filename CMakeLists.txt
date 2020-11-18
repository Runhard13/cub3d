cmake_minimum_required(VERSION 3.12)
project(cub3d C)

set(CMAKE_C_STANDARD 99)
set(SOURCE_EXE  main.c player/hooks.c texture/drawing_utils.c parsing/map_parsing.c texture/tex_utils.c sprite/sprite_utils.c
        player/player_movement.c parsing/resolution_parsing.c parsing/path_parsing.c parsing/player_parsing.c parsing/color_parsing.c
        parsing/sprite_parsing.c game_config.c texture/tex_drawing.c sprite/sprite_drawing.c player/rays.c
        validation/exit.c validation/errors.c validation/map_check.c validation/map_check2.c validation/map_check3.c create_buffer.c)




add_executable(cub3d ${SOURCE_EXE})

target_link_libraries(cub3d
        /Users/cdrennan/Desktop/cub3d/libmlx.dylib
        "-framework OpenGL"
        "-framework AppKit"
        /Users/cdrennan/Desktop/cub3d/libft.a)