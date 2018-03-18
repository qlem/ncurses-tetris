//
// Created by qlem on 15/07/17.
//

#include "../inc/tetris.h"

void        adjust_score_level(t_tetris *tetris, int nb_lines)
{
    if (nb_lines == 1)
        tetris->v_game->score += 40 * (tetris->v_game->level + 1);
    else if (nb_lines == 2)
        tetris->v_game->score += 100 * (tetris->v_game->level + 1);
    else if (nb_lines == 3)
        tetris->v_game->score += 300 * (tetris->v_game->level + 1);
    else if (nb_lines == 4)
        tetris->v_game->score += 1200 * (tetris->v_game->level + 1);
    if (tetris->v_game->score > 999999)
        tetris->v_game->score = 999999;
    if ((tetris->v_game->nb_lines % 10) + nb_lines >= 10)
        tetris->v_game->level++;
}

void        remove_line(t_tetris *tetris, int y)
{
    int     x;

    while (y > 0)
    {
        x = -1;
        while (++x < GRID_W)
        {
            tetris->v_game->grid[y][x] = tetris->v_game->grid[y - 1][x];
            if (y == 1)
                tetris->v_game->grid[y - 1][x] = -1;
        }
        y--;
    }
}

void        check_lines(t_tetris *tetris)
{
    int     y;
    int     x;
    int     count;
    int     nb_lines;

    nb_lines = 0;
    y = GRID_H;
    while (--y >= 0)
    {
        x =  -1;
        count = 0;
        while (++x < GRID_W)
        {
            if (tetris->v_game->grid[y][x] != -1)
                count++;
        }
        if (count == 10)
        {
            remove_line(tetris, y);
            nb_lines++;
            y++;
        }
    }
    if (nb_lines > 0)
    {
        adjust_score_level(tetris, nb_lines);
        tetris->v_game->nb_lines += nb_lines;
    }
}

bool        is_game_over(t_tetris *tetris)
{
    t_tetrimino     *tmp;
    int             y;
    int             x;
    int             i;
    int             j;

    tmp = tetris->v_game->c_tetri;
    i = 0;
    y = tmp->position.s_y - 1;
    while (++y <= tmp->position.e_y)
    {
        j = 0;
        x = tmp->position.s_x - 1;
        while (++x <= tmp->position.e_x)
        {
            if (tmp->matrix[i][j] != -1 && tetris->v_game->grid[y][x] != -1)
                return (true);
            j++;
        }
        i++;
    }
    return (false);
}

void        tetrimino_on_board(t_tetris *tetris)
{
    t_tetrimino     *tmp;
    int             y;
    int             x;
    int             i;
    int             j;

    tmp = tetris->v_game->c_tetri;
    i = 0;
    y = tmp->position.s_y - 1;
    while (++y <= tmp->position.e_y)
    {
        j = 0;
        x = tmp->position.s_x - 1;
        while (++x <= tmp->position.e_x)
        {
            if (tmp->matrix[i][j] != -1)
                tetris->v_game->grid[y][x] = tmp->matrix[i][j];
            j++;
        }
        i++;
    }
}