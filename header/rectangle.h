#ifndef RECT_H
#define RECT_H


#include "quad.h"

class Rectangle : public Quad {
  protected:
    float x_lenght, y_lenght;

  public:
    Rectangle(float x_size, float y_size, float x_pos, float y_pos, float red,
              float green, float blue, const Win& window);
    Rectangle(glm::vec2 size, glm::vec2 pos, glm::vec3 colour,
              const Win& window);
    Shader& get_shader() override;

    void render() override;
    glm::vec2 get_size() const;
};


#endif