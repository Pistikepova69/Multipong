#include "circle.h"
// clang-format off
#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include "glm/ext/vector_float3.hpp"
#include "quad.h"
// clang-format on

Circle::Circle(float rad, float x_pos, float y_pos, float red, float green,
               float blue, const Win& window)
    : Quad(x_pos, y_pos, red, green, blue, window), radius(rad) {}

Circle::Circle(float rad, glm::vec2 pos, glm::vec3 colour, const Win& window)
    : Quad(pos, colour, window), radius(rad) {}

Shader& Circle::get_shader() {
    static Shader shader{SHADER "circle.vert", SHADER "circle.frag"};
    return shader;
}

void Circle::render() {
    get_shader().use();
    get_shader().set_mat4("model",
                          glm::scale(glm::translate(glm::mat4{1}, position),
                                     glm::vec3{radius, radius, 1}));
    get_shader().set_mat4("proj", window.get_projection());
    get_shader().set_vec4("colour", colour);

    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}
