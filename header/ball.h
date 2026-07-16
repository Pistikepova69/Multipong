#ifndef BALL_H
#define BALL_H
#include <random>
#include <vector>

#include "bar.h"
#include "circle.h"
#include "glm/ext/vector_float2.hpp"

class Ball : public Circle {
  protected:
    double deltatime, last_time;
    glm::vec2 speed;
    static std::random_device random_device;
    std::mt19937 generator;
    float x_acceleration;
    void handle_bar_collision(const Bar& bar);
    void handle_edge_collision();
    void init();
    void handle_exit();
    float random_sign();
    float random_uniform(float lower_bound, float upper_bound);
    float random_normal(float mean, float dev, bool bounded = false,
                        float lower_bound = -1, float upper_bound = 1);

  public:
    Ball(float rad, float red, float green, float blue, const Win& window,
         float x_acceleration);
    void update(const std::vector<Bar>& bars);
};

#endif