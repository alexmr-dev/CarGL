
// PARA LAS TEXTURAS
attribute vec2 a_TextureCoord;      //Texturas
varying vec2 v_TextureCoord;        //Texturas
varying float v_Specular;                 //Luz

attribute vec4 a_Position;          // in: Posicián de cada vártice
attribute vec3 a_Normal;            // in: Normal de cada vártice

uniform mat4 u_ProjectionMatrix;    // in: Matriz Projection
uniform mat4 u_MVMatrix;            // in: Matriz ModelView
uniform mat4 u_VMatrix;             // in: Matriz View (cámara)
uniform vec4 u_Color;               // in: Color del objeto

uniform int  u_Luz0;                // in: Indica si la luz 0 está encedida
uniform int  u_Luz1;                // in: Indica si la luz 1 está encedida
uniform int  u_Luz2;                // in: Indica si la luz 2 está encedida

// Posicionamiento
uniform vec4 u_Position_Luz0;
uniform vec4 u_Position_Luz1;
uniform vec4 u_Position_Luz2;

// Intensidad
uniform float u_Intensidad0;
uniform float u_Intensidad1;
uniform float u_Intensidad2;

// Seleccion
uniform int u_selection_enabled;
varying vec4 v_Color;               // out: Color al fragment shader

void main(){
    if(u_selection_enabled == 1)
    {
        vec3 P = vec3(u_MVMatrix * a_Position);
        v_Color = vec4(u_Color.x, u_Color.x, u_Color.x, 0);
        v_TextureCoord = a_TextureCoord;
        gl_Position = u_ProjectionMatrix * vec4(P, 1.0);
    }
    else
    {
        // Posicion de la luz
        vec4  LightPos0 = u_VMatrix * u_Position_Luz0;
        vec4  LightPos1 = u_VMatrix * u_Position_Luz1;
        vec4  LightPos2 = u_VMatrix * u_Position_Luz2;

        vec3 P = vec3(u_MVMatrix * a_Position);             // Posicion del vertice
        vec3 N = vec3(u_MVMatrix * vec4(a_Normal, 0.0));    // Normal del vertice

        float d0 = length(LightPos0.xyz - P);               // Distancia de la luz 1
        float d1 = length(LightPos1.xyz - P);               // Distancia de la luz 2
        float d2 = length(LightPos2.xyz - P);               // Distancia de la luz 3

        vec3  L0 = normalize(LightPos0.xyz - P);            // Vector luz 1
        vec3  L1 = normalize(LightPos1.xyz - P);            // Vector luz 2
        vec3  L2 = normalize(LightPos2.xyz - P);            // Vector luz 3

        vec3 viewVec = normalize(vec3(-P));                 // Cálculo del vector de vista normalizado

        float ambient = 0.15;                               // Luz ambiente (15%)

        float diffuse0 = 0.0;
        float diffuse1 = 0.0;
        float diffuse2 = 0.0;

        float specular0 = 0.0;
        float specular1 = 0.0;
        float specular2 = 0.0;

        if (u_Luz0 > 0) {                                   // Si la luz 0 está encendida se calcula la intesidad difusa de L
            diffuse0 = max(dot(N, L0), 0.0);                // Cálculo de la int. difusa
            // Cálculo de la atenuación
            float attenuation0 = 100.0/(0.25+(0.01*d0)+(0.003*d0*d0));
            diffuse0 = diffuse0*attenuation0*u_Intensidad0;

            //Cálculo de la especular.
            vec3 lightVec0 = L0;
            vec3 reflectVec0 = reflect(-lightVec0, N);
            specular0 = clamp(dot(reflectVec0, viewVec),0.0, 1.0);
            specular0 = pow(specular0, 5.0);
            specular0 = specular0*u_Intensidad0;
        }

        if (u_Luz1 > 0) {                                    // Si la luz 0 esta encendida se calcula la intesidad difusa de L
            diffuse1 = max(dot(N, L1), 0.0);                 // Cálculo de la int. difusa
            // Cálculo de la atenuación
            float attenuation1 = 80.0/(0.25+(0.01*d1)+(0.003*d1*d1));
            diffuse1 = diffuse1*attenuation1*u_Intensidad1;

            //Cálculo de la especular.
            vec3 lightVec1 = L1;
            vec3 reflectVec1 = reflect(-lightVec1, N);
            specular1 = clamp(dot(reflectVec1, viewVec),0.0, 1.0);
            specular1 = pow(specular1, 5.0);
            specular1 = specular1*u_Intensidad1;
        }

        if (u_Luz2 > 0) {                                    // Si la luz 0 está encendida se calcula la intesidad difusa de L
            diffuse2 = max(dot(N, L2), 0.0);                 // Cálculo de la int. difusa
            // Cálculo de la atenuación
            float attenuation2 = 80.0/(0.25+(0.01*d2)+(0.003*d2*d2));
            diffuse2 = diffuse2*attenuation2*u_Intensidad2;

            // Cálculo de la especular.
            vec3 lightVec2 = L2;
            vec3 reflectVec2 = reflect(-lightVec2, N);
            specular2 = clamp(dot(reflectVec2, viewVec),0.0, 1.0);
            specular2 = pow(specular2, 5.0);
            specular2 = specular2*u_Intensidad2;
        }

        // Texturas
        float sumDiffuse = diffuse0 + diffuse1 + diffuse2;

        v_Specular = specular0 + specular1 + specular2;

        // Cálculo final de la luz
        v_Color = u_Color * (ambient + sumDiffuse);
        v_TextureCoord = a_TextureCoord;
        gl_Position = u_ProjectionMatrix * vec4(P, 1.0);
    }
}
