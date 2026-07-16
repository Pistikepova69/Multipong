#ifndef WIN_H
#define WIN_H

// clang-format off
#include <glad/gl.h>
#include <GLFW/glfw3.h>
// clang-format on  
#include <glm/glm.hpp>
#include <string>



class Win{
    GLFWwindow* window;
    int width, height;
    std::string title;
    glm::mat4 projection;
    
    
    void update_projection();
    void init();
    static void size_callback(GLFWwindow *window, int new_width, int new_height);
    void handle_resize(int new_width, int new_height);

    public:

    Win(int width = 800, int height = 450, const std::string& title="");
    operator GLFWwindow*();

    int get_window_height() const;
    int get_window_width() const;
    glm::mat4 get_projection() const;

    double get_time() const;
    void set_key_callback(void(*key_callback)(GLFWwindow*, int, int, int, int));

    ~Win();
};


#endif