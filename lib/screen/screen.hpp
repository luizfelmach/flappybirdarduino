#pragma once

#include <U8glib.h>
#include <bird.hpp>
#include <wall.hpp>

class Screen {
    Bird bird;
    Wall walls[3];
    int last_wall;
    int score;
    int last_time;
    public:
        U8GLIB_SSD1306_128X64 u8g;
        bool collided;
        Screen();
        void draw();
        void draw_bird();
        void bird_jump();;
        void bird_check_collision();
        void game_over();
        void draw_score();
        void draw_wall();
        void add_wall();
        void update_score();
};