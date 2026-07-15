// clang-format off
#include <glad/gl.h>
#include <GLFW/glfw3.h>
// clang-format on
#include <print>

#include "circle.h"
#include "rect.h"

int main() {
    int init = glfwInit();
    if(init == 0) {
        std::print("glfwInit failed\n");
        return -1;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 800, "Multipong", NULL, NULL);
    glfwMakeContextCurrent(window);
    int version = gladLoadGL(glfwGetProcAddress);
    if(version == 0) {
        std::print("Failed to initialize OpenGL context\n");
        glfwTerminate();
        return -1;
    }
    std::println("Loaded OpenGL");
    glViewport(0, 0, 800, 800);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


    // Rectangle kocka(1, 0.5, 0, 0, 1, 1, 1);

    Circle kor(1, 0, 0, 1, 1, 1);
    Circle kor2(0.5, 0, 0, 1, 0, 1);

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