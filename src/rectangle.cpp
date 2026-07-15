#include "rectangle.h"
// clang-format off
#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include "glm/ext/matrix_float4x4.hpp"
#include "glm/ext/matrix_transform.hpp"
#include "glm/ext/vector_float3.hpp"
#include "quad.h"
// clang-format on

Rectangle::Rectangle(float x_size, float y_size, float x_pos, float y_pos,
                     float red, float green, float blue, const Win& window)
    : Quad(x_pos, y_pos, red, green, blue, window), x_lenght(x_size),
      y_lenght(y_size) {}

Rectangle::Rectangle(glm::vec2 size, glm::vec2 pos, glm::vec3 colour, const Win& window)
    : Quad(pos, colour, window), x_lenght(size.x), y_lenght(size.y) {}

Shader& Rectangle::get_shader() {
    static Shader shader{SHADER "rectangle.vert", SHADER "rectangle.frag"};
    return shader;
}

void Rectangle::render() {
    

    get_shader().use();
    get_shader().set_mat4(
        "model", glm::scale(glm::translate(glm::mat4{1}, position),
                            glm::vec3(x_lenght / 2, y_lenght / 2, 1.0)));
    get_shader().set_mat4("proj", window.get_projection());
    get_shader().set_vec4("colour", colour);
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}