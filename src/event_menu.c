//
// Created by qlem on 14/07/17.
//

#include "../inc/tetris.h"

void        up_event(t_tetris *tetris)
{
    if (tetris->menu->opt_color)
    {
        if (tetris->menu->subm_color->p_index == 0)
            tetris->menu->subm_color->p_index = tetris->menu->subm_color->nb_color - 1;
        else
            tetris->menu->subm_color->p_index--;
    }
    else
    {
        if (tetris->menu->p_index == 0)
            tetris->menu->p_index = tetris->menu->nb_elem - 1;
        else
            tetris->menu->p_index--;
    }
}

void        down_event(t_tetris *tetris)
{
    if (tetris->menu->opt_color)
    {
        if (tetris->menu->subm_color->p_index == tetris->menu->subm_color->nb_color - 1)
            tetris->menu->subm_color->p_index = 0;
        else
            tetris->menu->subm_color->p_index++;
    }
    else
    {
        if (tetris->menu->p_index == tetris->menu->nb_elem - 1)
            tetris->menu->p_index = 0;
        else
            tetris->menu->p_index++;
    }
}

void        enter_event(t_tetris *tetris)
{
    if (tetris->menu->tab_elem[tetris->menu->p_index].id == 0)
    {
        wclear(tetris->windows->main_window);
        wrefresh(tetris->windows->main_window);
        set_ref_time(tetris);
        set_ref_time_lvl(tetris);
        tetris->state = GAME;
    }
    else if (tetris->menu->tab_elem[tetris->menu->p_index].id == 1 && !tetris->menu->opt_color)
        tetris->menu->opt_color = true;
    else if (tetris->menu->tab_elem[tetris->menu->p_index].id == 1 && tetris->menu->opt_color)
        tetris->menu->opt_color = false;
    else if (tetris->menu->tab_elem[tetris->menu->p_index].id == 2)
        tetris->state = QUIT;
}

void        menu_event(t_tetris *tetris, e_key key)
{
    if (key == UP)
        up_event(tetris);
    else if (key == DOWN)
        down_event(tetris);
    else if (key == ENTER)
        enter_event(tetris);
    else if (key == ESCAPE && !tetris->menu->opt_color)
    {
        tetris->menu->p_index = 0;
        set_ref_time(tetris);
        set_ref_time_lvl(tetris);
        wclear(tetris->windows->main_window);
        wrefresh(tetris->windows->main_window);
        tetris->state = GAME;
    }
    if (tetris->state == MENU)
        render_menu(tetris);
}