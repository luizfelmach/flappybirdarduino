#include <Arduino.h>

#include <wall.hpp>

Wall::Wall() {
    hole = 20;
    x = 120;
    y1 = random(3, 41);
    y2 = 64 - (y1 + hole);
    inc = 2;
    incy = random(-2, 2);
    scored = false;
}

void Wall::update() {
    x -= inc;
    y1 += incy;
    y2 = 64 - (y1 + hole);

    if (y1 <= 2 or y1 >= 42) {
        incy *= -1;
    }
}

void Wall::stop() { inc = 0; }