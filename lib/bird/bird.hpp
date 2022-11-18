#pragma once

class Bird {
    public:
        int x, y;
        int vx, vy;
        int acx, acy;
        Bird();
        Bird(int x, int y);
        void update();
};
