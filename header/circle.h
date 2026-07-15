#ifndef CIRCLE_H
#define CIRCLE_H

#include <glm/fwd.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "shader.h"

class Circle {
    glm::vec4 colour;
    glm::vec3 position;
    float radius;
    unsigned int VAO, VBO, EBO;
    void init_gl_resources();

  public:
    Circle(float rad, float x_pos, float y_pos, float red, float green,
           float blue);

    static Shader& get_circ_shader();

    void render();
    void shift(float x_shift, float y_shift);
};

#endif