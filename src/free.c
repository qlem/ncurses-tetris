//
// Created by qlem on 19/07/17.
//

#include "../inc/tetris.h"

int         **free_grid(t_tetris *tetris)
{
    int     y;

    y = -1;
    while (++y < GRID_H)
        free(tetris->v_game->grid[y]);
    free(tetris->v_game->grid);
    return (0);
}

int         free_matrix(t_tetrimino *tetrimino)
{
    int     y;

    y = -1;
    while (++y < tetrimino->height)
        free(tetrimino->matrix[y]);
    free(tetrimino->matrix);
    return (0);
}

int         free_tetrimino_list(t_tetris *tetris)
{
    t_tetrimino     *tmp;
    t_tetrimino     *del;
    int             i;

    i = -1;
    tmp = tetris->v_game->l_tetri;
    while (++i < tetris->v_game->nb_tetri)
    {
        free_matrix(tmp);
        del = tmp;
        tmp = tmp->next;
        free(del);
    }
    return (0);
}

void            delete_windows(t_tetris *tetris)
{
    delwin(tetris->windows->next_window);
    delwin(tetris->windows->data_window);
    delwin(tetris->windows->game_window);
    delwin(tetris->windows->main_window);
}

int     free_mem(t_tetris *tetris)
{
    delete_windows(tetris);
    free(tetris->windows);
    free(tetris->terminal);
    free(tetris->menu->subm_color);
    free(tetris->menu);
    free_grid(tetris);
    free(tetris->v_game->timer);
    free(tetris->v_game->lvl_timer);
    free_tetrimino_list(tetris);
    free(tetris->v_game);
    return (0);
}