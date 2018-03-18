//
// Created by qlem on 15/07/17.
//

#include "../inc/tetris.h"

void        render_current_tetrimino(t_tetris *tetris)
{
    int     x;
    int     y;
    int     i;
    int     j;

    y = -1;
    i = tetris->v_game->c_tetri->position.s_y + 1;
    while (++y < tetris->v_game->c_tetri->height)
    {
        x = -1;
        j = tetris->v_game->c_tetri->position.s_x;
        while (++x < tetris->v_game->c_tetri->width)
        {
            if (tetris->v_game->c_tetri->matrix[y][x] != -1)
            {
                wattron(tetris->windows->game_window, A_REVERSE);
                wattron(tetris->windows->game_window, COLOR_PAIR(tetris->v_game->c_tetri->matrix[y][x]));
                mvwprintw(tetris->windows->game_window, i, j * 2 + 1, " ");
                mvwprintw(tetris->windows->game_window, i, j * 2 + 2, " ");
                wattroff(tetris->windows->game_window, COLOR_PAIR(tetris->v_game->c_tetri->matrix[y][x]));
                wattroff(tetris->windows->game_window, A_REVERSE);
            }
            j++;
        }
        i++;
    }
}

void        render_grid_only(t_tetris *tetris)
{
    int     x;
    int     y;

    y = -1;
    draw_border(tetris->windows->game_window, ' ',
                COLOR_PAIR(tetris->menu->subm_color->tab_color[tetris->menu->subm_color->p_index].color));
    while (++y < GRID_H)
    {
        x = -1;
        while (++x < GRID_W)
        {
            if (tetris->v_game->grid[y][x] != -1)
            {
                wattron(tetris->windows->game_window, A_REVERSE);
                wattron(tetris->windows->game_window, COLOR_PAIR(tetris->v_game->grid[y][x]));
                mvwprintw(tetris->windows->game_window, y + 1, x * 2 + 1, " ");
                mvwprintw(tetris->windows->game_window, y + 1, x * 2 + 2, " ");
                wattroff(tetris->windows->game_window, COLOR_PAIR(tetris->v_game->grid[y][x]));
                wattroff(tetris->windows->game_window, A_REVERSE);
            }
        }
    }
}

void        render_grid(t_tetris *tetris)
{
    wclear(tetris->windows->game_window);
    render_grid_only(tetris);
    if (tetris->state != OVER)
        render_current_tetrimino(tetris);
    wrefresh(tetris->windows->game_window);
}