#pragma once

class Wall {
   public:
    int hole;
    int inc, incy;
    int x, y1, y2;
    bool scored;
    Wall();
    void update();
    void stop();
};
