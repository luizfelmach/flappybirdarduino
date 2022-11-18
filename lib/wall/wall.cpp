#include <wall.hpp>
#include <Arduino.h>

Wall::Wall() {
    hole = 20;
    x = 120;
    y1 = random(1, 44);
    y2 = 64 - (y1 + hole);
    scored = false;
}

void Wall::update() {
    x -= 2;
}