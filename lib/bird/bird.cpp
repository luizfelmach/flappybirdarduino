#include <bird.hpp>

Bird::Bird() {
}

Bird::Bird(int x  = 40, int y = 40): x(x), y(y) {
    vx = 0;
    vy = 0;
    acx = 0;
    acy = 1;
}

void Bird::update() {
    vx += acx;
    vy += acy;
    x += vx;
    y += vy;
    vx = vx > 5 ? 5 : vx;
    vy = vy > 5 ? 5 : vy;
}