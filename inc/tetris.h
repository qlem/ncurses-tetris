/*
** tetris.h for tetris in /home/qlem/rendu/tetris/inc
** 
** Made by qlem
** Login   <clement.dommerc@epitech.eu>
** 
** Started on  Fri Jul 14 17:54:48 2017 qlem
** Last update Fri Jul 14 17:55:56 2017 qlem
*/

#ifndef _TETRIS_H_
# define _TETRIS_H_

#include <ncurses.h>
#include <curses.h>
#include <term.h>
#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "int_to_str.h"

#define MW_WIDTH 45
#define MW_HEIGHT 22
#define MW_X 0
#define MW_Y 0

#define GW_WIDTH 22
#define GW_HEIGHT 22
#define GW_X 23
#define GW_Y 0

#define DW_WIDTH 22
#define DW_HEIGHT 11
#define DW_X 0
#define DW_Y 11

#define NW_WIDTH 22
#define NW_HEIGHT 11
#define NW_X 0
#define NW_Y 0

#define GRID_W 10
#define GRID_H 20

#define BILLION 1000000000

/*
** ENUM
*/

typedef enum        e_mode
{
    CANONICAL,
    NONCANONICAL
}                   e_mode;

typedef enum        e_key
{
    UP,
    DOWN,
    LEFT,
    RIGHT,
    ESCAPE,
    ENTER,
    UNDEFINED,
    RESTART,
    NO_PRESSED
}                   e_key;

typedef enum        e_state
{
    START,
    GAME,
    MENU,
    OVER,
    QUIT
}                   e_state;

/*
** STRUCTURES
*/

/* Tetrimino */
typedef struct      s_position
{
    int             s_x;
    int             e_x;
    int             s_y;
    int             e_y;
}                   t_position;

typedef struct              s_tetrimino
{
    int                     width;
    int                     height;
    int                     color;
    int                     **matrix;
    t_position              position;
    struct s_tetrimino      *next;
}                           t_tetrimino;

/* Menu pause */
typedef struct      s_color
{
    char            *name;
    int             color;
}                   t_color;

typedef struct      s_subm_color
{
    t_color         tab_color[7];
    int             p_index;
    int             nb_color;
}                   t_subm_color;

typedef struct      s_elem
{
    char            *name;
    int             id;
}                   t_elem;

typedef struct      s_menu
{
    t_elem          tab_elem[3];
    t_subm_color    *subm_color;
    int             nb_elem;
    int             p_index;
    bool            opt_color;
}                   t_menu;

/* Configuration Terminal */
typedef struct      s_terminal
{
    struct termios  initial_conf;
    e_mode          current_mode;
}                   t_terminal;


/* Windows ncurses */
typedef struct      s_windows
{
    WINDOW          *main_window;
    WINDOW          *next_window;
    WINDOW          *data_window;
    WINDOW          *game_window;
    WINDOW          *debug_window;
}                   t_windows;

/* Timer */
typedef struct      s_timer
{
    time_t          sec;
    time_t          min;
    time_t          hour;
    time_t          ref;
}                   t_timer;

/* Timer level */
typedef struct      s_lvl_timer
{
    double          ref;
}                   t_lvl_timer;

/* Var game */
typedef struct      s_v_game
{
    long            score;
    long            h_score;
    int             level;
    int             nb_lines;
    int             nb_tetri;
    int             **grid;
    t_timer         *timer;
    t_lvl_timer     *lvl_timer;
    t_tetrimino     *l_tetri;
    t_tetrimino     *n_tetri;
    t_tetrimino     *c_tetri;
}                   t_v_game;

/* Main structure */
typedef struct      s_tetris
{
    e_state         state;
    t_windows       *windows;
    t_terminal      *terminal;
    t_menu          *menu;
    t_v_game        *v_game;
}                   t_tetris;

/*
** FUNCTIONS
*/

/* Terminal */
void            save_initial_conf(t_tetris *tetris);
void            reset_mode(t_tetris *tetris);
void            set_noncanonical_mode(t_tetris *tetris);
int             init_terminal(void);
t_terminal      *malloc_terminal_struct(void);

/* Load tetrimino */
int             set_new_tetrimino(t_tetrimino *new, char *buffer);
void            add_tetrimino(t_tetris *tetris, char *buffer);
int             load_tetrimino(t_tetris *tetris);

/* Windows */
void            set_color(void);
void            draw_border(WINDOW *win, chtype c, int color_pair);
void            render_menu(t_tetris *tetris);
void            render_end(t_tetris *tetris);
void            render_start(t_tetris *tetris);
void            render_grid(t_tetris *tetris);
void            render_game(t_tetris *tetris);
int             init_windows(t_tetris *tetris);
t_windows       *malloc_windows_struct(void);

/* Game logic */
void            restart_game(t_tetris *tetris);
void            check_lines(t_tetris *tetris);
bool            is_game_over(t_tetris *tetris);
t_tetrimino     *get_tetrimino(t_tetris *tetris);
void            tetrimino_on_board(t_tetris *tetris);
void            menu_event(t_tetris *tetris, e_key key);
e_key           key_event(void);
int             game_loop(t_tetris *tetris);

/* Move */
bool            move_down(t_tetris *tetris);
bool            move_left(t_tetris *tetris);
bool            move_right(t_tetris *tetris);
bool            rotate(t_tetris *tetris);
bool            check_rotate(t_tetris *tetris);

/* Lvl timer */
bool            get_timing(t_tetris *tetris);
void            set_ref_time_lvl(t_tetris *tetris);
t_lvl_timer     *malloc_lvl_timer(void);

/* Timer */
void            update_timer(t_tetris *tetris);
void            set_ref_time(t_tetris *tetris);
t_timer         *malloc_timer(void);

/* Var game */
t_menu          *malloc_pause_menu(void);
t_v_game        *malloc_var_game(void);

/* Load and write high score */
int             write_new_high_score(long score);
int             load_high_score(void);

/* Free */
int             free_matrix(t_tetrimino *tetrimino);
int             free_mem(t_tetris *tetris);

/* Debug */
void            print_sequence(char *buffer);
void            display_matrix(t_tetrimino *tetrimino);

#endif /* !TERIS_H_ */
