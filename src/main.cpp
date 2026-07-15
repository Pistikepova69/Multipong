// clang-format off
#include <glad/gl.h>
#include <GLFW/glfw3.h>
// clang-format on

#include "bar.h"
#include "circle.h"
#include "rectangle.h"
#include "win.h"

void key_callback(GLFWwindow* window, int key, int scancode, int action,
                  int mods);

Win window;
Bar b{0.05, 0.2, 1.5, 1, 0, 0, window, GLFW_KEY_W, GLFW_KEY_S, 1};

int main() {
    window.set_key_callback(key_callback);


    while(!glfwWindowShouldClose(window)) {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        b.render();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }


    glfwTerminate();
}

void key_callback(GLFWwindow* window, int key, int scancode, int action,
                  int mods) {
    b.handle_input(key, action);
}