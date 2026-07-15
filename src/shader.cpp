// clang-format off
#include <glad/gl.h>
#include <GLFW/glfw3.h>
// clang-format on
#include "shader.h"

#include <fstream>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <sstream>
#include <string>

std::string read_shader(const std::string& path) {
    std::ifstream in(path);
    std::stringstream input;
    input << in.rdbuf();
    // std::cout << input.str() << "a\n";
    return input.str();
}

void validate_shader_compilation(unsigned int shader) {
    GLint shader_compiled;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &shader_compiled);
    if(shader_compiled != GL_TRUE) {
        GLsizei log_length = 0;
        GLchar message[1024];
        glGetShaderInfoLog(shader, 1024, &log_length, message);
        std::cerr << message << "\n";
    }
}

void validate_shader_linking(unsigned int program) {
    GLint program_linked;
    glGetProgramiv(program, GL_LINK_STATUS, &program_linked);
    if(program_linked != GL_TRUE) {
        GLsizei log_length = 0;
        GLchar message[1024];
        glGetProgramInfoLog(program, 1024, &log_length, message);
        std::cerr << message << "\n";
    }
}

void Shader::create_shader(const std::string& vertex_shader_path,
                           const std::string& fragment_shader_path) {
    std::string vertex_source = read_shader(vertex_shader_path);
    std::string fragment_source = read_shader(fragment_shader_path);
    const char *vertex_cstr = vertex_source.c_str(),
               *fragment_cstr = fragment_source.c_str();

    unsigned int vertex, fragment;
    vertex = glCreateShader(GL_VERTEX_SHADER);
    fragment = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(vertex, 1, &vertex_cstr, NULL);
    glShaderSource(fragment, 1, &fragment_cstr, NULL);


    glCompileShader(vertex);
    validate_shader_compilation(vertex);


    glCompileShader(fragment);
    validate_shader_compilation(fragment);

    id = glCreateProgram();
    glAttachShader(id, vertex);
    glAttachShader(id, fragment);
    glLinkProgram(id);

    validate_shader_linking(id);
    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

void Shader::set_mat4(const std::string& uniform_name,
                      const glm::mat4& matrix) {
    use();
    GLint uniform_location = glGetUniformLocation(id, uniform_name.c_str());
    glUniformMatrix4fv(uniform_location, 1, GL_FALSE, glm::value_ptr(matrix));
}

void Shader::set_vec4(const std::string& uniform_name,
                      const glm::vec4& vector) {
    use();
    GLint uniform_location = glGetUniformLocation(id, uniform_name.c_str());
    glUniform4fv(uniform_location, 1, glm::value_ptr(vector));
}

void Shader::set_vec3(const std::string& uniform_name,
                      const glm::vec3& vector) {
    use();
    GLint uniform_location = glGetUniformLocation(id, uniform_name.c_str());
    glUniform3fv(uniform_location, 1, glm::value_ptr(vector));
}

void Shader::set_float(const std::string& uniform_name, const float& number) {
    use();
    GLint uniform_location = glGetUniformLocation(id, uniform_name.c_str());
    glUniform1fv(uniform_location, 1, &number);
}

void Shader::set_int(const std::string& uniform_name, const int& number) {
    use();
    GLint uniform_location = glGetUniformLocation(id, uniform_name.c_str());
    glUniform1iv(uniform_location, 1, &number);
}

void Shader::use() { glUseProgram(id); }

void Shader::delete_shader() {
    glDeleteProgram(id);
    id = 0;
}

Shader::~Shader() {
    if(id != 0 && glfwGetCurrentContext() != nullptr) {
        delete_shader();
    }
}