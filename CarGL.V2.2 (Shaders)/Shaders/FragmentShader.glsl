precision mediump float;  // Precisión media, en algunas gráficas no se soporta (depende de la versión de GLSL), en ese caso comentar o quitar esta línea

varying vec4 v_Color;

// Texturas

varying vec2 v_TextureCoord;
varying float v_Specular;
uniform sampler2D u_Sampler;
uniform int activada;

void main() {
    if (activada == 0) {
        gl_FragColor = v_Color+vec4(1,1,1,1)*v_Specular;
    } else {
        gl_FragColor = texture2D(u_Sampler, v_TextureCoord) * v_Color +vec4(1,1,1,1)*v_Specular;
    }
}
