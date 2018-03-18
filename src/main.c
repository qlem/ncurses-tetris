/*
** main.c for foo in /home/qlem/rendu
** 
** Made by qlem
** Login   <clement.dommerc@epitech.eu>
** 
** Started on  Thu Jul 13 03:09:54 2017 qlem
** Last update Fri Jul 14 17:56:27 2017 qlem
*/

#include "../inc/tetris.h"

void    init_main_struct(t_tetris *tetris)
{
    tetris->state = START;
    tetris->windows = malloc_windows_struct();
    tetris->terminal = malloc_terminal_struct();
    tetris->menu = malloc_pause_menu();
    tetris->v_game = malloc_var_game();
}

int	    main(void)
{
    t_tetris      tetris;

    srand((unsigned int)time(NULL));
    init_main_struct(&tetris);
    load_tetrimino(&tetris);
    save_initial_conf(&tetris);
    init_terminal();
    init_windows(&tetris);
    set_color();
    game_loop(&tetris);
    free_mem(&tetris);
    endwin();
    return (0);
}
