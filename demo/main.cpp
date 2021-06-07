#include <ncurses.h>
#include <cstdlib>
#include "game_ship.h"
int main()
{
    setlocale(LC_ALL, "Russian");
    if (!initscr()) {
        fprintf(stderr, "Error initialising ncurses.\n");
        exit(1);
    }
   game_field first ;
    first.rules();
    clear();

    first.def();

    initscr();
    curs_set(0);
    refresh();
    keypad(stdscr, true);
    first.display();
    first.my_display(60);
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
    first.display();

    first.intellegent_desk();
    bool game =false;

    while (game != true) {
        first.shoot();
        first.enemy_shoot();
        game =first.my_end_game();
        game = first.enemy_end_game();

    }

    endwin();

}
