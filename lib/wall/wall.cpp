#include <wall.hpp>
#include <Arduino.h>

Wall::Wall() {
    hole = 20;
    x = 120;
    y1 = random(1, 44);
    y2 = 64 - (y1 + hole);
    inc = 2;
    scored = false;
}

void Wall::update() {
    x -= inc;
}

void Wall::stop() {
    inc = 0;
}