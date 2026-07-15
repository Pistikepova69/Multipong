#ifndef SHADER_H
#define SHADER_H


#include <glm/fwd.hpp>
#include <glm/glm.hpp>
#include <string>

class Shader {
    unsigned int id;
  
  public:
    void create_shader(const std::string& vertex_shader_path,
                       const std::string& fragment_shader_path);
    void use();
    void set_mat4(const std::string& uniform_name, const glm::mat4& matrix);
    void set_vec4(const std::string& uniform_name, const glm::vec4& vector);
    void set_vec3(const std::string& uniform_name, const glm::vec3& vector);
    void set_float(const std::string& uniform_name, const float& number);
    void set_int(const std::string& uniform_name, const int& number);

    Shader(const std::string& vertex_shader_path,
           const std::string& fragment_shader_path)
        : id{0} {
        create_shader(vertex_shader_path, fragment_shader_path);
    }

    Shader() = default;

    void delete_shader();

    ~Shader();
};

#endif