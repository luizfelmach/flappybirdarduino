#pragma once

#include <U8glib.h>

#include <bird.hpp>
#include <wall.hpp>

typedef enum { START = 0, PLAY = 1, GAME_OVER = 2 } STATUS;

class Screen {
    Bird bird;
    Wall walls[3];
    int last_wall;
    int score;
    int last_time;
    STATUS status;

   public:
    U8GLIB_SSD1306_128X64 u8g;
    bool collided;
    Screen();
    void draw();
    void draw_bird();
    void pressed_button();
    void bird_check_collision();
    void game_over();
    void draw_score();
    void draw_wall();
    void add_wall();
    void update_score();
};