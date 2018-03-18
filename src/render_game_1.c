//
// Created by qlem on 14/07/17.
//

#include "../inc/tetris.h"

void        draw_border(WINDOW *win, chtype c, int color_pair)
{
    wattron(win, A_REVERSE);
    wattron(win, color_pair);
    wborder(win, c, c, c, c, c, c, c, c);
    wattroff(win, color_pair);
    wattroff(win, A_REVERSE);
}

void        render_data(t_tetris *tetris)
{
    wclear(tetris->windows->data_window);
    mvwprintw(tetris->windows->data_window, 1, 2, "Timer");
    mvwprintw(tetris->windows->data_window, 3, 2, "Score");
    mvwprintw(tetris->windows->data_window, 5, 2, "Level");
    mvwprintw(tetris->windows->data_window, 7, 2, "Lines");
    mvwprintw(tetris->windows->data_window, 9, 2, "H. score");
    wattron(tetris->windows->data_window, A_BOLD);
    mvwprintw(tetris->windows->data_window, 1, 12, "%02d:%02d:%02d",
              tetris->v_game->timer->hour, tetris->v_game->timer->min, tetris->v_game->timer->sec);
    mvwprintw(tetris->windows->data_window, 3, 14, "%6d", tetris->v_game->score);
    mvwprintw(tetris->windows->data_window, 5, 14, "%6d", tetris->v_game->level);
    mvwprintw(tetris->windows->data_window, 7, 14, "%6d", tetris->v_game->nb_lines);
    mvwprintw(tetris->windows->data_window, 9, 14, "%6d", tetris->v_game->h_score);
    wattroff(tetris->windows->data_window, A_BOLD);
    wrefresh(tetris->windows->data_window);
}

void        render_next(t_tetris *tetris)
{
    int     x;
    int     y;
    int     i;
    int     j;

    y = -1;
    wclear(tetris->windows->next_window);
    draw_border(tetris->windows->next_window, ' ',
                COLOR_PAIR(tetris->menu->subm_color->tab_color[tetris->menu->subm_color->p_index].color));
    i = 5 - tetris->v_game->n_tetri->height / 2;
    while (++y < tetris->v_game->n_tetri->height)
    {
        x = -1;
        j = tetris->v_game->n_tetri->position.s_x;
        while (++x < tetris->v_game->n_tetri->width)
        {
            if (tetris->v_game->n_tetri->matrix[y][x] != -1)
            {
                wattron(tetris->windows->next_window, A_REVERSE);
                wattron(tetris->windows->next_window, COLOR_PAIR(tetris->v_game->n_tetri->matrix[y][x]));
                mvwprintw(tetris->windows->next_window, i, j * 2 + 1, " ");
                mvwprintw(tetris->windows->next_window, i, j * 2 + 2, " ");
                wattroff(tetris->windows->next_window, COLOR_PAIR(tetris->v_game->n_tetri->matrix[y][x]));
                wattroff(tetris->windows->next_window, A_REVERSE);
            }
            j++;
        }
        i++;
    }
    wrefresh(tetris->windows->next_window);
}

void            render_game(t_tetris *tetris)
{
    render_grid(tetris);
    render_next(tetris);
    render_data(tetris);
}