##
## Makefile for tetris in /home/qlem/rendu/tetris
## 
## Made by qlem
## Login   <clement.dommerc@epitech.eu>
## 
## Started on  Fri Jul 14 17:48:28 2017 qlem
## Last update Mon Nov  6 00:07:38 2017 qlem
##

NAME		:=	tetris

CC		:=	gcc

RM		:=	rm -f

CFLAGS		:=	-W -Wextra -Wall -Werror ## -ansi -pedantic

SRC_DIR		:=	src
OBJ_DIR		:=	obj
INC_DIR		:=	inc

SRC		:=	check_rotate.c		\
			color.c			\
			debug.c			\
			event_game.c		\
			event_key.c		\
			event_menu.c		\
			free.c			\
			game_loop.c		\
			get_tetrimino.c		\
			init_menu.c		\
			init_terminal.c		\
			init_tetrimino_1.c	\
			init_tetrimino_2.c	\
			init_var_game.c		\
			init_windows.c		\
			int_to_str_1.c		\
			int_to_str_2.c		\
			load_tetrimino.c	\
			main.c			\
			move_down.c		\
			move_left.c		\
			move_right.c		\
			render_game_1.c		\
			render_menu.c		\
			render_over.c		\
			render_start.c		\
			render_game_2.c		\
			restart_game.c		\
			rotate.c		\
			score.c			\
			timer_game.c		\
			timer_lvl.c
SRC		:=	$(addprefix $(SRC_DIR)/, $(SRC))

OBJ		:=	$(SRC:.c=.o)
OBJ		:=	$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

$(OBJ_DIR)/%.o:		$(SRC_DIR)/%.c
	$(CC) -c $(CFLAGS) $< -o $@

all:		$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) -lncurses

clean:
		$(RM) src/*~ obj/*~ inc/*~ *~
		$(RM) src/#*# obj/#* inc/#*# #*#
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
