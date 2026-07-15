#ifndef WIN_H
#define WIN_H

// clang-format off
#include <glad/gl.h>
#include <GLFW/glfw3.h>
// clang-format on  
#include <string>



class Win{
    GLFWwindow* window;
    int width, height;
    std::string title;
    void init();
    static void size_callback(GLFWwindow *window, int new_width, int new_height);
    void handle_resize(int new_width, int new_height);

    public:

    Win(int width = 800, int height = 800, const std::string& title="");
    operator GLFWwindow*();

    ~Win();
};


#endif