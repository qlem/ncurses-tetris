//
// Created by qlem on 14/07/17.
//

#include "../inc/tetris.h"

void    save_initial_conf(t_tetris *tetris)
{
    tcgetattr(fileno(stdin), &tetris->terminal->initial_conf);
}

void    reset_mode(t_tetris *tetris)
{
    tcsetattr(fileno(stdin),  TCSANOW, &tetris->terminal->initial_conf);
}

void        set_noncanonical_mode(t_tetris *tetris)
{
    struct termios      ncanonical;

    tcgetattr(fileno(stdin), &ncanonical);
    ncanonical.c_lflag &= ~ICANON;
    ncanonical.c_lflag &= ~ECHO;
    ncanonical.c_cc[VMIN] = 0;
    ncanonical.c_cc[VTIME] = 1;
    tcsetattr(fileno(stdin),  TCSANOW, &ncanonical);
    tetris->terminal->current_mode = NONCANONICAL;
}

t_terminal      *malloc_terminal_struct(void)
{
    t_terminal      *new;

    new = malloc(sizeof(t_terminal));
    if (new == NULL)
        return (NULL);
    new->current_mode = CANONICAL;
    return (new);
}

int     init_terminal(void)
{
    int     error;

    setupterm(NULL, fileno(stdout), &error);
    initscr();
    start_color();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    return (0);
}