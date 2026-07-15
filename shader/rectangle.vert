#version 460 core

layout(location = 0) in vec3 in_position;

uniform mat4 model;
uniform mat4 proj;

void main() {
    gl_Position = proj * model * vec4(in_position, 1.0);
}