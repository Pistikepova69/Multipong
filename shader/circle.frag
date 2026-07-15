#version 460 core
in vec3 fragment_position;
uniform vec4 colour;
out vec4 fragment_colour;

void main() {
    float dist = distance(fragment_position.xy, vec2(0.0));
    float alpha = smoothstep(1.0, 0.99, dist);
    fragment_colour = vec4(colour.rgb, colour.a * alpha);
}