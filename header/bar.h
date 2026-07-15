#ifndef BAR_H
#define BAR_H

#include "rectangle.h"

class Bar : public Rectangle {
    int up_key, down_key;
    float speed;
    bool up_pressed, down_pressed;
    double deltatime, last_time;



  public:
    void handle_input(int key, int action);
    Bar(float x_size, float y_size, float x_pos, float red, float green,
        float blue, const Win& window, int up_key, int down_key, float speed);
    void render();
    void update();
};


#endif