#include <Arduino.h>
#include <U8glib.h>

#include <bird.hpp>
#include <screen.hpp>

Screen::Screen() {
    u8g = U8GLIB_SSD1306_128X64(U8G_I2C_OPT_NONE | U8G_I2C_OPT_DEV_0);
    u8g.setFont(u8g_font_04b_24);
    bird = Bird(30, 30);
    collided = false;
    score = 0;
    last_wall = 0;
    last_time = 0;
    status = START;
    add_wall();
}

void Screen::draw() {
    u8g.firstPage();
    do {
        if (status == START) {
            u8g.drawStr(25, 35, "Press button to start");
        }

        if (status == PLAY) {
            draw_bird();
            draw_score();
            draw_wall();
        }

        if (status == GAME_OVER) {
            draw_score();
            u8g.drawStr(45, 35, "Game over");
        }

    } while (u8g.nextPage());

    if (status == START) {
    }

    if (status == PLAY) {
        if (last_time == 20) {
            add_wall();
            last_time = 0;
        }

        last_time += 1;

        bird.update();

        for (int i = 0; i < last_wall; i++) {
            walls[i].update();
        }

        bird_check_collision();
        update_score();
    }

    if (status == GAME_OVER) {
    }
}

void Screen::draw_bird() { u8g.drawCircle(bird.x, bird.y, 1); }

void Screen::pressed_button() {
    if (status == START) {
        status = PLAY;
    }

    if (status == PLAY) {
        if (collided) {
            return;
        }
        bird.vy = -5;
    }
    Serial.println("Apertou o botao");

    if (status == GAME_OVER) {
        Serial.println("Apertou o botao dentro do game over");

        collided = false;
        score = 0;
        last_wall = 0;
        last_time = 0;
        bird = Bird(30, 30);
        walls[0] = Wall();
        walls[1] = Wall();
        walls[2] = Wall();
        add_wall();
        status = PLAY;
    }
}

void Screen::bird_check_collision() {
    if (bird.y >= 64 or bird.y <= 0) {
        bird.acy = 0;
        bird.acx = 0;
        bird.vx = 0;
        bird.vy = 0;
        collided = true;
        status = GAME_OVER;
    }

    if ((bird.x >= walls[0].x and bird.x <= walls[0].x + 5) and
        (bird.y <= walls[0].y1 or bird.y >= walls[0].y1 + walls[0].hole)) {
        bird.acy = 0;
        bird.acx = 0;
        bird.vx = 0;
        bird.vy = 0;
        collided = true;
        status = GAME_OVER;
    }

    if (collided) {
        walls[0].stop();
        walls[1].stop();
        walls[2].stop();
        status = GAME_OVER;
    }
}

void Screen::draw_score() {
    char s_str[20];
    itoa(score, s_str, 10);
    u8g.drawStr(5, 10, s_str);
}

void Screen::draw_wall() {
    for (int i = 0; i < last_wall; i++) {
        u8g.drawBox(walls[i].x, 0, 5, walls[i].y1);
        u8g.drawBox(walls[i].x, walls[i].y1 + walls[i].hole, 5, walls[i].y2);
    }
}

void Screen::add_wall() {
    if (last_wall == 3) {
        walls[0] = walls[1];
        walls[1] = walls[2];
        walls[2] = Wall();
        last_wall = 2;
    }
    last_wall += 1;
}

void Screen::update_score() {
    if (walls[0].scored) {
        return;
    }
    if (walls[0].x + 10 <= bird.x) {
        score += 1;
        walls[0].scored = true;
    }
}
