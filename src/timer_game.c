//
// Created by qlem on 15/07/17.
//

#include "../inc/tetris.h"

void        update_timer(t_tetris *tetris)
{
    struct timespec     tp;
    time_t              diff;

    clock_gettime(CLOCK_REALTIME, &tp);
    diff = tp.tv_sec - tetris->v_game->timer->ref;
    if (tetris->v_game->timer->sec + diff > 59)
    {
        tetris->v_game->timer->sec = 0;
        if (tetris->v_game->timer->min + 1 > 59)
        {
            tetris->v_game->timer->min = 0;
            tetris->v_game->timer->hour++;
        }
        else
            tetris->v_game->timer->min++;
    }
    else
        tetris->v_game->timer->sec += diff;
    tetris->v_game->timer->ref = tp.tv_sec;
}

void        set_ref_time(t_tetris *tetris)
{
    struct timespec     tp;

    clock_gettime(CLOCK_REALTIME, &tp);
    tetris->v_game->timer->ref = tp.tv_sec;
}

t_timer     *malloc_timer(void)
{
    t_timer     *timer;

    timer = malloc(sizeof(t_timer));
    if (timer == NULL)
        return (NULL);
    timer->sec = 0;
    timer->min = 0;
    timer->hour = 0;
    timer->ref = 0;
    return (timer);
}

