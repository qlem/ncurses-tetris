//
// Created by qlem on 14/07/17.
//

#include "../inc/tetris.h"

int     init_windows(t_tetris *tetris)
{
    tetris->windows->main_window = newwin(MW_HEIGHT, MW_WIDTH, MW_Y, MW_X);
    tetris->windows->game_window = subwin(tetris->windows->main_window, GW_HEIGHT, GW_WIDTH, GW_Y, GW_X);
    tetris->windows->data_window = subwin(tetris->windows->main_window, DW_HEIGHT, DW_WIDTH, DW_Y, DW_X);
    tetris->windows->next_window = subwin(tetris->windows->main_window, NW_HEIGHT, NW_WIDTH, NW_X, NW_Y);
    // tetris->windows->debug_window = newwin(10, 20, 0, 50);
    return (0);
}

t_windows       *malloc_windows_struct(void)
{
    t_windows   *new;

    new = malloc(sizeof(t_windows));
    if (new == NULL)
        return (NULL);
    new->main_window = NULL;
    new->game_window = NULL;
    new->data_window = NULL;
    new->next_window = NULL;
    new->debug_window = NULL;
    return (new);
}