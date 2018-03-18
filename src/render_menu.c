//
// Created by qlem on 14/07/17.
//

#include "../inc/tetris.h"

void        render_sub_menu(t_tetris *tetris)
{
    int     i;
    int     x;
    int     y;

    i = -1;
    y = 7;
    x = MW_WIDTH / 2 - (int)strlen("color x") / 2;
    while (++i < tetris->menu->subm_color->nb_color)
    {
        wattron(tetris->windows->main_window, COLOR_PAIR(tetris->menu->subm_color->tab_color[i].color));
        if (tetris->menu->subm_color->p_index == i)
        {
            wattron(tetris->windows->main_window, A_REVERSE);
            mvwprintw(tetris->windows->main_window, y, x, tetris->menu->subm_color->tab_color[i].name);
            wattroff(tetris->windows->main_window, A_REVERSE);
        }
        else
            mvwprintw(tetris->windows->main_window, y, x, tetris->menu->subm_color->tab_color[i].name);
        wattroff(tetris->windows->main_window, COLOR_PAIR(tetris->menu->subm_color->tab_color[i].color));
        y++;
    }
}

void        render_menu(t_tetris *tetris)
{
    int         i;
    int         y;
    int         x;

    i = -1;
    y = 2;
    wclear(tetris->windows->main_window);
    render_sub_menu(tetris);
    while (++i < tetris->menu->nb_elem)
    {
        x = MW_WIDTH / 2 - (int)strlen(tetris->menu->tab_elem[i].name) / 2;
        if (tetris->menu->p_index == i && !tetris->menu->opt_color)
        {
            wattron(tetris->windows->main_window, A_BOLD);
            wattron(tetris->windows->main_window, COLOR_PAIR(3));
            mvwprintw(tetris->windows->main_window, y, x, tetris->menu->tab_elem[i].name);
            wattroff(tetris->windows->main_window, COLOR_PAIR(3));
            wattroff(tetris->windows->main_window, A_BOLD);
        }
        else
            mvwprintw(tetris->windows->main_window, y, x, tetris->menu->tab_elem[i].name);
        if (i == 1)
            y = 16;
        else
            y = 5;
    }
    wattron(tetris->windows->main_window, A_ITALIC);
    mvwprintw(tetris->windows->main_window, 20, 1, "Developed by");
    wattron(tetris->windows->main_window, A_BOLD);
    mvwprintw(tetris->windows->main_window, 20, 14, "qlem");
    wattroff(tetris->windows->main_window, A_BOLD);
    mvwprintw(tetris->windows->main_window, 20, 19, "- language C - July 2017");
    wattroff(tetris->windows->main_window, A_ITALIC);
    wrefresh(tetris->windows->main_window);
}