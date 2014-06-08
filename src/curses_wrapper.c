#include <curses.h>

void curses_init() 
{
	initscr();
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_BLUE, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_RED, COLOR_BLACK);
	refresh();
	keypad(stdscr,TRUE);
	nonl();
	cbreak();
	noecho();
	curs_set(0);
	clear();
    bkgd(COLOR_PAIR(2));
}

void curses_exit() 
{
	clear();
	endwin();
}


void curses_clear_screen()
{
    clear();
}


void curses_refresh()
{
    refresh();
}

void curses_show_char(int y, int x, int ch)
{
    mvaddch(y, x, ch);
}
