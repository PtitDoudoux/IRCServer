cmake_minimum_required(VERSION 3.10)
project(irc_server C)

set(CMAKE_C_STANDARD 11)

add_executable(irc_server main.c includes/utils.h includes/user.h includes/commands.h modules/utils.c includes/room.h modules/room.c modules/user.c)