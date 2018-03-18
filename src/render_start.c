//
// Created by qlem on 14/07/17.
//

#include "../inc/tetris.h"

/*

 ___________________  ________
/_  __/ __/_  __/ _ \/  _/ __/
 / / / _/  / / / , _// /_\ \
/_/ /___/ /_/ /_/|_/___/___/

*/


void        render_start(t_tetris *tetris)
{
    wclear(tetris->windows->main_window);
    wattron(tetris->windows->main_window, COLOR_PAIR(3));
    mvwprintw(tetris->windows->main_window, 9, 7, " ___________________  ________");
    mvwprintw(tetris->windows->main_window, 10, 7, "/_  __/ __/_  __/ _ \\/  _/ __/");
    mvwprintw(tetris->windows->main_window, 11, 7, " / / / _/  / / / , _// /_\\ \\");
    mvwprintw(tetris->windows->main_window, 12, 7, "/_/ /___/ /_/ /_/|_/___/___/");
    wattroff(tetris->windows->main_window, COLOR_PAIR(3));
    wattron(tetris->windows->main_window, A_ITALIC);
    mvwprintw(tetris->windows->main_window, 20, 13, "Press key to start");
    wattroff(tetris->windows->main_window, A_ITALIC);
    wrefresh(tetris->windows->main_window);
}
