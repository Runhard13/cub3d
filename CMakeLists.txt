cmake_minimum_required(VERSION 3.12)
project(cub3d C)

set(CMAKE_C_STANDARD 99)
set(SOURCE_EXE  main.c map.c gnl/get_next_line.c hooks.c draw_player.c pars.c raycasting.c draw3d.c rounding.c)




add_executable(cub3d ${SOURCE_EXE})

target_link_libraries(cub3d
        /Users/cdrennan/Desktop/cub3d/libmlx.dylib
        "-framework OpenGL"
        "-framework AppKit"
        /Users/cdrennan/Desktop/cub3d/libft.a)