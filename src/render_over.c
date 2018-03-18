//
// Created by qlem on 14/07/17.
//

#include "../inc/tetris.h"

/*

  _____
 / ___/__  __ _  ___
/ (_ / _ `/  ' \/ -_)
\___/\_,_/_/_/_/\__/
                       ____
                      / __ \_  _____ ____
                     / /_/ / |/ / -_) __/
                     \____/|___/\__/_/

   _  __
  / |/ /__ _    __
 /    / -_) |/|/ /
/_/|_/\__/|__,__/
              __ ___      __
             / // (_)__ _/ /
            / _  / / _ `/ _ \
           /_//_/_/\_, /_//_/
                  /___/
                        ____
                       / __/______  _______
                      _\ \/ __/ _ \/ __/ -_)
                     /___/\__/\___/_/  \__/


*/



void        render_end(t_tetris *tetris)
{
    wclear(tetris->windows->main_window);
    if (tetris->v_game->score > tetris->v_game->h_score)
    {
        wattron(tetris->windows->main_window, COLOR_PAIR(2));
        mvwprintw(tetris->windows->main_window, 1, 1, "   _  __");
        mvwprintw(tetris->windows->main_window, 2, 1, "  / |/ /__ _    __");
        mvwprintw(tetris->windows->main_window, 3, 1, " /    / -_) |/|/ /");
        mvwprintw(tetris->windows->main_window, 4, 1, "/_/|_/\\__/|__,__/");
        mvwprintw(tetris->windows->main_window, 5, 1, "              __ ___      __");
        mvwprintw(tetris->windows->main_window, 6, 1, "             / // (_)__ _/ /");
        mvwprintw(tetris->windows->main_window, 7, 1, "            / _  / / _ `/ _ \\");
        mvwprintw(tetris->windows->main_window, 8, 1, "           /_//_/_/\\_, /_//_/");
        mvwprintw(tetris->windows->main_window, 9, 1, "                  /___/");
        mvwprintw(tetris->windows->main_window, 10, 1, "                        ____");
        mvwprintw(tetris->windows->main_window, 11, 1, "                       / __/______  _______");
        mvwprintw(tetris->windows->main_window, 12, 1, "                      _\\ \\/ __/ _ \\/ __/ -_)");
        mvwprintw(tetris->windows->main_window, 13, 1, "                     /___/\\__/\\___/_/  \\__/");
        wattroff(tetris->windows->main_window, COLOR_PAIR(2));
    }
    else
    {
        wattron(tetris->windows->main_window, COLOR_PAIR(1));
        mvwprintw(tetris->windows->main_window, 2, 1, "  _____");
        mvwprintw(tetris->windows->main_window, 3, 1, " / ___/__  __ _  ___");
        mvwprintw(tetris->windows->main_window, 4, 1, "/ (_ / _ `/  ' \\/ -_)");
        mvwprintw(tetris->windows->main_window, 5, 1, "\\___/\\_,_/_/_/_/\\__/");
        mvwprintw(tetris->windows->main_window, 9, 1, "                       ____");
        mvwprintw(tetris->windows->main_window, 10, 1, "                      / __ \\_  _____ ____");
        mvwprintw(tetris->windows->main_window, 11, 1, "                     / /_/ / |/ / -_) __/");
        mvwprintw(tetris->windows->main_window, 12, 1, "                     \\____/|___/\\__/_/");
        wattroff(tetris->windows->main_window, COLOR_PAIR(1));
    }
    mvwprintw(tetris->windows->main_window, 15, 14, "Your score %6d", tetris->v_game->score);
    wattron(tetris->windows->main_window, A_ITALIC);
    mvwprintw(tetris->windows->main_window, 20, 13, "Press R to restart");
    wattroff(tetris->windows->main_window, A_ITALIC);
    wrefresh(tetris->windows->main_window);
}
