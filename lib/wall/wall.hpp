#pragma once

class Wall {
    public:
        int hole;
        int x, y1, y2;
        bool scored;
        Wall();
        void update();
};
