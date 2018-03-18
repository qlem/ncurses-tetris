//
// Created by qlem on 15/07/17.
//

#include "../inc/tetris.h"

double      delta_tab[10] = {
        1000000000.0,
        911111111.1111,
        822222222.2222,
        733333333.3333,
        644444444.4444,
        555555555.5555,
        466666666.6666,
        377777777.7777,
        288888888.8888,
        200000000.0
};

bool        get_timing(t_tetris *tetris)
{
    struct timespec     tp;
    double              now;
    double              delta;

    clock_gettime(CLOCK_REALTIME, &tp);
    now = (tp.tv_sec * BILLION) + tp.tv_nsec;
    if (tetris->v_game->level <= 9)
        delta = delta_tab[tetris->v_game->level];
    else
        delta = delta_tab[9];
    if (now - tetris->v_game->lvl_timer->ref > delta)
    {
        tetris->v_game->lvl_timer->ref = now;
        return (true);
    }
    return (false);
}

void        set_ref_time_lvl(t_tetris *tetris)
{
    struct timespec     tp;

    clock_gettime(CLOCK_REALTIME, &tp);
    tetris->v_game->lvl_timer->ref = (tp.tv_sec * BILLION) + tp.tv_nsec;
}

t_lvl_timer     *malloc_lvl_timer(void)
{
    t_lvl_timer     *lvl_timer;

    lvl_timer = malloc(sizeof(t_lvl_timer));
    if (lvl_timer == NULL)
        return (NULL);
    return (lvl_timer);
}