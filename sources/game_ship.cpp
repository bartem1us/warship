#include "game_ship.h"
#include <ncurses.h>
#include <cstring>

void game_field::rules()
{

    clear();

    initscr();

    int height = 23;
    int width = 89;
    int x = 30;
    int y = 10;

    WINDOW *help_win = newwin(height, width, y, x);
    refresh();
    box(help_win, 0, 0);

    mvwprintw(help_win, 1, 1, "--------------------------------------- Rules ---------------------------------------");
    mvwprintw(help_win, 2, 1, "1) The player has 4 types of ships:                                                 ");
    mvwprintw(help_win, 3, 1, "   single-deck, double-deck, three-deck and four-deck:                               ");
    mvwprintw(help_win, 4, 1, "   O, OO, OOO, OOOO - designation of the ships                                       ");
    mvwprintw(help_win, 5, 1, "2) The distance between the ships must be at least 1 cell, including diagonally     ");
    mvwprintw(help_win, 6, 1, "3) You can move ships using the keys: w - up, a - left, s - down, d - right         ");
    mvwprintw(help_win, 7, 1, "4) To change the orientation of the ship, you need to press Insert                   ");
    mvwprintw(help_win, 8, 1, "5) To put the ship on the field, you need to press '+'                               ");
    mvwprintw(help_win, 9, 1, "6) After the player has placed his ships, two fields will appear in front of him:   ");
    mvwprintw(help_win, 10, 1, "  the left one -his, right one - the enemy's field                                  ");
    mvwprintw(help_win, 13, 1, "8) ! The player's task is to sink all enemy ships first !                          ");
    mvwprintw(help_win, 14, 1, "-------------------------------------- Symbols --------------------------------------");
    mvwprintw(help_win, 15, 1, "1) '-'  - water, free space,                                                       ");
    mvwprintw(help_win, 16, 1, "2) 'O'  - ship (part of a ship),                                                   ");
    mvwprintw(help_win, 17, 1, "3) '*'  - miss,                                                                    ");
    mvwprintw(help_win, 18, 1, "4) '*'  - occupied space, in these places you cannot put,                          ");
    mvwprintw(help_win, 19, 1, "5) 'X'  - shot at the ship (on the part of the ship)                               ");
    mvwprintw(help_win, 20, 1, "-------------------------------------- End Rules ----------------------------------");
    mvwprintw(help_win, 21, 1, "1)Press q to exit                                                                  ");
    wrefresh(help_win);

    while (true) {
        int ch = getch();
        if (ch == 'q') //Quit if q is pressed
            break;
    }
}
void game_field::display() {
    refresh();
    WINDOW *win = newwin(23, 41, 0, 0);
    box(win, 0, 0);
    start_color();
    init_pair(1, COLOR_BLUE, A_NORMAL);
    wattron(win, COLOR_PAIR(1));

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            mvwprintw(win, 2 * i + 2, 4 * j + 2, "%c", visible_field[i][j]);
        }
    }
    use_default_colors();
    wrefresh(win);
    delwin(win);
}


void game_field::def() {
    visible_field.resize(10);
    my_field.resize(10);
    shoot_field.resize(10);
    enemy_field.resize(10);

    for (size_t i = 0; i < visible_field.size(); ++i) {
        visible_field[i].resize(10);
        my_field[i].resize(10);
        shoot_field[i].resize(10);
        enemy_field[i].resize(10);
        for (size_t k = 0; k < visible_field[i].size(); ++k) {
            visible_field[i][k] = '-';
            my_field[i][k] = '-';
            shoot_field[i][k]='-';
            enemy_field[i][k]='-';
        }
    }
}

void game_field::move_up_ship_vertical(size_t i) {

    if (y != 0) {
        --y;
    }
    for (size_t i = 0; i < visible_field.size(); ++i) {
        for (size_t k = 0; k < visible_field[i].size(); ++k) {
            visible_field[i][k] = '-';
        }
    }
    for (size_t k = y; k - y < i; ++k) {
        visible_field[k][x] = 'O';
    }
}

void game_field::move_down_ship_vertical(size_t i) {

    if (10 - y != i) {
        ++y;
    }
    for (size_t i = 0; i < visible_field.size(); ++i) {
        for (size_t k = 0; k < visible_field[i].size(); ++k) {
            visible_field[i][k] = '-';
        }
    }
    for (size_t k = y; k - y < i; ++k) {
        visible_field[k][x] = 'O';
    }
}

void game_field::move_right_ship_vertical(size_t i) {
    if (x != 9) {
        ++x;
    }
    for (size_t i = 0; i < visible_field.size(); ++i) {
        for (size_t k = 0; k < visible_field[i].size(); ++k) {
            visible_field[i][k] = '-';
        }
    }
    for (size_t k = y; k - y < i; ++k) {
        visible_field[k][x] = 'O';
    }
}

void game_field::move_left_ship_vertical(size_t i) {
    if (x != 0) {
        --x;
    }
    for (size_t i = 0; i < visible_field.size(); ++i) {
        for (size_t k = 0; k < visible_field[i].size(); ++k) {
            visible_field[i][k] = '-';
        }
    }
    for (size_t k = y; k - y < i; ++k) {
        visible_field[k][x] = 'O';
    }
}

void game_field::move_down_ship_horizontal(size_t i) {
    if (y != 9) {
        ++y;
    }
    for (size_t i = 0; i < visible_field.size(); ++i) {
        for (size_t k = 0; k < visible_field[i].size(); ++k) {
            visible_field[i][k] = '-';
        }
    }
    for (size_t k = x; k - x < i; ++k) {
        visible_field[y][k] = 'O';
    }
}

void game_field::move_up_ship_horizontal(size_t i) {
    if (y != 0) {
        --y;
    }
    for (size_t i = 0; i < visible_field.size(); ++i) {
        for (size_t k = 0; k < visible_field[i].size(); ++k) {
            visible_field[i][k] = '-';
        }
    }
    for (size_t k = x; k - x < i; ++k) {
        visible_field[y][k] = 'O';
    }
}

void game_field::move_left_ship_horizontal(size_t i) {
    if (x != 0) {
        --x;
    }
    for (size_t i = 0; i < visible_field.size(); ++i) {
        for (size_t k = 0; k < visible_field[i].size(); ++k) {
            visible_field[i][k] = '-';
        }
    }
    for (size_t k = x; k - x < i; ++k) {
        visible_field[y][k] = 'O';
    }
}

void game_field::move_right_ship_horizontal(size_t i) {
    if (10 - x != i) {
        ++x;
    }
    for (size_t i = 0; i < visible_field.size(); ++i) {
        for (size_t k = 0; k < visible_field[i].size(); ++k) {
            visible_field[i][k] = '-';
        }
    }
    for (size_t k = x; k - x < i; ++k) {
        visible_field[y][k] = 'O';
    }
}

void game_field::my_display(int wide) {
    refresh();
    WINDOW *win = newwin(23, 41, 0, wide);
    box(win, 0, 0);
    start_color();
    init_pair(1, COLOR_BLUE, A_NORMAL);
    wattron(win, COLOR_PAIR(1));

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {

            if (i == x && j == y) {
                mvwprintw(win, 2 * i + 2, 4 * j + 2, "%c", my_field[i][j]);

            } else {
                mvwprintw(win, 2 * i + 2, 4 * j + 2, "%c", my_field[i][j]);
            }
        }
    }
    use_default_colors();
    wrefresh(win);//
    delwin(win);//
}

bool game_field::condition_vertical(size_t i) {

    try {
        for (size_t k = 0; k < i; k++) {
            char t = my_field.at(y + k).at(x);
            if (t == 'O') {
                return false;
            }
        }
    }
    catch (std::out_of_range &e) {}
    try {
        char t = my_field.at(y + i ).at(x);
        if (t == 'O') {
            return false;
        }
    }
    catch (std::out_of_range &e) {}
    try {
        char t = my_field.at(y - 1).at(x);
        if (t == 'O') {
            return false;
        }
    }
    catch (std::out_of_range &e) {}
    try {
        for (size_t k = 0; k < i; k++) {
            char t = my_field.at(y + k).at(x + 1);
            if (t == 'O') {
                return false;
            }
        }
    }
    catch (std::out_of_range &e) {}
    try {
        char t = my_field.at(y  + i).at(x + 1);
        if (t == 'O') {
            return false;
        }
    }
    catch (std::out_of_range &e) {}
    try {
        char t = my_field.at(y - 1).at(x + 1);
        if (t == 'O') {
            return false;
        }
    }
    catch (std::out_of_range &e) {}
    try {
        for (size_t k = 0; k < i; k++) {
            char t = my_field.at(y + k).at(x - 1);
            if (t == 'O') {
                return false;
            }
        }
    }
    catch (std::out_of_range &e) {}
    try {
        char t = my_field.at(y + i ).at(x - 1);
        if (t == 'O') {
            return false;
        }
    }
    catch (std::out_of_range &e) {}
    try {
        char t = my_field.at(y - 1).at(x - 1);
        if (t == 'O') {
            return false;
        }
    }
    catch (std::out_of_range &e) {}


    return true;


}

bool game_field::condition_horizontal(size_t i) {
    try {
        for (size_t k = 0; k < i; k++) {
            char t = my_field.at(y).at(x + k);
            if (t == 'O') {
                return false;
            }
        }
    }
    catch (std::out_of_range &e) {}
    try {
        for (size_t k = 0; k < i; k++) {
            char t = my_field.at(y + 1).at(x + k);
            if (t == 'O') {
                return false;
            }
        }
    }
    catch (std::out_of_range &e) {}
    try {
        for (size_t k = 0; k < i; k++) {
            char t = my_field.at(y -1).at(x + k);
            if (t == 'O') {
                return false;
            }
        }
    }
    catch (std::out_of_range &e) {}
    try {
        char t = my_field.at(y).at(x - 1);
        if (t == 'O') {
            return false;
        }
    }
    catch (std::out_of_range &e) {}

    try
    {
        char t = my_field.at(y+1).at(x+i);
        if (t == 'O') {
            return false;
        }
    }
    catch (std::out_of_range &e) {}
    try {
        char t = my_field.at(y - 1).at(x  + i);
        if (t == 'O') {
            return false;
        }
    }
    catch (std::out_of_range &e){}
    try
    {
        char t = my_field.at(y).at(x+i);
        if (t == 'O') {
            return false;
        }
    }
    catch (std::out_of_range &e) {}
    try {
        char t = my_field.at(y + 1).at(x - 1);
        if (t == 'O') {
            return false;
        }
    }
    catch (std::out_of_range &e) {}
    try {
        char t = my_field.at(y - 1).at(x - 1);
        if (t == 'O') {
            return false;
        }
    }
    catch (std::out_of_range &e) {}
    try {
        char t = my_field.at(y + 1).at(x);
        if (t == 'O') {
            return false;
        }
    }
    catch (std::out_of_range &e) {}
    return true;


}

void game_field::move_ship(size_t i) {
    bool pos = true;
    bool change_hor = true;
    while (pos != false) {
        if (change_hor == true) {
            int key = getch();
            switch (key) {
                case KEY_UP: {
                    move_up_ship_vertical(i);
                    display();
                    break;
                }
                case KEY_DOWN: {
                    move_down_ship_vertical(i);
                    display();
                    break;
                }
                case KEY_RIGHT: {
                    move_right_ship_vertical(i);
                    display();
                    break;
                }
                case KEY_LEFT: {
                    move_left_ship_vertical(i);
                    display();
                    break;
                }
                case KEY_IC: {
                    change_hor = false;
                    x = 0;
                    y = 0;
                    break;
                }
                case '+': {
                    if (condition_vertical(i)) {
                        for (size_t k = 0; k < i; ++k) {
                            my_field[y + k][x] = visible_field[y + k][x];
                        }
                        pos = false;
                        my_display(60);
                        x = 0;
                        y = 0;
                        break;
                    } else { break; }
                }
            }

        }
        if (change_hor == false) {
            int key = getch();
            switch (key) {
                case KEY_UP: {
                    move_up_ship_horizontal(i);
                    display();
                    break;
                }
                case KEY_DOWN: {
                    move_down_ship_horizontal(i);
                    display();
                    break;
                }
                case KEY_RIGHT: {
                    move_right_ship_horizontal(i);
                    display();
                    break;
                }
                case KEY_LEFT: {
                    move_left_ship_horizontal(i);
                    display();
                    break;
                }
                case KEY_IC: {
                    x = 0;
                    y = 0;
                    change_hor = true;
                    break;
                }
                case '+': {
                    if (condition_horizontal(i)) {
                        for (size_t k = 0; k < i; ++k) {
                            my_field[y][x + k] = visible_field[y][x + k];
                        }
                        my_display(60);
                        pos = false;
                        x = 0;
                        y = 0;
                        break;
                    } else { break; }
                }
            }
        }
    }

}

bool game_field::is_dead(const int x, const int y) const {
    int curr_x = x;
    int curr_y = y;
    while (true) {
        ++curr_y;
        try {
            if (enemy_field.at(curr_x).at(curr_y) == '-' || visible_field.at(curr_x).at(curr_y) == '*') {
                break;
            }
            if (enemy_field.at(curr_x).at(curr_y) == 'O') {
                return false;
            }
        } catch (std::out_of_range &e) {
            break;
        }
    }
    curr_y = y;
    while (true) {
        --curr_y;
        try {
            if (enemy_field.at(curr_x).at(curr_y) == '-' || visible_field.at(curr_x).at(curr_y) == '*') {
                break;
            }
            if (enemy_field.at(curr_x).at(curr_y) == 'O') {
                return false;
            }
        } catch (std::out_of_range &e) {
            break;
        }
    }
    curr_y = y;
    while (true) {
        --curr_x;
        try {
            if (enemy_field.at(curr_x).at(curr_y) == '-' || visible_field.at(curr_x).at(curr_y) == '*') {
                break;
            }
            if (enemy_field.at(curr_x).at(curr_y) == 'O') {
                return false;
            }
        } catch (std::out_of_range &e) {
            break;
        }
    }
    curr_x = x;
    while (true) {
        ++curr_x;
        try {
            if (enemy_field.at(curr_x).at(curr_y) == '-' || visible_field.at(curr_x).at(curr_y) == '*') {
                break;
            }
            if (enemy_field.at(curr_x).at(curr_y) == 'O') {
                return false;
            }
        } catch (std::out_of_range &e) {
            break;
        }
    }
    return true;
}

void game_field::AutoShoot(const int x, const int y) {
    int curr_x = x;
    int curr_y = y;
    bool direction = false;
    while (true) {
        --curr_y;
        try {
            if (visible_field.at(curr_x).at(curr_y) == '-' || visible_field.at(curr_x).at(curr_y) == '*') {
                break;
            }
        } catch (std::out_of_range &e) {
            break;
        }
    }
    ++curr_y;

    while (true) {
        --curr_x;
        try {
            if (visible_field.at(curr_x).at(curr_y) == '-' || visible_field.at(curr_x).at(curr_y) == '*') {
                break;
            }
        } catch (std::out_of_range &e) {
            break;
        }
    }
    ++curr_x;

    try {
        if (visible_field.at(curr_x + 1).at(curr_y) == 'X') {
            direction = true;
        }
    } catch (std::out_of_range &e) {}
    if (direction) {
        for (int i = -1; i < 2; ++i) {
            try {
                visible_field.at(curr_x - 1).at(curr_y + i) = '*';
            } catch (std::out_of_range &e) {}
        }
        while (true) {
            try {
                if (visible_field.at(curr_x).at(curr_y) == '-' ||
                    visible_field.at(curr_x).at(curr_y) == '*') {
                    break;
                }
            } catch (std::out_of_range &e) {
                break;
            }
            visible_field[curr_x][curr_y] = 'X';
            try {
                visible_field.at(curr_x).at(curr_y + 1) = '*';
            } catch (std::out_of_range &e) {}
            try {
                visible_field.at(curr_x).at(curr_y - 1) = '*';
            } catch (std::out_of_range &e) {}
            ++curr_x;
        }
        for (int i = -1; i < 2; ++i) {
            try {
                visible_field.at(curr_x).at(curr_y + i) = '*';
            } catch (std::out_of_range &e) {}
        }
    } else {
        for (int i = -1; i < 2; ++i) {
            try {
                visible_field.at(curr_x + i).at(curr_y - 1) = '*';
            } catch (std::out_of_range &e) {}
        }
        while (true) {
            try {
                if (visible_field.at(curr_x).at(curr_y) == '-' ||
                    visible_field.at(curr_x).at(curr_y) == '*') {
                    break;
                }
            } catch (std::out_of_range &e) {
                break;
            }
            visible_field[curr_x][curr_y] = 'X';
            try {
                visible_field.at(curr_x + 1).at(curr_y) = '*';
            } catch (std::out_of_range &e) {}
            try {
                visible_field.at(curr_x - 1).at(curr_y) = '*';
            } catch (std::out_of_range &e) {}
            ++curr_y;
        }
        for (int i = -1; i < 2; ++i) {
            try {
                visible_field.at(curr_x + i).at(curr_y) = '*';
            } catch (std::out_of_range &e) {}
        }
    }

}


void game_field::shoot_display() {
    refresh();
    WINDOW *win = newwin(23, 41, 0, 0);
    box(win, 0, 0);
    start_color();
    init_pair(1, COLOR_BLUE, A_NORMAL);
    init_pair(2, A_NORMAL, COLOR_RED);


    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            wattron(win, COLOR_PAIR(1));
            if (i == y && j == x) {
                wattron(win, COLOR_PAIR(2));
                mvwprintw(win, 2 * i + 2, 4 * j + 2, "%c", visible_field[i][j]);
                wattroff(win, COLOR_PAIR(2));
            } else {
                wattron(win, COLOR_PAIR(1));
                mvwprintw(win, 2 * i + 2, 4 * j + 2, "%c", visible_field[i][j]);
                wattroff(win, COLOR_PAIR(1));
            }
        }
    }
    use_default_colors();
    wrefresh(win);//
    delwin(win);//
}
void game_field::move_shoot_up() {
    if (y != 0) {
        --y;
    }


}
void game_field::move_shoot_down()
{
    if (y != 9) {
        ++y;
    }
}

void game_field::move_shoot_right() {
    if (x != 9) {
        ++x;
    }


}

void game_field::move_shoot_left() {
    if (x != 0) {
        --x;
    }

}

bool game_field::my_end_game() {
    size_t win = 0;
    for (size_t i = 0; i < visible_field.size(); ++i) {
        for (size_t k = 0; k < visible_field[i].size(); ++k) {
            if (visible_field[i][k] == 'X') {
                ++win;
            }
        }
    }
    if (win == 20) {
        clear();

        initscr();

        int height = 13;
        int width = 89;
        int x = 30;
        int y = 10;

        WINDOW *help_win = newwin(height, width, y, x);
        refresh();
        box(help_win, 0, 0);

        mvwprintw(help_win, 1, 1,
                  "------------------------------------ Game is end ------------------------------------");
        mvwprintw(help_win, 2, 1,
                  "-------------------------------------------------------------------------------------");
        mvwprintw(help_win, 3, 1,
                  "-------------------------------------------------------------------------------------");
        mvwprintw(help_win, 4, 1,
                  "-------------------------------------------------------------------------------------");
        mvwprintw(help_win, 5, 1,
                  "-------------------------------------------------------------------------------------");
        mvwprintw(help_win, 6, 1,
                  "------------------------------------ Player win -------------------------------------");
        mvwprintw(help_win, 7, 1,
                  "-------------------------------------------------------------------------------------");
        mvwprintw(help_win, 8, 1,
                  "-------------------------------------------------------------------------------------");
        mvwprintw(help_win, 9, 1,
                  "-------------------------------------------------------------------------------------");
        mvwprintw(help_win, 10, 1,
                  "-------------------------------------------------------------------------------------");
        mvwprintw(help_win, 11, 1,
                  "-------------------------------------------------------------------------------------");

        wrefresh(help_win);

        while (true) {
            int ch = getch();
            if (ch == 'q') //Quit if q is pressed
                break;
        }
        return true;
    }
    return false;
}

bool game_field::enemy_end_game() {
    size_t win = 0;
    for (size_t i = 0; i < my_field.size(); ++i) {
        for (size_t k = 0; k < my_field[i].size(); ++k) {
            if (my_field[i][k] == 'X') {
                ++win;
            }
        }
    }
    if (win == 20) {
        clear();

        initscr();

        int height = 14;
        int width = 89;
        int x = 30;
        int y = 10;

        WINDOW *help_win = newwin(height, width, y, x);
        refresh();
        box(help_win, 0, 0);

        mvwprintw(help_win, 1, 1,
                  "------------------------------------ Game is end ------------------------------------");
        mvwprintw(help_win, 2, 1,
                  "-------------------------------------------------------------------------------------");
        mvwprintw(help_win, 3, 1,
                  "-------------------------------------------------------------------------------------");
        mvwprintw(help_win, 4, 1,
                  "-------------------------------------------------------------------------------------");
        mvwprintw(help_win, 5, 1,
                  "-------------------------------------------------------------------------------------");
        mvwprintw(help_win, 6, 1,
                  "-------------------------------------- AI win ---------------------------------------");
        mvwprintw(help_win, 7, 1,
                  "-------------------------------------------------------------------------------------");
        mvwprintw(help_win, 8, 1,
                  "-------------------------------------------------------------------------------------");
        mvwprintw(help_win, 9, 1,
                  "-------------------------------------------------------------------------------------");
        mvwprintw(help_win, 10, 1,
                  "-------------------------------------------------------------------------------------");
        mvwprintw(help_win, 13, 1,
                  "-------------------------------------------------------------------------------------");

        wrefresh(help_win);

        while (true) {
            int ch = getch();
            if (ch == 'q') //Quit if q is pressed
                break;
        }
        return true;
    }
    return false;
}

void game_field::enemy_shoot() {
    size_t new_x = rand() % 10;
    size_t new_y = rand() % 10;
    if (my_field[new_y][new_x] == 'O') {
        my_field[new_y][new_x] = 'X';
        
        my_display(60);
        return;
    } else if (my_field[new_y][new_x] == '-') {
        my_field[new_y][new_x] = '*';
        my_display(60);
        return;
    } else { enemy_shoot(); }
}


void game_field::shoot() {
    refresh();
    bool pos = false;
    while (pos != true) {
        int key = getch();
        switch (key) {
            case KEY_UP: {
                move_shoot_up();
                shoot_display();
                break;
            }
            case KEY_DOWN: {
                move_shoot_down();
                shoot_display();
                break;
            }
            case KEY_RIGHT: {
                move_shoot_right();
                shoot_display();
                break;
            }
            case KEY_LEFT: {
                move_shoot_left();
                shoot_display();
                break;
            }
            case '+': {
                if (enemy_field[y][x] == 'O' && visible_field[y][x] != 'X' && visible_field[y][x] != '*') {
                    visible_field[y][x] = 'X';
                    enemy_field[y][x] = 'X';
                    shoot_display();
                    if (is_dead(y, x)) {
                        AutoShoot(y,x);
                        shoot_display();
                    }
                    pos = true;
                    break;
                }
                if (enemy_field[y][x] == '-' && visible_field[y][x] != 'X' && visible_field[y][x] != '*') {
                    visible_field[y][x] = '*';
                    enemy_field[y][x] = '*';
                    shoot_display();
                    pos = true;
                    break;
                }
                break;
            }
        }
    }
}


void game_field::intellegent_desk() {
    for(size_t i = 0 ; i <4  ; ++i)
    {
        enemy_field[0][i]='O';
    }
    for(size_t i = 0 ; i <3  ; ++i)
    {
        enemy_field[0][5+i]='O';
    }
    for(size_t i = 0 ; i <3  ; ++i)
    {
        enemy_field[2][i]='O';
    }
    for(size_t i = 0 ; i <2  ; ++i)
    {
        enemy_field[2][i+4]='O';
    }
    for(size_t i = 0 ; i <2  ; ++i)
    {
        enemy_field[2][i+7]='O';
    }
    for(size_t i = 0 ; i <2  ; ++i)
    {
        enemy_field[i+4][0]='O';
    }
    enemy_field[9][9]='O';
    enemy_field[7][7]='O';
    enemy_field[9][0]='O';
    enemy_field[9][3]='O';

}