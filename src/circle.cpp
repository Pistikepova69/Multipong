#include "circle.h"
// clang-format off
#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include "glm/ext/matrix_float4x4.hpp"
#include "glm/ext/matrix_transform.hpp"
#include "glm/ext/vector_float3.hpp"
// clang-format on

Circle::Circle(float rad, float x_pos, float y_pos, float red, float green,
               float blue)
    : colour{red, green, blue, 1}, position{x_pos, y_pos, 0}, radius(rad),
      VAO(0), VBO(0), EBO(0) {
    if(VAO == 0 || VBO == 0 || EBO == 0) {
        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &VBO);
        init_gl_resources();
    }
}

Shader& Circle::get_circ_shader() {
    static Shader shader{SHADER "circle.vert", SHADER "circle.frag"};
    return shader;
}

void Circle::init_gl_resources() {
    glm::vec3 vertices[4]{
        glm::vec3{-radius, radius, 0},   // top left
        glm::vec3{radius, radius, 0},    // top right
        glm::vec3{-radius, -radius, 0},  // bottom left
        glm::vec3{radius, -radius, 0}    // bottom right
    };

    unsigned int indices[6]{2, 0, 1,  //
                            2, 3, 1};
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices,
                 GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3),
                          (void*) 0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);
}

void Circle::render() {
    Circle::get_circ_shader().use();
    Circle::get_circ_shader().set_mat4("model",
                                       glm::translate(glm::mat4{1}, position));
    Circle::get_circ_shader().set_vec4("colour", colour);
    Circle::get_circ_shader().set_float("radius", radius);
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}