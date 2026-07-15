// clang-format off
#include <glad/gl.h>
#include <GLFW/glfw3.h>
// clang-format on

#include "circle.h"
#include "rectangle.h"
#include "win.h"

int main() {
    Win window;

    // Rectangle kocka(1, 0.5, 0, 0, 1, 1, 1);

    Circle kor(1, 0, 0, 1, 1, 1);
    Circle kor2(0.1, 0, 0, 1, 0, 1);

    while(!glfwWindowShouldClose(window)) {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        kor.render();
        kor2.render();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }


    glfwTerminate();
}