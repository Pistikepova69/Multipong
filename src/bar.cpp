#include "bar.h"

#include "GLFW/glfw3.h"

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
    : mesh(x_size, y_size, x_pos, 0, red, green, blue, window), up_key(up_key),
      down_key(down_key), speed(speed), up_pressed(false), down_pressed(false) {
}

void Bar::render() {
    update();
    mesh.render();
}

void Bar::update() {
    float deltatime = (float) mesh.get_deltatime();
    mesh.shift(
        0, speed * deltatime * (float) ((int) up_pressed - (int) down_pressed));
}