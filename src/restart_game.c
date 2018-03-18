//
// Created by qlem on 18/07/17.
//

#include "../inc/tetris.h"

void        clear_grid(t_tetris *tetris)
{
    int     y;
    int     x;

    y = -1;
    while (++y < GRID_H)
    {
        x = -1;
        while (++x < GRID_W)
            tetris->v_game->grid[y][x] = -1;
    }
}

void    restart_game(t_tetris *tetris)
{
    clear_grid(tetris);
    tetris->v_game->c_tetri = NULL;
    tetris->v_game->n_tetri = NULL;
    tetris->v_game->c_tetri = get_tetrimino(tetris);
    tetris->v_game->n_tetri = get_tetrimino(tetris);
    set_ref_time(tetris);
    set_ref_time_lvl(tetris);
    tetris->v_game->score = 0;
    tetris->v_game->h_score = load_high_score();
    tetris->v_game->nb_lines = 0;
    tetris->v_game->level = 0;
    tetris->v_game->timer->sec = 0;
    tetris->v_game->timer->hour = 0;
    tetris->v_game->timer->min = 0;
}