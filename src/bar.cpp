#include "bar.h"

#include "GLFW/glfw3.h"
#include "rectangle.h"

void Bar::handle_input(int key, int action) {
    if(key == up_key && action == GLFW_PRESS) {
        up_pressed = true;
    }
    if(key == up_key && action == GLFW_RELEASE) {
        up_pressed = false;
    }
    if(key == down_key && action == GLFW_PRESS) {
        down_pressed = true;
    }
    if(key == down_key && action == GLFW_RELEASE) {
        down_pressed = false;
    }
}

Bar::Bar(float x_size, float y_size, float x_pos, float red, float green,
         float blue, const Win& window, int up_key, int down_key, float speed)
    : Rectangle(x_size, y_size, x_pos, 0, red, green, blue, window),
      up_key(up_key), down_key(down_key), speed(speed), up_pressed(false),
      down_pressed(false), deltatime(0), last_time(0) {}

void Bar::render() {
    update();
    Rectangle::render();
}

void Bar::update() {
    double time = window.get_time();
    if(last_time == 0) {
        last_time = time;
        deltatime = 0;
    }
    else {
        deltatime = time - last_time;
        last_time = time;
    }
    shift(0, speed * (float) deltatime *
                 (float) ((int) up_pressed - (int) down_pressed));
    if(position.y + y_lenght / 2 >= 1.0) {
        set_pos(position.x, 1.0f - y_lenght / 2);
    }
    if(position.y - y_lenght / 2 <= -1.0) {
        set_pos(position.x, -1.0f + y_lenght / 2);
    }
}