#ifndef CIRCLE_H
#define CIRCLE_H

#include "quad.h"

class Circle : public Quad {
    float radius;

  public:
    Circle(float rad, float x_pos, float y_pos, float red, float green,
           float blue, const Win& window);
    Circle(float rad, glm::vec2 pos, glm::vec3 colour, const Win& window);
    Shader& get_shader() override;
    void render() override;
};

#endif