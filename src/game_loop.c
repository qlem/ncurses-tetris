//
// Created by qlem on 14/07/17.
//

#include "../inc/tetris.h"

void        over_event(t_tetris *tetris, e_key key)
{
    if (tetris->v_game->score > tetris->v_game->h_score)
        write_new_high_score(tetris->v_game->score);
    if (key == ESCAPE)
        tetris->state = QUIT;
    else if (key == RESTART)
    {
        wclear(tetris->windows->main_window);
        wrefresh(tetris->windows->main_window);
        restart_game(tetris);
        tetris->state = GAME;
    }
    if (tetris->state == OVER)
        render_end(tetris);
}

void        start_event(t_tetris *tetris, e_key key)
{
    if (key != NO_PRESSED)
    {
        wclear(tetris->windows->main_window);
        wrefresh(tetris->windows->main_window);
        tetris->state = GAME;
        set_ref_time(tetris);
        set_ref_time_lvl(tetris);
    }
    if (tetris->state == START)
        render_start(tetris);
}

void        game_event(t_tetris *tetris, e_key key)
{
    update_timer(tetris);
    if (get_timing(tetris))
    {
        if (!move_down(tetris))
        {
            tetrimino_on_board(tetris);
            check_lines(tetris);
            tetris->v_game->c_tetri = tetris->v_game->n_tetri;
            tetris->v_game->n_tetri = get_tetrimino(tetris);
            if (is_game_over(tetris))
                tetris->state = OVER;
        }
    }
    if (key == ESCAPE)
        tetris->state = MENU;
    else if (key == UP)
        rotate(tetris);
    else if (key == DOWN)
    {
        if (move_down(tetris) && tetris->v_game->score < 999999)
            tetris->v_game->score++;
    }
    else if (key == LEFT)
        move_left(tetris);
    else if (key == RIGHT)
        move_right(tetris);
    render_game(tetris);
}

int     game_loop(t_tetris *tetris)
{
    e_key       key;

    set_noncanonical_mode(tetris);
    tetris->v_game->c_tetri = get_tetrimino(tetris);
    tetris->v_game->n_tetri = get_tetrimino(tetris);
    while (tetris->state != QUIT)
    {
        key = key_event();
        if (tetris->state == START)
            start_event(tetris, key);
        else if (tetris->state == GAME)
            game_event(tetris, key);
        else if (tetris->state == MENU)
            menu_event(tetris, key);
        else if (tetris->state == OVER)
            over_event(tetris, key);
    }
    return (0);
}