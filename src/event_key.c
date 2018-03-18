//
// Created by qlem on 14/07/17.
//

#include "../inc/tetris.h"

e_key       get_key_pressed(char *sequence)
{
    e_key       key;

    key = UNDEFINED;
    if (strcmp(tigetstr("kcud1"), sequence) == 0)
        key = DOWN;
    else if (strcmp(tigetstr("kcub1"), sequence) == 0)
        key = LEFT;
    else if (strcmp(tigetstr("kcuf1"), sequence) == 0)
        key = RIGHT;
    else if (strcmp(tigetstr("kcuu1"), sequence) == 0)
        key = UP;
    else if (strcmp("\e", sequence) == 0)
        key = ESCAPE;
    else if (strcmp(tigetstr("cr"), sequence) == 0)
        key = ENTER;
    else if (strcmp(sequence, "r") == 0 || strcmp(sequence, "R") == 0)
        key = RESTART;
    return (key);
}

e_key           key_event(void)
{
    char        *buffer;
    e_key       key;

    buffer = malloc(sizeof(char) * 10);
    memset(buffer, 0, 10);
    read(0, buffer, 10);
    if (buffer[0])
        key = get_key_pressed(buffer);
    else
        key = NO_PRESSED;
    free(buffer);
    return (key);
}