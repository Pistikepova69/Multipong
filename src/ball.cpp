#include "ball.h"

#include <algorithm>
#include <cstdlib>
#include <random>
#include <vector>

#include "circle.h"

std::random_device Ball::random_device{};

float Ball::random_sign() {
    std::uniform_int_distribution<int> distribrution(0, 1);
    return distribrution(generator) ? 1 : -1;
}

float Ball::random_normal(float mean, float dev, bool bounded,
                          float lower_bound, float upper_bound) {
    std::normal_distribution<float> distribrution(mean, dev);
    float number = distribrution(generator);
    if(bounded) {
        number = std::min(upper_bound, std::max(lower_bound, number));
    }
    return number;
}

float Ball::random_uniform(float lower_bound, float upper_bound) {
    std::uniform_real_distribution<float> distribution(lower_bound,
                                                       upper_bound);
    return distribution(generator);
}

void Ball::handle_edge_collision() {
    if(position.y + radius >= 1) {
        speed.y = -speed.y;
    }
    if(position.y - radius <= -1) {
        speed.y = -speed.y;
    }
}

void Ball::handle_bar_collision(const Bar& bar) {
    glm::vec3 bar_pos = bar.get_pos();
    glm::vec2 bar_sidelengths = bar.get_size();
    float closest_x =
        std::min(bar_pos.x + bar_sidelengths.x / 2,
                 std::max(bar_pos.x - bar_sidelengths.x / 2, position.x));
    float closest_y =
        std::min(bar_pos.y + bar_sidelengths.y / 2,
                 std::max(bar_pos.y - bar_sidelengths.y / 2, position.y));

    float dx = position.x - closest_x;
    float dy = position.y - closest_y;

    float ds_2 = dx * dx + dy * dy;
    if(ds_2 <= radius * radius) {
        speed.x = -speed.x;
        float y_speed_sign = speed.y > 0 ? 1 : -1;
        speed.y =
            std::abs(bar_pos.y - closest_y) * std::abs(speed.x) * y_speed_sign * 2;
    }
    
}

void Ball::update(const std::vector<Bar>& bars) {
    double time = window.get_time();
    if(last_time == 0) {
        last_time = time;
        deltatime = 0;
    }
    else {
        deltatime = time - last_time;
        last_time = time;
    }
    handle_edge_collision();
    for(const Bar& bar : bars) {
        handle_bar_collision(bar);
    }
    handle_exit();
    float x_speed_sign = speed.x > 0 ? 1 : -1;
    speed.x += x_acceleration * (float) deltatime * x_speed_sign / 2;
    shift(speed * (float) deltatime);
    speed.x += x_acceleration * (float) deltatime * x_speed_sign / 2;
}

void Ball::init() {
    position.x = 0;
    position.y = random_normal(1, 0.5, true, -1.0f + radius + 0.02f,
                               1.0f - radius - 0.02f);
    speed.x = random_uniform(1, 2) * random_sign();
    speed.y = random_uniform(0, 1) * random_sign() * speed.x;
}

void Ball::handle_exit() {
    if(position.x >= 2.5) {
        // score things
        // wait
        init();
    }
    if(position.x <= -2.5) {
        // score things
        // wait
        init();
    }
}

Ball::Ball(float rad, float red, float green, float blue, const Win& window,
           float x_acceleration)
    : Circle(rad, 0, 0, red, green, blue, window), deltatime(0), last_time(0),
      speed(0), generator(Ball::random_device()),
      x_acceleration(x_acceleration) {
    init();
}
