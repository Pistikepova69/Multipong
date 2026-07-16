#ifndef SHAPE_BASE_H
#define SHAPE_BASE_H
#include <glm/fwd.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "shader.h"
#include "win.h"

class Shape_Base {
  protected:
    glm::vec4 colour;
    glm::vec3 position;
    unsigned int VAO, VBO, EBO;
    const Win& window;
    virtual void init_gl_resources() =0;

  public:
    Shape_Base(float x_pos, float y_pos, float red, float green, float blue,
               const Win& window);
    Shape_Base(glm::vec2 pos, glm::vec3 colour, const Win& window);

    virtual Shader& get_shader() = 0;
    virtual void render() = 0;
    virtual ~Shape_Base() = default;
    void shift(float x_shift, float y_shift);
    void shift(const glm::vec2& shift);
    void set_pos(float x_pos, float y_pos);
    void set_pos(glm::vec2 pos);
    glm::vec3 get_pos() const;
};

#endif