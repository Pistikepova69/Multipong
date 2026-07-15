#version 460 core

layout(location = 0) in vec3 in_position;

uniform mat4 model;

out vec3 fragment_position;

void main() {
    gl_Position = model * vec4(in_position, 1.0);
    fragment_position = in_position;
}