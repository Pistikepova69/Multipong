#include "shape_base.h"

Shape_Base::Shape_Base(float x_pos, float y_pos, float red, float green,
                       float blue, const Win& window)
    : colour{red, green, blue, 1}, position{x_pos, y_pos, 0}, VAO(0), VBO(0),
      EBO(0), window{window} {}

Shape_Base::Shape_Base(glm::vec2 pos, glm::vec3 colour, const Win& window)
    : position(pos, 0), colour(colour, 0), VAO(0), VBO(0), EBO(0),
      window(window) {}

void Shape_Base::shift(float x_shift, float y_shift) {
    position.x += x_shift;
    position.y += y_shift;
}

void Shape_Base::shift(const glm::vec2& shift) {
    position += glm::vec3{shift, 0};
}