#ifndef QUAD_H
#define QUAD_H

#include "shape_base.h"

class Quad : public Shape_Base {
  public:
    Quad(float x_pos, float y_pos, float red, float green, float blue,
         const Win& window);
    Quad(glm::vec2 pos, glm::vec3 colour, const Win& window);
    void init_gl_resources() override;
};

#endif