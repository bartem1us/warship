#include <ncurses.h>
#include <cstdlib>
#include "game_ship.h"
int main()
{

    if (!initscr()) {
        fprintf(stderr, "Error initialising ncurses.\n");
        exit(1);
    }
   game_field first ;

    first.def();

    initscr();
    curs_set(0);
    refresh();
    keypad(stdscr, true);
    first.display();
    first.my_display();
    first.move_ship(4);
    first.move_ship(3);
    first.move_ship(3);
    first.move_ship(2);
    first.move_ship(2);
    first.move_ship(2);
    first.move_ship(1);
    first.move_ship(1);
    first.move_ship(1);
    first.move_ship(1);

    getch();
getch();
getch();
    endwin();

}
