#include "game_ship.h"
#include <ncurses.h>
#include <cstring>

void game_field::rules()
{
    std::vector<std::string>rules;
    rules.push_back("Расстановка кораблей:");
    rules.push_back("f1 - поставить корабль на место курсора");
    rules.push_back("f2 - поменять расположение корабля (горизонтальное/вертикальное)");
    rules.push_back(" Игра:");
    rules.push_back("  f1 - выстрелить в данную клетку поля");
    refresh();
    WINDOW *win = newwin(23, 41, 0, 0);
    box(win, 0, 0);
    start_color();
    init_pair(1, COLOR_BLUE, A_NORMAL);
    wattron(win, COLOR_PAIR(1));

    for (int i = 0; i < rules.size(); ++i) {
        for (int j = 0; j < rules[i].size(); ++j) {

            mvwprintw(win, 2 * i + 2, 4 * j + 2, "%c", rules[i][j]);

        }
    }
    use_default_colors();
    wrefresh(win);
    delwin(win);
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

    for (size_t i = 0; i < visible_field.size(); ++i) {
        visible_field[i].resize(10);
        my_field[i].resize(10);
        for (size_t k = 0; k < visible_field[i].size(); ++k) {
            visible_field[i][k] = '-';
            my_field[i][k] = '-';
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

void game_field::my_display() {
    refresh();
    WINDOW *win = newwin(23, 41, 0, 60);
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
                        pos=false;
                        my_display();
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
                        my_display();
                        pos=false;
                        break;
                    } else { break; }
                }
            }
        }
    }
}