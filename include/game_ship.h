#include <vector>
#include <iostream>
#ifndef DZ_GAME_SHIP_H
#define DZ_GAME_SHIP_H
class game_field
{
 std::vector<std::vector<char>> visible_field;
 std::vector<std::vector<char>> my_field;
 size_t x=0;
 size_t y=0;
public:
    void rules();
    void display();
    void my_display();
    void move_ship(size_t i);
    void def();
    void move_up_ship_vertical(size_t i);
    void move_down_ship_vertical(size_t i);
    void move_left_ship_vertical(size_t i);
    void move_right_ship_vertical(size_t i);
    void move_up_ship_horizontal(size_t i);
    void move_down_ship_horizontal(size_t i);
    void move_left_ship_horizontal(size_t i);
    void move_right_ship_horizontal(size_t i);
    bool condition_vertical(size_t i);
    bool condition_horizontal(size_t i);


};
#endif //DZ_GAME_SHIP_H
