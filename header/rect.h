#ifndef RECT_H
#define RECT_H

#include <glm/fwd.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "shader.h"

class Rectangle {
  public:
    glm::vec4 colour;
    glm::vec3 position;
    float x_lenght, y_lenght;

    Rectangle(float x_size, float y_size, float x_pos, float y_pos, float red,
              float green, float blue);

    static Shader& get_rect_shader();

    void render();
    unsigned int VAO, VBO, EBO;

    void init_gl_resources();
};


#endif