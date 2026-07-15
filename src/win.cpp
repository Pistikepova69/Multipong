#include "win.h"

#include <exception>
#include <print>

#include "GLFW/glfw3.h"
#include "glm/ext/matrix_clip_space.hpp"

void Win::update_projection() {
    float aspect = (float) width / (float) height;
    if(aspect >= 1.0f) {
        projection = glm::ortho(-aspect, aspect, -1.0f, 1.0f);
    }
    else {
        projection = glm::ortho(-1.0f, 1.0f, -1.0f / aspect, 1.0f / aspect);
    }
}

void Win::size_callback(GLFWwindow* window, int new_width, int new_height) {
    Win* win = (Win*) glfwGetWindowUserPointer(window);
    win->handle_resize(new_width, new_height);
}

void Win::handle_resize(int new_width, int new_height) {
    width = new_width;
    height = new_height;
    update_projection();
    glViewport(0, 0, width, height);
}

Win::Win(int width, int height, const std::string& title)
    : width{width}, height{height}, title{title} {
    init();
}

void Win::init() {
    int init = glfwInit();
    if(init == 0) {
        std::print("glfwInit failed\n");
        std::terminate();
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
    glfwMakeContextCurrent(window);
    int version = gladLoadGL(glfwGetProcAddress);
    if(version == 0) {
        std::print("Failed to initialize OpenGL context\n");
        glfwTerminate();
        std::terminate();
    }
    std::println("Loaded OpenGL");
    glViewport(0, 0, width, height);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


    glfwSetWindowUserPointer(window, this);

    glfwSetWindowSizeCallback(window, size_callback);

    update_projection();
}

Win::operator GLFWwindow*() { return window; }

Win::~Win() { glfwTerminate(); }

int Win::get_window_height() const { return height; }

int Win::get_window_width() const { return width; }

glm::mat4 Win::get_projection() const { return projection; }

double Win::get_time() const { return glfwGetTime(); }

void Win::set_key_callback(void(*key_callback)(GLFWwindow*, int, int, int, int)) {
    glfwSetKeyCallback(window, key_callback);
}