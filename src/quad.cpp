#include "quad.h"

#include "shape_base.h"

Quad::Quad(float x_pos, float y_pos, float red, float green, float blue,
           const Win& window)
    : Shape_Base(x_pos, y_pos, red, green, blue, window) {
    init_gl_resources();
}

Quad::Quad(glm::vec2 pos, glm::vec3 colour, const Win& window)
    : Shape_Base(pos, colour, window) {
    init_gl_resources();
}

void Quad::init_gl_resources() {
    glm::vec3 vertices[4]{
        glm::vec3{-1, 1, 0},   // top left
        glm::vec3{1, 1, 0},    // top right
        glm::vec3{-1, -1, 0},  // bottom left
        glm::vec3{1, -1, 0}    // bottom right
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