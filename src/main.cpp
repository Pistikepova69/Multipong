// clang-format off
#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
// clang-format on

#include "ball.h"
#include "bar.h"
#include "win.h"

void key_callback(GLFWwindow* window, int key, int scancode, int action,
                  int mods);

Win window;
std::vector<Bar> bars{
    {0.05, 0.5, 1.7, 1, 0, 0, window, GLFW_KEY_UP, GLFW_KEY_DOWN, 2},
    {0.05, 0.5, -1.7, 1, 0, 0, window, GLFW_KEY_W, GLFW_KEY_S, 2}};
    
    int main() {
        window.set_key_callback(key_callback);
        Ball ball(0.03, 1, 1, 0, window, 0.05);



    while(!glfwWindowShouldClose(window)) {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        for(Bar& bar : bars) {
            bar.render();
        }
        ball.update(bars);
        ball.render();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }


    glfwTerminate();
}

void key_callback(GLFWwindow* window, int key, int scancode, int action,
                  int mods) {
    for(Bar& bar : bars) {
        bar.handle_input(key, action);
    }
}