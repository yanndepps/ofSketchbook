#ifdef GL_ES
precision mediump float;
#endif

uniform vec2 u_resolution;
uniform vec3 u_mouse;
uniform float u_time;

// a separate function that return a specific color
vec4 red() {
    return vec4(1.0, 0.0, 0.0, 1.0);
}

void main() {
    vec2 st = gl_FragCoord.st / u_resolution;

    // multiple ways of constructing vec4 types
    // vec4 color = vec4(vec3(1.0, 0.0, 1.0), 1.0);

    vec4 color = red();

    // gl_FragColor = vec4(st.x, 0.0, st.y, 1.0);
    gl_FragColor = vec4(color);
}
