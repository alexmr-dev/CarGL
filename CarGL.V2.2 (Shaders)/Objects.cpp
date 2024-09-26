
/****************************************************************************************

    CarGL (Objects.cpp)

    Grado en Ingeniería Multimedia.
    Práctica de Gráficos por Computador.
    OpenGL con Shaders.
  ---------------------------------------------------------------------------------------

    2012 - 2022 (C) Juan Antonio Puchol García (puchol@dccia.ua.es)


*****************************************************************************************/

#include "Objects.h"
#include <GL/glui.h>

#include "load3ds.c"

// Variable para inicializar los vectores correpondientes con los valores iniciales
GLfloat light0_ambient_c[4] = {0.2f, 0.2f, 0.2f, 1.0f};
GLfloat light0_diffuse_c[4] = {0.8f, 0.8f, 0.8f, 1.0f};
GLfloat light0_specular_c[4] = {1.0f, 1.0f, 1.0f, 1.0f};
GLfloat light0_position_c[4] = {-100.0f, 100.0f, 50.0f, 1.0f};

GLfloat light1_ambient_c[4] = {0.2f, 0.2f, 0.2f, 1.0f};
GLfloat light1_diffuse_c[4] = {0.8f, 0.8f, 0.8f, 1.0f};
GLfloat light1_specular_c[4] = {1.0f, 1.0f, 1.0f, 1.0f};
GLfloat light1_position_c[4] = {0.0f, 100.0f, 0.0f, 1.0f};

GLfloat light2_ambient_c[4] = {0.2f, 0.2f, 0.2f, 1.0f};
GLfloat light2_diffuse_c[4] = {0.8f, 0.8f, 0.8f, 1.0f};
GLfloat light2_specular_c[4] = {1.0f, 1.0f, 1.0f, 1.0f};
GLfloat light2_position_c[4] = {100.0f, 100.0f, 0.0f, 1.0f};

GLfloat mat_ambient_c[4] = {0.7f, 0.7f, 0.7f, 1.0f};
GLfloat mat_diffuse_c[4] = {0.8f, 0.8f, 0.8f, 1.0f};
GLfloat mat_specular_c[4] = {1.0f, 1.0f, 1.0f, 1.0f};
GLfloat mat_shininess_c[1] = {100.0f};

// Matriz de 4x4 = (I)
float view_rotate_c[16] = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
float view_position_c[3] = {8.0, -6.0, -9.0};

float colores_acera[2][4] = {{0.77, 0.53, 0.83, 1.0}, {0.5, 0.5, 0.5, 1.0}};
float colores_arco_jap[2][4] = {{0.92, 0.05, 0.05, 1.0}, {0.5, 0.5, 0.5, 1.0}};
float colores_arbeloa[2][4] = {{0.84, 0.55, 0.03, 1.0}, {0.5, 0.5, 0.5, 1.0}};
float colores_arbol[2][4] = {{0.03, 0.84, 0.03, 1.0}, {0.5, 0.5, 0.5, 1.0}};
float colores_banco[2][4] = {{0.32, 0.37, 0.85, 1.0}, {0.5, 0.5, 0.5, 1.0}};
float colores_domo[2][4] = {{0.62, 0.66, 0.99, 1.0}, {0.5, 0.5, 0.5, 1.0}};
float colores_edificio[2][4] = {{0.72, 0.89, 0.44, 1.0}, {0.5, 0.5, 0.5, 1.0}};
float colores_pozo[2][4] = {{0.41, 0.51, 0.47, 1.0}, {0.5, 0.5, 0.5, 1.0}};
float colores_faro[2][4] = {{0.99, 0.99, 0.62, 1.0}, {0.5, 0.5, 0.5, 1.0}};
float colores_farola[2][4] = {{0.19, 0.19, 0.18, 1.0}, {0.5, 0.5, 0.5, 1.0}};
float colores_fuente[2][4] = {{0.82, 0.87, 0.87, 1.0}, {0.5, 0.5, 0.5, 1.0}};
float colores_semaforo[2][4] = {{0.01, 0.20, 0.20, 1.0}, {0.5, 0.5, 0.5, 1.0}};
float colores_senial[2][4] = {{0.70, 0.10, 0.47, 1.0}, {0.5, 0.5, 0.5, 1.0}};
float colores_marcador[2][4] = {{0.70, 0.10, 0.47, 1.0}, {0.5, 0.5, 0.5, 1.0}};
float colores_gimnasio[2][4] = {{0.52, 0.52, 0.52, 1.0}, {0.5, 0.5, 0.5, 1.0}};
float colores_cesped[2][4] = {{0.25, 0.47, 0.36, 1.0}, {0.5, 0.5, 0.5, 1.0}};
float colores_vallas[2][4] = {{0.47, 0.39, 0.25, 1.0}, {0.5, 0.5, 0.5, 1.0}};
float colores_pino[2][4] = {{0.11, 0.41, 0.21, 1.0}, {0.5, 0.5, 0.5, 1.0}};
float colores_panteon[2][4] = {{0.21, 0.21, 0.51, 1.0}, {0.5, 0.5, 0.5, 1.0}};
float colores_tienda[2][4] = {{0.55, 0.06, 0.62, 1.0}, {0.5, 0.5, 0.5, 1.0}};

float color_blanco[2][4] = {{1.0, 1.0, 1.0, 1.0}, {0.5, 0.5, 0.5, 1.0}};

float coloresc_c[2][4] = {{0.8, 0.5, 0.0, 1.0}, {0.5, 0.5, 0.5, 1.0}}; // Color del coche
float coloresr_c[2][4] = {{0.3, 0.3, 0.3, 1.0}, {1.0, 1.0, 1.0, 1.0}}; // Color de la carretera

//************************************************************** Variables de clase

TEscena escena;
TGui gui;

//************************************************************** Clase TPrimitiva

TPrimitiva::TPrimitiva(int DL, int t)
{

    ID = DL;
    tipo = t;

    sx = sy = sz = 1;
    rx = ry = rz = 0;
    switch (tipo)
    {
    case CARRETERA_ID:
    { // Creación de la carretera
        tx = ty = tz = 0;

        memcpy(colores, color_blanco, 8 * sizeof(float));

        //************************ Cargar modelos 3ds ***********************************
        // formato 8 floats por vértice (x, y, z, A, B, C, u, v)
        modelo0 = Load3DS("../../Modelos/Road_V2.3ds", &num_vertices0);
        // modelo1 = Load3DS("../../Modelos/Lines_V2.3ds", &num_vertices1);

        break;
    }
    case COCHE_ID:
    { // Creación del coche

        tx = -3.0;
        ty = 0.0;
        tz = -18.0;
        rr = 0.0;
        ry = 0.0;

        memcpy(colores, color_blanco, 8 * sizeof(float));

        //************************ Cargar modelos 3ds ***********************************
        // formato 8 floats por vértice (x, y, z, A, B, C, u, v)
        modelo0 = Load3DS("../../Modelos/Coche.3ds", &num_vertices0);
        // modelo0 = Load3DS("../../Modelos/Banco.3ds", &num_vertices0);
        modelo1 = Load3DS("../../Modelos/RuedaNueva.3ds", &num_vertices1);
        break;
    }
    case MARCADOR_ID:
    {
        ty = 0.1;
        memcpy(colores, colores_marcador, 8 * sizeof(float));
        modelo0 = Load3DS("../../Modelos/Marcador.3ds", &num_vertices0);
        break;
    }
    case ACERA_ID:
    {
        memcpy(colores, color_blanco, 8 * sizeof(float));
        modelo0 = Load3DS("../../Modelos/Acera_V2.3ds", &num_vertices0);
        break;
    }
    case ARCO_JAP_ID:
    {
        memcpy(colores, color_blanco, 8 * sizeof(float));
        modelo0 = Load3DS("../../Modelos/Arco_japones.3ds", &num_vertices0);
        break;
    }
    case ARBELOA_ID:
    {
        memcpy(colores, color_blanco, 8 * sizeof(float));
        modelo0 = Load3DS("../../Modelos/Arbeloa.3ds", &num_vertices0);
        break;
    }
    case ARBOL_ID:
    {
        memcpy(colores, color_blanco, 8 * sizeof(float));
        modelo0 = Load3DS("../../Modelos/Arbol.3ds", &num_vertices0);
        break;
    }
    case BANCO_ID:
    {
        memcpy(colores, color_blanco, 8 * sizeof(float));
        modelo0 = Load3DS("../../Modelos/Banco.3ds", &num_vertices0);
        break;
    }
    case CARTEL_ID:
    {
        memcpy(colores, color_blanco, 8 * sizeof(float));
        modelo0 = Load3DS("../../Modelos/Cartel.3ds", &num_vertices0);
        break;
    }
    case DOMO_ID:
    {
        memcpy(colores, color_blanco, 8 * sizeof(float));
        modelo0 = Load3DS("../../Modelos/Domo.3ds", &num_vertices0);
        break;
    }
    case EDIFICIO_ID:
    {
        memcpy(colores, color_blanco, 8 * sizeof(float));
        modelo0 = Load3DS("../../Modelos/Edificio.3ds", &num_vertices0);
        break;
    }
    case FARO_ID:
    {
        memcpy(colores, color_blanco, 8 * sizeof(float));
        modelo0 = Load3DS("../../Modelos/Faro.3ds", &num_vertices0);
        break;
    }
    case FAROLA_ID:
    {
        memcpy(colores, color_blanco, 8 * sizeof(float));
        modelo0 = Load3DS("../../Modelos/Farola.3ds", &num_vertices0);
        break;
    }
    case FUENTE_ID:
    {
        memcpy(colores, color_blanco, 8 * sizeof(float));
        modelo0 = Load3DS("../../Modelos/Fuente.3ds", &num_vertices0);
        break;
    }
    case POZO_ID:
    {
        memcpy(colores, color_blanco, 8 * sizeof(float));
        modelo0 = Load3DS("../../Modelos/Pozo.3ds", &num_vertices0);
        break;
    }
    case PANTEON_ID:
    {
        memcpy(colores, color_blanco, 8 * sizeof(float));
        modelo0 = Load3DS("../../Modelos/panteon.3ds", &num_vertices0);
        break;
    }
    case SENIAL_ID:
    {
        memcpy(colores, color_blanco, 8 * sizeof(float));
        modelo0 = Load3DS("../../Modelos/Senial.3ds", &num_vertices0);
        break;
    }
    case SEMAFORO_ID:
    {
        memcpy(colores, color_blanco, 8 * sizeof(float));
        modelo0 = Load3DS("../../Modelos/Semaforo.3ds", &num_vertices0);
        break;
    }
    case LINES_ID:
    {
        memcpy(colores, color_blanco, 8 * sizeof(float));
        modelo0 = Load3DS("../../Modelos/Lines_V2.3ds", &num_vertices0);
        break;
    }
    case GIMNASIO_ID:
    {
        memcpy(colores, color_blanco, 8 * sizeof(float));
        modelo0 = Load3DS("../../Modelos/Gimnasio.3ds", &num_vertices0);
        break;
    }
    case VALLAS_ID:
    {
        memcpy(colores, color_blanco, 8 * sizeof(float));
        modelo0 = Load3DS("../../Modelos/Vallas.3ds", &num_vertices0);
        break;
    }
    case CESPED_ID:
    {
        memcpy(colores, color_blanco, 8 * sizeof(float));
        modelo0 = Load3DS("../../Modelos/Cesped.3ds", &num_vertices0);
        break;
    }
    case CIELO_ID:
    {
        memcpy(colores, color_blanco, 8 * sizeof(float));
        modelo0 = Load3DS("../../Modelos/Cielo.3ds", &num_vertices0);
        break;
    }
    case PINO_ID:
    {
        memcpy(colores, color_blanco, 8 * sizeof(float));
        modelo0 = Load3DS("../../Modelos/Pino.3ds", &num_vertices0);
        break;
    }
    case TIENDA_ID:
    {
        memcpy(colores, color_blanco, 8 * sizeof(float));
        modelo0 = Load3DS("../../Modelos/Tienda.3ds", &num_vertices0);
        break;
    }

    } // switch
}

void __fastcall TPrimitiva::Render(int seleccion, bool reflejo)
{
    glm::mat4 modelMatrix;
    glm::mat4 modelViewMatrix;
    switch (tipo)
    {

    case CARRETERA_ID:
    {
        if (escena.show_road)
        {
            float ttx, tty, ttz;
            ttx = tx;
            tty = ty;
            ttz = tz;

            glUniform4fv(escena.uColorLocation, 1, (const GLfloat *)colores[0]);
            modelMatrix = glm::mat4(1.0f);
            modelMatrix = glm::translate(modelMatrix, glm::vec3(ttx, tty, ttz));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(sx, sy, sz));

            modelViewMatrix = escena.viewMatrix * modelMatrix;
            glUniformMatrix4fv(escena.uMVMatrixLocation, 1, GL_FALSE, &modelViewMatrix[0][0]);

            glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
            glStencilFunc(GL_ALWAYS, 0, 0xFF);

            glBindTexture(GL_TEXTURE_2D, escena.texturas_id[5]);
            glUniform1i(escena.activadaLocation, 1);
            glUniform1i(escena.u_SamplerLocation, 0);
            glActiveTexture(GL_TEXTURE0);

            glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0);
            glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0 + 3);

            glVertexAttribPointer(escena.aTextureCoordLocation, UV_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0 + 6);

            glDrawArrays(GL_TRIANGLES, 0, num_vertices0);
        }
        break;
    } // case CARRETERA_ID:
    case EDIFICIO_ID:
    {
        if (escena.show_objetos)
        {
            float ttx, tty, ttz;
            ttx = tx;
            tty = ty;
            ttz = tz;

            glUniform4fv(escena.uColorLocation, 1, (const GLfloat *)colores[0]);
            modelMatrix = glm::mat4(1.0f);
            modelMatrix = glm::translate(modelMatrix, glm::vec3(ttx, tty, ttz));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(sx, sy, sz));

            modelViewMatrix = escena.viewMatrix * modelMatrix;
            glUniformMatrix4fv(escena.uMVMatrixLocation, 1, GL_FALSE, &modelViewMatrix[0][0]);

            glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
            glStencilFunc(GL_ALWAYS, 0, 0xFF);

            glBindTexture(GL_TEXTURE_2D, escena.texturas_id[8]);
            glUniform1i(escena.activadaLocation, 1);
            glUniform1i(escena.u_SamplerLocation, 0);
            glActiveTexture(GL_TEXTURE0);

            glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0);
            glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0 + 3);

            glVertexAttribPointer(escena.aTextureCoordLocation, UV_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0 + 6);

            glDrawArrays(GL_TRIANGLES, 0, num_vertices0);
        }
        break;
    } // case CARRETERA_ID:
    case COCHE_ID:
    {
        if (escena.show_car)
        {
            float ttx, tty, ttz;
            ttx = tx;
            tty = ty;
            ttz = tz;
            glUniform4fv(escena.uColorLocation, 1, (const GLfloat *)colores[0]);
            // Asociamos los vértices y sus normales
            glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0);
            glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0 + 3);
            glUniform1i(escena.activadaLocation, 0);
            // Cálculo de la matriz modelo
            modelMatrix = glm::mat4(1.0f); // matriz identidad
            modelMatrix = glm::translate(modelMatrix, glm::vec3(tx, ty, tz));
            modelMatrix = glm::rotate(modelMatrix, (float)glm::radians(0.0), glm::vec3(1, 0, 0)); // en radianes
            // Rotar coche en el giro
            modelMatrix = glm::rotate(modelMatrix, (float)glm::radians(ry), glm::vec3(0, 1, 0)); // en radianes

            modelViewMatrix = escena.viewMatrix * modelMatrix;

            glBindTexture(GL_TEXTURE_2D, escena.texturas_id[21]);
            glUniform1i(escena.activadaLocation, 1);
            glUniform1i(escena.u_SamplerLocation, 0);
            glActiveTexture(GL_TEXTURE0);

            glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
            glStencilFunc(GL_ALWAYS, ID, 0xFF);

            glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0);
            glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0 + 3);
            glVertexAttribPointer(escena.aTextureCoordLocation, UV_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0 + 6);

            // Envía nuestra ModelView al Vertex Shader
            glUniformMatrix4fv(escena.uMVMatrixLocation, 1, GL_FALSE, &modelViewMatrix[0][0]);

            glDrawArrays(GL_TRIANGLES, 0, num_vertices0);
        }

        if (escena.show_wheels)
        {
            glUniform4fv(escena.uColorLocation, 1, (const GLfloat *)colores[1]);
            // Asociamos los vértices y sus normales
            glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo1);
            glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo1 + 3);

            // RUEDA Delantera Izquierda : Cálculo de la matriz modelo
            modelMatrix = glm::mat4(1.0f); // matriz identidad

            modelMatrix = glm::translate(modelMatrix, glm::vec3(tx + 1.05, ty + 0.45, tz));
            modelMatrix = glm::translate(modelMatrix, glm::vec3(-1.05, 0, -0.03));                  // en radianes
            modelMatrix = glm::rotate(modelMatrix, (float)glm::radians(ry), glm::vec3(0, 1, 0));    // en radianes
            modelMatrix = glm::translate(modelMatrix, glm::vec3(+1.05, 0, +0.03));                  // en radianes
            modelMatrix = glm::rotate(modelMatrix, (float)glm::radians(giro), glm::vec3(0, 1, 0));  // en radianes
            modelMatrix = glm::rotate(modelMatrix, (float)glm::radians(rr), glm::vec3(1, 0, 0));    // en radianes
            modelMatrix = glm::rotate(modelMatrix, (float)glm::radians(180.0), glm::vec3(0, 0, 1)); // en radianes

            modelViewMatrix = escena.viewMatrix * modelMatrix;
            glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
            glStencilFunc(GL_ALWAYS, ID, 0xFF);
            glBindTexture(GL_TEXTURE_2D, escena.texturas_id[24]);

            // Envia nuestra ModelView al Vertex Shader
            glUniformMatrix4fv(escena.uMVMatrixLocation, 1, GL_FALSE, &modelViewMatrix[0][0]);

            glDrawArrays(GL_TRIANGLES, 0, num_vertices1);

            // RUEDA delantera Derecha : Cálculo de la matriz modelo
            modelMatrix = glm::mat4(1.0f); // matriz identidad

            modelMatrix = glm::translate(modelMatrix, glm::vec3(tx - 0.95, ty + 0.45, tz));

            modelMatrix = glm::translate(modelMatrix, glm::vec3(+0.95, 0, +0.03));                 // en radianes
            modelMatrix = glm::rotate(modelMatrix, (float)glm::radians(ry), glm::vec3(0, 1, 0));   // en radianes
            modelMatrix = glm::translate(modelMatrix, glm::vec3(-0.95, 0, -0.03));                 // en radianes
            modelMatrix = glm::rotate(modelMatrix, (float)glm::radians(giro), glm::vec3(0, 1, 0)); // en radianes
            modelMatrix = glm::rotate(modelMatrix, (float)glm::radians(rr), glm::vec3(1, 0, 0));   // en radianes

            glBindTexture(GL_TEXTURE_2D, escena.texturas_id[24]);

            modelViewMatrix = escena.viewMatrix * modelMatrix;

            // Envia nuestra ModelView al Vertex Shader
            glUniformMatrix4fv(escena.uMVMatrixLocation, 1, GL_FALSE, &modelViewMatrix[0][0]);

            glDrawArrays(GL_TRIANGLES, 0, num_vertices1);

            // RUEDA trasera Izquierda : Cálculo de la matriz modelo
            modelMatrix = glm::mat4(1.0f); // matriz identidad

            modelMatrix = glm::translate(modelMatrix, glm::vec3(tx + 1.05, ty + 0.45, tz - 3.9));
            // modelMatrix     = glm::rotate(modelMatrix, (float) glm::radians(rr), glm::vec3(1,0,0));      // en radianes
            // modelMatrix     = glm::rotate(modelMatrix, (float) glm::radians(180.0), glm::vec3(0,0,1));   // en radianes
            modelMatrix = glm::translate(modelMatrix, glm::vec3(-1.05, 0, +3.9));                // en radianes
            modelMatrix = glm::rotate(modelMatrix, (float)glm::radians(ry), glm::vec3(0, 1, 0)); // en radianes
            modelMatrix = glm::translate(modelMatrix, glm::vec3(+1.05, 0, -3.9));                // en radianes
            modelMatrix = glm::rotate(modelMatrix, (float)glm::radians(rr), glm::vec3(1, 0, 0)); // en radianes
            modelMatrix = glm::rotate(modelMatrix, (float)glm::radians(180.0), glm::vec3(0, 0, 1));

            modelViewMatrix = escena.viewMatrix * modelMatrix;

            glBindTexture(GL_TEXTURE_2D, escena.texturas_id[24]);
            // Envia nuestra ModelView al Vertex Shader
            glUniformMatrix4fv(escena.uMVMatrixLocation, 1, GL_FALSE, &modelViewMatrix[0][0]);

            glDrawArrays(GL_TRIANGLES, 0, num_vertices1);

            // RUEDA Trasera Derecha : Cálculo de la matriz modelo
            modelMatrix = glm::mat4(1.0f); // matriz identidad

            modelMatrix = glm::translate(modelMatrix, glm::vec3(tx - 1.05, ty + 0.45, tz - 3.9));
            modelMatrix = glm::translate(modelMatrix, glm::vec3(+1.05, 0, +3.9));                // en radianes
            modelMatrix = glm::rotate(modelMatrix, (float)glm::radians(ry), glm::vec3(0, 1, 0)); // en radianes
            modelMatrix = glm::translate(modelMatrix, glm::vec3(-1.05, 0, -3.9));                // en radianes
            modelMatrix = glm::rotate(modelMatrix, (float)glm::radians(rr), glm::vec3(1, 0, 0)); // en radianes

            modelViewMatrix = escena.viewMatrix * modelMatrix;

            glBindTexture(GL_TEXTURE_2D, escena.texturas_id[24]);

            // Envia nuestra ModelView al Vertex Shader
            glUniformMatrix4fv(escena.uMVMatrixLocation, 1, GL_FALSE, &modelViewMatrix[0][0]);

            glDrawArrays(GL_TRIANGLES, 0, num_vertices1);
        }
        break;
    }
    case MARCADOR_ID:
    {
        if (escena.show_marcador)
        {
            float ttx, tty, ttz;
            ttx = tx;
            tty = ty;
            ttz = tz;

            glUniform4fv(escena.uColorLocation, 1, (const GLfloat *)colores[0]);
            modelMatrix = glm::mat4(1.0f);
            modelMatrix = glm::translate(modelMatrix, glm::vec3(ttx, tty, ttz));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(sx, sy, sz));
            modelMatrix = glm::rotate(modelMatrix, (float)glm::radians(ry), glm::vec3(0, 1, 0)); // en radianes

            modelViewMatrix = escena.viewMatrix * modelMatrix;
            glUniformMatrix4fv(escena.uMVMatrixLocation, 1, GL_FALSE, &modelViewMatrix[0][0]);

            glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
            glStencilFunc(GL_ALWAYS, 0, 0xFF);

            glBindTexture(GL_TEXTURE_2D, escena.texturas_id[23]);
            glUniform1i(escena.activadaLocation, 1);
            glUniform1i(escena.u_SamplerLocation, 0);
            glActiveTexture(GL_TEXTURE0);

            glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0);
            glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0 + 3);

            glEnable(GL_BLEND);
            glDisable(GL_LIGHTING);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            glDisable(GL_BLEND);
            glEnable(GL_LIGHTING);
            glVertexAttribPointer(escena.aTextureCoordLocation, UV_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0 + 6);

            glDrawArrays(GL_TRIANGLES, 0, num_vertices0);
        }
        break;
    }
    case ACERA_ID:
    {
        if (escena.show_acera)
        {
            float ttx, tty, ttz;
            ttx = tx;
            tty = ty;
            ttz = tz;

            glUniform4fv(escena.uColorLocation, 1, (const GLfloat *)colores[0]);
            modelMatrix = glm::mat4(1.0f);
            modelMatrix = glm::translate(modelMatrix, glm::vec3(ttx, tty, ttz));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(sx, sy, sz));

            modelViewMatrix = escena.viewMatrix * modelMatrix;
            glUniformMatrix4fv(escena.uMVMatrixLocation, 1, GL_FALSE, &modelViewMatrix[0][0]);

            glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
            glStencilFunc(GL_ALWAYS, 0, 0xFF);

            glBindTexture(GL_TEXTURE_2D, escena.texturas_id[0]);
            glUniform1i(escena.activadaLocation, 1);
            glUniform1i(escena.u_SamplerLocation, 0);
            glActiveTexture(GL_TEXTURE0);

            glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0);
            glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0 + 3);

            glVertexAttribPointer(escena.aTextureCoordLocation, UV_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0 + 6);

            glDrawArrays(GL_TRIANGLES, 0, num_vertices0);
        }
        break;
    }
    case ARBELOA_ID:
        if (escena.show_objetos)
        {

            float ttx, tty, ttz;
            ttx = tx;
            tty = ty;
            ttz = tz;

            glUniform4fv(escena.uColorLocation, 1, (const GLfloat *)colores[0]);
            modelMatrix = glm::mat4(1.0f);
            modelMatrix = glm::translate(modelMatrix, glm::vec3(ttx, tty, ttz));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(sx, sy, sz));

            modelViewMatrix = escena.viewMatrix * modelMatrix;
            glUniformMatrix4fv(escena.uMVMatrixLocation, 1, GL_FALSE, &modelViewMatrix[0][0]);

            glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
            glStencilFunc(GL_ALWAYS, 0, 0xFF);

            glBindTexture(GL_TEXTURE_2D, escena.texturas_id[1]);
            glUniform1i(escena.activadaLocation, 1);
            glUniform1i(escena.u_SamplerLocation, 0);
            glActiveTexture(GL_TEXTURE0);

            glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0);
            glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0 + 3);

            glVertexAttribPointer(escena.aTextureCoordLocation, UV_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0 + 6);

            glDrawArrays(GL_TRIANGLES, 0, num_vertices0);
        }
        break;
    case ARBOL_ID:
        if (escena.show_objetos)
        {

            float ttx, tty, ttz;
            ttx = tx;
            tty = ty;
            ttz = tz;

            glUniform4fv(escena.uColorLocation, 1, (const GLfloat *)colores[0]);
            modelMatrix = glm::mat4(1.0f);
            modelMatrix = glm::translate(modelMatrix, glm::vec3(ttx, tty, ttz));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(sx, sy, sz));

            modelViewMatrix = escena.viewMatrix * modelMatrix;
            glUniformMatrix4fv(escena.uMVMatrixLocation, 1, GL_FALSE, &modelViewMatrix[0][0]);

            glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
            glStencilFunc(GL_ALWAYS, 0, 0xFF);

            glBindTexture(GL_TEXTURE_2D, escena.texturas_id[2]);
            glUniform1i(escena.activadaLocation, 1);
            glUniform1i(escena.u_SamplerLocation, 0);
            glActiveTexture(GL_TEXTURE0);

            glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0);
            glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0 + 3);

            glVertexAttribPointer(escena.aTextureCoordLocation, UV_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0 + 6);

            glDrawArrays(GL_TRIANGLES, 0, num_vertices0);
        }
        break;
    case ARCO_JAP_ID:
        if (escena.show_objetos)
        {

            float ttx, tty, ttz;
            ttx = tx;
            tty = ty;
            ttz = tz;

            glUniform4fv(escena.uColorLocation, 1, (const GLfloat *)colores[0]);
            modelMatrix = glm::mat4(1.0f);
            modelMatrix = glm::translate(modelMatrix, glm::vec3(ttx, tty, ttz));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(sx, sy, sz));

            modelViewMatrix = escena.viewMatrix * modelMatrix;
            glUniformMatrix4fv(escena.uMVMatrixLocation, 1, GL_FALSE, &modelViewMatrix[0][0]);

            glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
            glStencilFunc(GL_ALWAYS, 0, 0xFF);

            glBindTexture(GL_TEXTURE_2D, escena.texturas_id[3]);
            glUniform1i(escena.activadaLocation, 1);
            glUniform1i(escena.u_SamplerLocation, 0);
            glActiveTexture(GL_TEXTURE0);

            glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0);
            glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0 + 3);

            glVertexAttribPointer(escena.aTextureCoordLocation, UV_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0 + 6);

            glDrawArrays(GL_TRIANGLES, 0, num_vertices0);
        }
        break;
    case BANCO_ID:
        if (escena.show_objetos)
        {

            float ttx, tty, ttz;
            ttx = tx;
            tty = ty;
            ttz = tz;

            glUniform4fv(escena.uColorLocation, 1, (const GLfloat *)colores[0]);
            modelMatrix = glm::mat4(1.0f);
            modelMatrix = glm::translate(modelMatrix, glm::vec3(ttx, tty, ttz));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(sx, sy, sz));

            modelViewMatrix = escena.viewMatrix * modelMatrix;
            glUniformMatrix4fv(escena.uMVMatrixLocation, 1, GL_FALSE, &modelViewMatrix[0][0]);

            glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
            glStencilFunc(GL_ALWAYS, 0, 0xFF);

            glBindTexture(GL_TEXTURE_2D, escena.texturas_id[4]);
            glUniform1i(escena.activadaLocation, 1);
            glUniform1i(escena.u_SamplerLocation, 0);
            glActiveTexture(GL_TEXTURE0);

            glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0);
            glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0 + 3);

            glVertexAttribPointer(escena.aTextureCoordLocation, UV_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0 + 6);

            glDrawArrays(GL_TRIANGLES, 0, num_vertices0);
        }
        break;
    case CARTEL_ID:
        if (escena.show_objetos)
        {

            float ttx, tty, ttz;
            ttx = tx;
            tty = ty;
            ttz = tz;

            glUniform4fv(escena.uColorLocation, 1, (const GLfloat *)colores[0]);
            modelMatrix = glm::mat4(1.0f);
            modelMatrix = glm::translate(modelMatrix, glm::vec3(ttx, tty, ttz));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(sx, sy, sz));

            modelViewMatrix = escena.viewMatrix * modelMatrix;
            glUniformMatrix4fv(escena.uMVMatrixLocation, 1, GL_FALSE, &modelViewMatrix[0][0]);

            glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
            glStencilFunc(GL_ALWAYS, 0, 0xFF);

            glBindTexture(GL_TEXTURE_2D, escena.texturas_id[22]);
            glUniform1i(escena.activadaLocation, 1);
            glUniform1i(escena.u_SamplerLocation, 0);
            glActiveTexture(GL_TEXTURE0);

            glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0);
            glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0 + 3);

            glVertexAttribPointer(escena.aTextureCoordLocation, UV_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0 + 6);

            glDrawArrays(GL_TRIANGLES, 0, num_vertices0);
        }
        break;
    case CESPED_ID:
        if (escena.show_objetos)
        {

            float ttx, tty, ttz;
            ttx = tx;
            tty = ty;
            ttz = tz;

            glUniform4fv(escena.uColorLocation, 1, (const GLfloat *)colores[0]);
            modelMatrix = glm::mat4(1.0f);
            modelMatrix = glm::translate(modelMatrix, glm::vec3(ttx, tty, ttz));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(sx, sy, sz));

            modelViewMatrix = escena.viewMatrix * modelMatrix;
            glUniformMatrix4fv(escena.uMVMatrixLocation, 1, GL_FALSE, &modelViewMatrix[0][0]);

            glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
            glStencilFunc(GL_ALWAYS, 0, 0xFF);

            glBindTexture(GL_TEXTURE_2D, escena.texturas_id[6]);
            glUniform1i(escena.activadaLocation, 1);
            glUniform1i(escena.u_SamplerLocation, 0);
            glActiveTexture(GL_TEXTURE0);

            glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0);
            glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0 + 3);

            glVertexAttribPointer(escena.aTextureCoordLocation, UV_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0 + 6);

            glDrawArrays(GL_TRIANGLES, 0, num_vertices0);
        }
        break;
    case CIELO_ID:
        if (escena.show_objetos)
        {

            float ttx, tty, ttz;
            ttx = tx;
            tty = ty;
            ttz = tz;

            glUniform4fv(escena.uColorLocation, 1, (const GLfloat *)colores[0]);
            modelMatrix = glm::mat4(1.0f);
            modelMatrix = glm::translate(modelMatrix, glm::vec3(ttx, tty, ttz));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(sx, sy, sz));

            modelViewMatrix = escena.viewMatrix * modelMatrix;
            glUniformMatrix4fv(escena.uMVMatrixLocation, 1, GL_FALSE, &modelViewMatrix[0][0]);

            glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
            glStencilFunc(GL_ALWAYS, 0, 0xFF);

            glBindTexture(GL_TEXTURE_2D, escena.texturas_id[25]);
            glUniform1i(escena.activadaLocation, 1);
            glUniform1i(escena.u_SamplerLocation, 0);
            glActiveTexture(GL_TEXTURE0);

            glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0);
            glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0 + 3);

            glVertexAttribPointer(escena.aTextureCoordLocation, UV_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0 + 6);

            glDrawArrays(GL_TRIANGLES, 0, num_vertices0);
        }
        break;
    case DOMO_ID:
        if (escena.show_objetos)
        {

            float ttx, tty, ttz;
            ttx = tx;
            tty = ty;
            ttz = tz;

            glUniform4fv(escena.uColorLocation, 1, (const GLfloat *)colores[0]);
            modelMatrix = glm::mat4(1.0f);
            modelMatrix = glm::translate(modelMatrix, glm::vec3(ttx, tty, ttz));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(sx, sy, sz));

            modelViewMatrix = escena.viewMatrix * modelMatrix;
            glUniformMatrix4fv(escena.uMVMatrixLocation, 1, GL_FALSE, &modelViewMatrix[0][0]);

            glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
            glStencilFunc(GL_ALWAYS, 0, 0xFF);

            glBindTexture(GL_TEXTURE_2D, escena.texturas_id[7]);
            glUniform1i(escena.activadaLocation, 1);
            glUniform1i(escena.u_SamplerLocation, 0);
            glActiveTexture(GL_TEXTURE0);

            glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0);
            glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0 + 3);

            glVertexAttribPointer(escena.aTextureCoordLocation, UV_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0 + 6);

            glDrawArrays(GL_TRIANGLES, 0, num_vertices0);
        }
        break;
    case FARO_ID:
        if (escena.show_objetos)
        {

            float ttx, tty, ttz;
            ttx = tx;
            tty = ty;
            ttz = tz;

            glUniform4fv(escena.uColorLocation, 1, (const GLfloat *)colores[0]);
            modelMatrix = glm::mat4(1.0f);
            modelMatrix = glm::translate(modelMatrix, glm::vec3(ttx, tty, ttz));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(sx, sy, sz));

            modelViewMatrix = escena.viewMatrix * modelMatrix;
            glUniformMatrix4fv(escena.uMVMatrixLocation, 1, GL_FALSE, &modelViewMatrix[0][0]);

            glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
            glStencilFunc(GL_ALWAYS, 0, 0xFF);

            glBindTexture(GL_TEXTURE_2D, escena.texturas_id[9]);
            glUniform1i(escena.activadaLocation, 1);
            glUniform1i(escena.u_SamplerLocation, 0);
            glActiveTexture(GL_TEXTURE0);

            glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0);
            glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0 + 3);

            glVertexAttribPointer(escena.aTextureCoordLocation, UV_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0 + 6);

            glDrawArrays(GL_TRIANGLES, 0, num_vertices0);
        }
        break;
    case FAROLA_ID:
        if (escena.show_objetos)
        {

            float ttx, tty, ttz;
            ttx = tx;
            tty = ty;
            ttz = tz;

            glUniform4fv(escena.uColorLocation, 1, (const GLfloat *)colores[0]);
            modelMatrix = glm::mat4(1.0f);
            modelMatrix = glm::translate(modelMatrix, glm::vec3(ttx, tty, ttz));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(sx, sy, sz));

            modelViewMatrix = escena.viewMatrix * modelMatrix;
            glUniformMatrix4fv(escena.uMVMatrixLocation, 1, GL_FALSE, &modelViewMatrix[0][0]);

            glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
            glStencilFunc(GL_ALWAYS, 0, 0xFF);

            glBindTexture(GL_TEXTURE_2D, escena.texturas_id[10]);
            glUniform1i(escena.activadaLocation, 1);
            glUniform1i(escena.u_SamplerLocation, 0);
            glActiveTexture(GL_TEXTURE0);

            glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0);
            glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0 + 3);

            glVertexAttribPointer(escena.aTextureCoordLocation, UV_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0 + 6);

            glDrawArrays(GL_TRIANGLES, 0, num_vertices0);
        }
        break;
    case FUENTE_ID:
        if (escena.show_objetos)
        {

            float ttx, tty, ttz;
            ttx = tx;
            tty = ty;
            ttz = tz;

            glUniform4fv(escena.uColorLocation, 1, (const GLfloat *)colores[0]);
            modelMatrix = glm::mat4(1.0f);
            modelMatrix = glm::translate(modelMatrix, glm::vec3(ttx, tty, ttz));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(sx, sy, sz));

            modelViewMatrix = escena.viewMatrix * modelMatrix;
            glUniformMatrix4fv(escena.uMVMatrixLocation, 1, GL_FALSE, &modelViewMatrix[0][0]);

            glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
            glStencilFunc(GL_ALWAYS, 0, 0xFF);

            glBindTexture(GL_TEXTURE_2D, escena.texturas_id[11]);
            glUniform1i(escena.activadaLocation, 1);
            glUniform1i(escena.u_SamplerLocation, 0);
            glActiveTexture(GL_TEXTURE0);

            glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0);
            glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0 + 3);

            glVertexAttribPointer(escena.aTextureCoordLocation, UV_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0 + 6);

            glDrawArrays(GL_TRIANGLES, 0, num_vertices0);
        }
        break;
    case LINES_ID:
        if (escena.show_objetos)
        {

            float ttx, tty, ttz;
            ttx = tx;
            tty = ty;
            ttz = tz;

            glUniform4fv(escena.uColorLocation, 1, (const GLfloat *)colores[0]);
            modelMatrix = glm::mat4(1.0f);
            modelMatrix = glm::translate(modelMatrix, glm::vec3(ttx, tty, ttz));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(sx, sy, sz));

            modelViewMatrix = escena.viewMatrix * modelMatrix;
            glUniformMatrix4fv(escena.uMVMatrixLocation, 1, GL_FALSE, &modelViewMatrix[0][0]);

            glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
            glStencilFunc(GL_ALWAYS, 0, 0xFF);

            glBindTexture(GL_TEXTURE_2D, escena.texturas_id[13]);
            glUniform1i(escena.activadaLocation, 1);
            glUniform1i(escena.u_SamplerLocation, 0);
            glActiveTexture(GL_TEXTURE0);

            glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0);
            glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0 + 3);

            glVertexAttribPointer(escena.aTextureCoordLocation, UV_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0 + 6);

            glDrawArrays(GL_TRIANGLES, 0, num_vertices0);
        }
        break;
    case PANTEON_ID:
        if (escena.show_objetos)
        {

            float ttx, tty, ttz;
            ttx = tx;
            tty = ty;
            ttz = tz;

            glUniform4fv(escena.uColorLocation, 1, (const GLfloat *)colores[0]);
            modelMatrix = glm::mat4(1.0f);
            modelMatrix = glm::translate(modelMatrix, glm::vec3(ttx, tty, ttz));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(sx, sy, sz));

            modelViewMatrix = escena.viewMatrix * modelMatrix;
            glUniformMatrix4fv(escena.uMVMatrixLocation, 1, GL_FALSE, &modelViewMatrix[0][0]);

            glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
            glStencilFunc(GL_ALWAYS, 0, 0xFF);

            glBindTexture(GL_TEXTURE_2D, escena.texturas_id[14]);
            glUniform1i(escena.activadaLocation, 1);
            glUniform1i(escena.u_SamplerLocation, 0);
            glActiveTexture(GL_TEXTURE0);

            glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0);
            glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0 + 3);

            glVertexAttribPointer(escena.aTextureCoordLocation, UV_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0 + 6);

            glDrawArrays(GL_TRIANGLES, 0, num_vertices0);
        }
        break;
    case PINO_ID:
        if (escena.show_objetos)
        {

            float ttx, tty, ttz;
            ttx = tx;
            tty = ty;
            ttz = tz;

            glUniform4fv(escena.uColorLocation, 1, (const GLfloat *)colores[0]);
            modelMatrix = glm::mat4(1.0f);
            modelMatrix = glm::translate(modelMatrix, glm::vec3(ttx, tty, ttz));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(sx, sy, sz));

            modelViewMatrix = escena.viewMatrix * modelMatrix;
            glUniformMatrix4fv(escena.uMVMatrixLocation, 1, GL_FALSE, &modelViewMatrix[0][0]);

            glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
            glStencilFunc(GL_ALWAYS, 0, 0xFF);

            glBindTexture(GL_TEXTURE_2D, escena.texturas_id[15]);
            glUniform1i(escena.activadaLocation, 1);
            glUniform1i(escena.u_SamplerLocation, 0);
            glActiveTexture(GL_TEXTURE0);

            glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0);
            glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0 + 3);

            glVertexAttribPointer(escena.aTextureCoordLocation, UV_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0 + 6);

            glDrawArrays(GL_TRIANGLES, 0, num_vertices0);
        }
        break;
    case POZO_ID:
        if (escena.show_objetos)
        {

            float ttx, tty, ttz;
            ttx = tx;
            tty = ty;
            ttz = tz;

            glUniform4fv(escena.uColorLocation, 1, (const GLfloat *)colores[0]);
            modelMatrix = glm::mat4(1.0f);
            modelMatrix = glm::translate(modelMatrix, glm::vec3(ttx, tty, ttz));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(sx, sy, sz));

            modelViewMatrix = escena.viewMatrix * modelMatrix;
            glUniformMatrix4fv(escena.uMVMatrixLocation, 1, GL_FALSE, &modelViewMatrix[0][0]);

            glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
            glStencilFunc(GL_ALWAYS, 0, 0xFF);

            glBindTexture(GL_TEXTURE_2D, escena.texturas_id[16]);
            glUniform1i(escena.activadaLocation, 1);
            glUniform1i(escena.u_SamplerLocation, 0);
            glActiveTexture(GL_TEXTURE0);

            glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0);
            glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0 + 3);

            glVertexAttribPointer(escena.aTextureCoordLocation, UV_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0 + 6);

            glDrawArrays(GL_TRIANGLES, 0, num_vertices0);
        }
        break;
    case SEMAFORO_ID:
        if (escena.show_objetos)
        {

            float ttx, tty, ttz;
            ttx = tx;
            tty = ty;
            ttz = tz;

            glUniform4fv(escena.uColorLocation, 1, (const GLfloat *)colores[0]);
            modelMatrix = glm::mat4(1.0f);
            modelMatrix = glm::translate(modelMatrix, glm::vec3(ttx, tty, ttz));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(sx, sy, sz));

            modelViewMatrix = escena.viewMatrix * modelMatrix;
            glUniformMatrix4fv(escena.uMVMatrixLocation, 1, GL_FALSE, &modelViewMatrix[0][0]);

            glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
            glStencilFunc(GL_ALWAYS, 0, 0xFF);

            glBindTexture(GL_TEXTURE_2D, escena.texturas_id[17]);
            glUniform1i(escena.activadaLocation, 1);
            glUniform1i(escena.u_SamplerLocation, 0);
            glActiveTexture(GL_TEXTURE0);

            glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0);
            glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0 + 3);

            glVertexAttribPointer(escena.aTextureCoordLocation, UV_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0 + 6);

            glDrawArrays(GL_TRIANGLES, 0, num_vertices0);
        }
        break;
    case SENIAL_ID:
        if (escena.show_objetos)
        {

            float ttx, tty, ttz;
            ttx = tx;
            tty = ty;
            ttz = tz;

            glUniform4fv(escena.uColorLocation, 1, (const GLfloat *)colores[0]);
            modelMatrix = glm::mat4(1.0f);
            modelMatrix = glm::translate(modelMatrix, glm::vec3(ttx, tty, ttz));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(sx, sy, sz));

            modelViewMatrix = escena.viewMatrix * modelMatrix;
            glUniformMatrix4fv(escena.uMVMatrixLocation, 1, GL_FALSE, &modelViewMatrix[0][0]);

            glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
            glStencilFunc(GL_ALWAYS, 0, 0xFF);

            glBindTexture(GL_TEXTURE_2D, escena.texturas_id[18]);
            glUniform1i(escena.activadaLocation, 1);
            glUniform1i(escena.u_SamplerLocation, 0);
            glActiveTexture(GL_TEXTURE0);

            glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0);
            glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0 + 3);

            glVertexAttribPointer(escena.aTextureCoordLocation, UV_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0 + 6);

            glDrawArrays(GL_TRIANGLES, 0, num_vertices0);
        }
        break;
    case TIENDA_ID:
        if (escena.show_objetos)
        {

            float ttx, tty, ttz;
            ttx = tx;
            tty = ty;
            ttz = tz;

            glUniform4fv(escena.uColorLocation, 1, (const GLfloat *)colores[0]);
            modelMatrix = glm::mat4(1.0f);
            modelMatrix = glm::translate(modelMatrix, glm::vec3(ttx, tty, ttz));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(sx, sy, sz));

            modelViewMatrix = escena.viewMatrix * modelMatrix;
            glUniformMatrix4fv(escena.uMVMatrixLocation, 1, GL_FALSE, &modelViewMatrix[0][0]);

            glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
            glStencilFunc(GL_ALWAYS, 0, 0xFF);

            glBindTexture(GL_TEXTURE_2D, escena.texturas_id[19]);
            glUniform1i(escena.activadaLocation, 1);
            glUniform1i(escena.u_SamplerLocation, 0);
            glActiveTexture(GL_TEXTURE0);

            glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0);
            glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0 + 3);

            glVertexAttribPointer(escena.aTextureCoordLocation, UV_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0 + 6);

            glDrawArrays(GL_TRIANGLES, 0, num_vertices0);
        }
        break;
    case VALLAS_ID:
    {
        if (escena.show_objetos)
        {

            float ttx, tty, ttz;
            ttx = tx;
            tty = ty;
            ttz = tz;

            glUniform4fv(escena.uColorLocation, 1, (const GLfloat *)colores[0]);
            modelMatrix = glm::mat4(1.0f);
            modelMatrix = glm::translate(modelMatrix, glm::vec3(ttx, tty, ttz));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(sx, sy, sz));

            modelViewMatrix = escena.viewMatrix * modelMatrix;
            glUniformMatrix4fv(escena.uMVMatrixLocation, 1, GL_FALSE, &modelViewMatrix[0][0]);

            glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
            glStencilFunc(GL_ALWAYS, 0, 0xFF);

            glBindTexture(GL_TEXTURE_2D, escena.texturas_id[20]);
            glUniform1i(escena.activadaLocation, 1);
            glUniform1i(escena.u_SamplerLocation, 0);
            glActiveTexture(GL_TEXTURE0);

            glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0);
            glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0 + 3);

            glVertexAttribPointer(escena.aTextureCoordLocation, UV_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0 + 6);

            glDrawArrays(GL_TRIANGLES, 0, num_vertices0);
        }
        break;
    }
    case GIMNASIO_ID:
    {
        if (escena.show_objetos)
        {
            float ttx, tty, ttz;
            ttx = tx;
            tty = ty;
            ttz = tz;

            glUniform4fv(escena.uColorLocation, 1, (const GLfloat *)colores[0]);
            modelMatrix = glm::mat4(1.0f);
            modelMatrix = glm::translate(modelMatrix, glm::vec3(ttx, tty, ttz));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(sx, sy, sz));

            modelViewMatrix = escena.viewMatrix * modelMatrix;
            glUniformMatrix4fv(escena.uMVMatrixLocation, 1, GL_FALSE, &modelViewMatrix[0][0]);

            glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
            glStencilFunc(GL_ALWAYS, 0, 0xFF);

            glBindTexture(GL_TEXTURE_2D, escena.texturas_id[12]);
            glUniform1i(escena.activadaLocation, 1);
            glUniform1i(escena.u_SamplerLocation, 0);
            glActiveTexture(GL_TEXTURE0);

            glVertexAttribPointer(escena.aPositionLocation, POSITION_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0);
            glVertexAttribPointer(escena.aNormalLocation, NORMAL_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0 + 3);

            glVertexAttribPointer(escena.aTextureCoordLocation, UV_COMPONENT_COUNT, GL_FLOAT, false, STRIDE, modelo0 + 6);

            glDrawArrays(GL_TRIANGLES, 0, num_vertices0);
        }
        break;
    }

    } // switch
}

//************************************************************** Clase TEscena

TEscena::TEscena()
{

    seleccion = 1;
    num_objects = 0;
    num_cars = 0;
    num_marcador = 0;

    show_car = 1;
    show_wheels = 1;
    show_road = 1;

    show_acera = 1;
    show_objetos = 1;
    show_marcador = 1;

    // live variables usadas por GLUI en TGui
    wireframe = 0;
    z_buffer = 1;
    culling = 0;
    transparencia = 0;
    sentido_horario = 1;
    proyeccion = 0;

    raton = 0;
    rotacion_X = 0;
    rotacion_Y = 0;
    rotacion_Z = 0;
    factor_movimiento_camara = 0.4;
    scaleZ = 1.0;
    camara_Movil = 0;

    scale = 100.0;
    xy_aspect = 1;
    last_x = 0;
    last_y = 0;

    memcpy(view_position, view_position_c, 3 * sizeof(float));
    memcpy(view_rotate, view_rotate_c, 16 * sizeof(float));

    memcpy(light0_ambient, light0_ambient_c, 4 * sizeof(float));

    memcpy(light0_ambient, light0_ambient_c, 4 * sizeof(float));
    memcpy(light0_diffuse, light0_diffuse_c, 4 * sizeof(float));
    memcpy(light0_specular, light0_specular_c, 4 * sizeof(float));
    memcpy(light0_position, light0_position_c, 4 * sizeof(float));

    memcpy(light1_ambient, light1_ambient_c, 4 * sizeof(float));
    memcpy(light1_diffuse, light1_diffuse_c, 4 * sizeof(float));
    memcpy(light1_specular, light1_specular_c, 4 * sizeof(float));
    memcpy(light1_position, light1_position_c, 4 * sizeof(float));

    memcpy(mat_ambient, mat_ambient_c, 4 * sizeof(float));
    memcpy(mat_diffuse, mat_diffuse_c, 4 * sizeof(float));
    memcpy(mat_specular, mat_specular_c, 4 * sizeof(float));
    memcpy(mat_shininess, mat_shininess_c, 1 * sizeof(float));
}

void __fastcall TEscena::InitGL()
{
    int tx, ty, tw, th;

    // Habilita el z_buffer
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_STENCIL_TEST);
    glDepthFunc(GL_LESS);

    // Inicializaci�n de GLEW
    std::cout << "Inicializando GLEW" << std::endl
              << std::endl;
    if (glewInit() != GLEW_OK)
        throw std::runtime_error("glewInit failed");

    // print out some info about the graphics drivers
    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLSL version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
    std::cout << "Vendedor: " << glGetString(GL_VENDOR) << std::endl;
    std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;

    // Carga de los Shaders
    std::cout << std::endl
              << "Cargando Shaders" << std::endl;

    Shader shader;

    std::vector<GLuint> shaders;
    shaders.push_back(shader.LoadShader("../../Shaders/VertexShader.glsl", GL_VERTEX_SHADER));
    // std::cout << "Vertex Shader: " << shader.ReturnShaderID() << std::endl;
    shaders.push_back(shader.LoadShader("../../Shaders/FragmentShader.glsl", GL_FRAGMENT_SHADER));
    // std::cout << "Fragment Shader: " << shader.ReturnShaderID() << std::endl;
    shaderProgram = new Program(shaders);

    // std::cout << "Shader Program: " << shaderProgram->ReturnProgramID() << std::endl;

    glUseProgram(shaderProgram->ReturnProgramID());
    // glValidateProgram(shaderProgram->ReturnProgramID());

    aPositionLocation = shaderProgram->attrib(A_POSITION);
    aNormalLocation = shaderProgram->attrib(A_NORMAL);

    // PARA LAS TEXTURAS--------------------------------------
    aTextureCoordLocation = shaderProgram->attrib(A_TEXTURECORD);
    u_SamplerLocation = shaderProgram->uniform(U_SAMPLER);
    activadaLocation = shaderProgram->uniform("activada");

    uProjectionMatrixLocation = shaderProgram->uniform(U_PROJECTIONMATRIX);
    uMVMatrixLocation = shaderProgram->uniform(U_MVMATRIX);
    uVMatrixLocation = shaderProgram->uniform(U_VMATRIX);
    uColorLocation = shaderProgram->uniform(U_COLOR);

    uLuz0Location = shaderProgram->uniform(U_LUZ0);
    uLuz1Location = shaderProgram->uniform(U_LUZ1);
    uLuz2Location = shaderProgram->uniform(U_LUZ2);

    u_Intensidad0Location = shaderProgram->uniform("u_Intensidad0");
    u_Intensidad1Location = shaderProgram->uniform("u_Intensidad1");
    u_Intensidad2Location = shaderProgram->uniform("u_Intensidad2");

    u_Position_Luz0Location = shaderProgram->uniform("u_Position_Luz0");
    u_Position_Luz1Location = shaderProgram->uniform("u_Position_Luz1");
    u_Position_Luz2Location = shaderProgram->uniform("u_Position_Luz2");

    // PUNTO DE OBJETO CLICADO
    uSelectionEnabledLocation = shaderProgram->uniform(U_SELECTION_ENABLED);

    // Habilitamos el paso de attributes
    glEnableVertexAttribArray(aPositionLocation);
    glEnableVertexAttribArray(aNormalLocation);

    // Habilitamos las texturas
    glEnableVertexAttribArray(aTextureCoordLocation);

    // Estableciendo la matriz de proyecci�n perspectiva
    GLUI_Master.get_viewport_area(&tx, &ty, &tw, &th);
    xy_aspect = (float)tw / (float)th;
    projectionMatrix = glm::perspective(45.0f, xy_aspect, 0.1f, 1000.0f);
    glUniformMatrix4fv(uProjectionMatrixLocation, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
}

/************************** TEscena::AddCar(TPrimitiva *car) *****************/

void __fastcall TEscena::AddCar(TPrimitiva *car)
{
    cars[num_cars] = car;
    num_cars++;
}

/******************** TEscena::AddObject(TPrimitiva *object) *****************/

void __fastcall TEscena::AddObject(TPrimitiva *object)
{
    objects[num_objects] = object;
    num_objects++;
}

/******************** TEscena::AddMarcador(TPrimitiva *marcador) *****************/

void __fastcall TEscena::AddMarcador(TPrimitiva *marcador)
{
    marcadores[num_marcador] = marcador;
    num_marcador++;
}

/******************** TPrimitiva __fastcall *TEscena::GetMarcador() *****************/

TPrimitiva __fastcall *TEscena::GetMarcador()
{
    TPrimitiva *p = NULL;

    for (int i = 0; i < num_marcador; i++)
    {
        p = marcadores[i];
    }
    return (p);
}

/******************** TPrimitiva *TEscena::GetCar(int id) ********************/

TPrimitiva __fastcall *TEscena::GetCar(int id)
{
    TPrimitiva *p = NULL;

    for (int i = 0; i < num_cars; i++)
    {
        if (cars[i]->ID == id)
        {
            p = cars[i];
        }
    }
    return (p);
}

/******************** TEscena::RenderCars() **********************************/

void __fastcall TEscena::RenderCars(bool reflejo)
{

    for (int i = 0; i < num_cars; i++)
    {
        cars[i]->Render(seleccion, reflejo);
    }
}

/******************** TEscena::RenderCars() **********************************/

void __fastcall TEscena::RenderObjects(bool reflejo)
{

    for (int i = 0; i < num_objects; i++)
    {
        objects[i]->Render(seleccion, reflejo);
    }
}

/******************** TEscena::RenderMarcador() ******************************/

void __fastcall TEscena::RenderMarcador(bool reflejo)
{

    for (int i = 0; i < num_marcador; i++)
    {
        marcadores[i]->Render(seleccion, reflejo);
    }
}

/***************************************** TEscena::Render() *****************/

void __fastcall TEscena::Render()
{
    glm::mat4 rotateMatrix;

    glClearColor(0.0, 0.7, 0.9, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // Cálculo de la vista (cámara)
    switch (escena.modo_camara)
    {
    // Camara general
    case 0:
    {
        viewMatrix = glm::mat4(1.0f);
        rotateMatrix = glm::make_mat4(view_rotate);
        viewMatrix = glm::translate(viewMatrix, glm::vec3(view_position[0], view_position[1], view_position[2]));
        viewMatrix = viewMatrix * rotateMatrix;
        viewMatrix = glm::scale(viewMatrix, glm::vec3(scale / 100.0, scale / 100.0, scale / 100.0));
        break;
    }
    case 1:
    {
        // Camara de seguimiento
        TPrimitiva *coche = GetCar(seleccion);
        if (coche)
        {
            float grados = coche->ry * 3.14159265358979 / 180.0;
            viewMatrix = glm::lookAt(glm::vec3(coche->tx - 10.0 * sin(grados), 5, coche->tz - 10.0 * cos(grados)), glm::vec3(coche->tx, coche->ty, coche->tz), glm::vec3(0, 1, 0));
        }
        break;
    }
    case 2:
    {
        // Camara aerea
        TPrimitiva *coche = GetCar(seleccion);
        if (coche)
            viewMatrix = glm::lookAt(glm::vec3(coche->tx, 30, coche->tz), glm::vec3(coche->tx, 0, coche->tz), glm::vec3(0, 0, 1));
        break;
    }
    case 3:
    {
        // Camara conductor
        TPrimitiva *coche = GetCar(seleccion);
        if (coche)
        {
            float grados = coche->ry * 3.14159265358979 / 180.0;
            viewMatrix = glm::lookAt(glm::vec3(coche->tx, 2.5, coche->tz), glm::vec3((coche->tx) + 2 * sin(grados), 2.5, (coche->tz) + 2 * cos(grados)), glm::vec3(0, 1, 0));
        }
        break;
    }
    }

    // Proyeccion
    int tx, ty, tw, th;
    GLUI_Master.get_viewport_area(&tx, &ty, &tw, &th);
    glViewport(tx, ty, tw, th);
    escena.xy_aspect = (float)tw / (float)th;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (proyeccion == 0)
    {
        projectionMatrix = glm::perspective(45.0f, xy_aspect, 0.1f, 1000.0f);
        glUniformMatrix4fv(uProjectionMatrixLocation, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
    }
    else if (proyeccion == 1)
    {
        projectionMatrix = glm::ortho(-50.0f, (float)tw / 10, (float)-th / 10, 50.0f, -1000.0f, 1000.0f);
        glUniformMatrix4fv(uProjectionMatrixLocation, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
    }

    glUniform1i(uLuz0Location, gui.light0_enabled);
    glUniform1i(uLuz1Location, gui.light1_enabled);
    glUniform1i(uLuz2Location, gui.light2_enabled);

    float intensidad = gui.light0_intensity;
    glUniform1f(u_Intensidad0Location, intensidad);
    float intensidad1 = gui.light1_intensity;
    glUniform1f(u_Intensidad1Location, intensidad1);
    float intensidad2 = gui.light2_intensity;
    glUniform1f(u_Intensidad2Location, intensidad2);

    glUniformMatrix4fv(uVMatrixLocation, 1, GL_FALSE, glm::value_ptr(viewMatrix));

    glUniform1i(uSelectionEnabledLocation, 0);

    glUniform4fv(escena.u_Position_Luz0Location, 1, (const GLfloat *)&escena.light0_position);
    glUniform4fv(escena.u_Position_Luz1Location, 1, (const GLfloat *)&escena.light1_position);
    glUniform4fv(escena.u_Position_Luz2Location, 1, (const GLfloat *)&escena.light2_position);

    // Dibujar carretera y objetos
    RenderObjects(seleccion);

    // Dibujar coches
    RenderCars(seleccion);

    // Dibujar marcador
    RenderMarcador(seleccion);

    glutSwapBuffers();
}

// Selecciona un objeto a través del ratón
void __fastcall TEscena::Pick3D(int mouse_x, int mouse_y)
{
    GLint viewport[4];               // buffer[0] = numero de objetos
    GLuint buffer[2048];             // buffer[1] = profundidad minima
    GLint hits;                      // buffer[2] = profuncidad maxima
    int profundidad, tx, ty, tw, th; // buffer[3] = nombre de la pila
    char cad[80];

    // seleccion = 0;
    GLUI_Master.get_viewport_area(&tx, &ty, &tw, &th);
    glViewport(tx, ty, tw, th);

    int index;
    glReadPixels(mouse_x, th - mouse_y + 81, 1, 1, GL_STENCIL_INDEX, GL_UNSIGNED_INT, &index);

    gui.sel = index;
    seleccion = index;

    // std::cout << "seleccion: " << seleccion << std::endl;
    switch (seleccion)
    {
    case 1:
    { // Coche 1
        if (escena.show_marcador == 0)
        {
            escena.show_marcador = 1;
        }
        gui.sel = 1;
        seleccion = 1;
        gui.radioGroup->set_selected(seleccion);
        TPrimitiva *marcador = escena.GetMarcador();
        TPrimitiva *coche = escena.GetCar(seleccion);
        marcador->ry = coche->ry;
        marcador->tx = coche->tx;
        marcador->tz = coche->tz;
        marcador->ty = coche->ty;
        break;
    }
    case 2:
    {
        if (escena.show_marcador == 0)
        {
            escena.show_marcador = 1;
        }
        gui.sel = 2;
        seleccion = 2;
        gui.radioGroup->set_selected(seleccion);
        TPrimitiva *marcador = escena.GetMarcador();
        TPrimitiva *coche = escena.GetCar(seleccion);
        marcador->ry = coche->ry;
        marcador->tx = coche->tx;
        marcador->tz = coche->tz;
        marcador->ty = coche->ty;
        break;
    }
    default:
    {
        // printf("No has seleccionado ningun coche \n");
        escena.show_marcador = 0;
        gui.radioGroup->set_selected(0);
        break;
    }
    }
}

// Crea todo el escenario
void __fastcall TEscena::CrearEscenario()
{
    TPrimitiva *road = new TPrimitiva(CARRETERA_ID, CARRETERA_ID);
    AddObject(road);

    TPrimitiva *car1 = new TPrimitiva(1, COCHE_ID);
    car1->rx = 0.0;
    car1->ry = 0.0;
    car1->rz = 0.0;
    car1->rr = 0.0;
    car1->giro = 0;
    TPrimitiva *car2 = new TPrimitiva(2, COCHE_ID);
    car2->colores[0][0] = 1.0;
    car2->colores[0][1] = 1.0;
    car2->colores[0][2] = 1.0;
    car2->colores[0][3] = 1.0;
    car2->tx = 2;
    car2->tz = -20;
    AddCar(car1);
    AddCar(car2);

    TPrimitiva *lineas = new TPrimitiva(LINES_ID, LINES_ID);
    lineas->tx = 0;
    lineas->ty = 0;
    lineas->tz = 0;
    AddObject(lineas);

    TPrimitiva *edificio1 = new TPrimitiva(EDIFICIO_ID, EDIFICIO_ID);
    edificio1->tx = 0;
    edificio1->ty = 0;
    edificio1->tz = -5;
    AddObject(edificio1);

    TPrimitiva *edificio2 = new TPrimitiva(EDIFICIO_ID, EDIFICIO_ID);
    edificio2->tx = 0;
    edificio2->ty = 0;
    edificio2->tz = 23;
    AddObject(edificio2);

    TPrimitiva *edificio3 = new TPrimitiva(EDIFICIO_ID, EDIFICIO_ID);
    edificio3->tx = 0;
    edificio3->ty = 0;
    edificio3->tz = 51;
    AddObject(edificio3);

    TPrimitiva *edificio4 = new TPrimitiva(EDIFICIO_ID, EDIFICIO_ID);
    edificio4->tx = 0;
    edificio4->ty = 0;
    edificio4->tz = 79;
    AddObject(edificio4);

    TPrimitiva *acera = new TPrimitiva(ACERA_ID, ACERA_ID);
    acera->tx = 0.15;
    acera->ty = 0;
    acera->tz = -0.15;

    AddObject(acera);

    TPrimitiva *fuente = new TPrimitiva(FUENTE_ID, FUENTE_ID);
    fuente->tx = 0;
    fuente->ty = 0.0;
    fuente->tz = 2;
    AddObject(fuente);

    TPrimitiva *arco_japones = new TPrimitiva(ARCO_JAP_ID, ARCO_JAP_ID);
    arco_japones->tx = 0;
    arco_japones->ty = 0;
    arco_japones->tz = 0;
    AddObject(arco_japones);

    TPrimitiva *arbeloa1 = new TPrimitiva(ARBELOA_ID, ARBELOA_ID);
    arbeloa1->tx = 0;
    arbeloa1->ty = 0;
    arbeloa1->tz = 0;
    AddObject(arbeloa1);

    TPrimitiva *arbeloa2 = new TPrimitiva(ARBELOA_ID, ARBELOA_ID);
    arbeloa2->tx = 0;
    arbeloa2->ty = 0;
    arbeloa2->tz = 5;
    AddObject(arbeloa2);

    TPrimitiva *arbeloa3 = new TPrimitiva(ARBELOA_ID, ARBELOA_ID);
    arbeloa3->tx = 0;
    arbeloa3->ty = 0;
    arbeloa3->tz = 10;
    AddObject(arbeloa3);

    TPrimitiva *arbeloa4 = new TPrimitiva(ARBELOA_ID, ARBELOA_ID);
    arbeloa4->tx = 0;
    arbeloa4->ty = 0;
    arbeloa4->tz = 15;
    AddObject(arbeloa4);

    TPrimitiva *cartel = new TPrimitiva(CARTEL_ID, CARTEL_ID);
    cartel->tx = 0;
    cartel->ty = 0;
    cartel->tz = 0;
    AddObject(cartel);

    TPrimitiva *arbol2 = new TPrimitiva(ARBOL_ID, ARBOL_ID);
    arbol2->tx = 0;
    arbol2->ty = 0;
    arbol2->tz = 85;
    AddObject(arbol2);

    TPrimitiva *arbol3 = new TPrimitiva(ARBOL_ID, ARBOL_ID);
    arbol3->tx = 0;
    arbol3->ty = 0;
    arbol3->tz = 70;
    AddObject(arbol3);

    TPrimitiva *arbol4 = new TPrimitiva(ARBOL_ID, ARBOL_ID);
    arbol4->tx = 0;
    arbol4->ty = 0;
    arbol4->tz = -5;
    AddObject(arbol4);

    TPrimitiva *arbol5 = new TPrimitiva(ARBOL_ID, ARBOL_ID);
    arbol5->tx = 0;
    arbol5->ty = 0;
    arbol5->tz = 10;
    AddObject(arbol5);

    TPrimitiva *arbol6 = new TPrimitiva(ARBOL_ID, ARBOL_ID);
    arbol6->tx = 0;
    arbol6->ty = 0;
    arbol6->tz = 25;
    AddObject(arbol6);

    TPrimitiva *arbol7 = new TPrimitiva(ARBOL_ID, ARBOL_ID);
    arbol7->tx = 0;
    arbol7->ty = 0;
    arbol7->tz = 40;
    AddObject(arbol7);

    TPrimitiva *arbol8 = new TPrimitiva(ARBOL_ID, ARBOL_ID);
    arbol8->tx = 0;
    arbol8->ty = 0;
    arbol8->tz = 55;
    AddObject(arbol8);

    TPrimitiva *banco1 = new TPrimitiva(BANCO_ID, BANCO_ID);
    banco1->tx = 0;
    banco1->ty = 0;
    banco1->tz = 0;
    AddObject(banco1);

    TPrimitiva *banco2 = new TPrimitiva(BANCO_ID, BANCO_ID);
    banco2->tx = 0;
    banco2->ty = 0;
    banco2->tz = 10;
    AddObject(banco2);

    TPrimitiva *banco3 = new TPrimitiva(BANCO_ID, BANCO_ID);
    banco3->tx = 0;
    banco3->ty = 0;
    banco3->tz = 65;
    AddObject(banco3);

    TPrimitiva *faro = new TPrimitiva(FARO_ID, FARO_ID);
    faro->tx = 0;
    faro->ty = 0;
    faro->tz = 0;
    AddObject(faro);

    TPrimitiva *farola1 = new TPrimitiva(FAROLA_ID, FAROLA_ID);
    farola1->tx = 53;
    farola1->ty = 0;
    farola1->tz = 8;
    AddObject(farola1);

    TPrimitiva *farola2 = new TPrimitiva(FAROLA_ID, FAROLA_ID);
    farola2->tx = 53;
    farola2->ty = 0;
    farola2->tz = 23;
    AddObject(farola2);

    TPrimitiva *farola3 = new TPrimitiva(FAROLA_ID, FAROLA_ID);
    farola3->tx = 53;
    farola3->ty = 0;
    farola3->tz = 38;
    AddObject(farola3);

    TPrimitiva *farola4 = new TPrimitiva(FAROLA_ID, FAROLA_ID);
    farola4->tx = 53;
    farola4->ty = 0;
    farola4->tz = 53;
    AddObject(farola4);

    TPrimitiva *farola5 = new TPrimitiva(FAROLA_ID, FAROLA_ID);
    farola5->tx = 53;
    farola5->ty = 0;
    farola5->tz = -7;
    AddObject(farola5);

    TPrimitiva *farola6 = new TPrimitiva(FAROLA_ID, FAROLA_ID);
    farola6->tx = 53;
    farola6->ty = 0;
    farola6->tz = -22;
    AddObject(farola6);

    TPrimitiva *farola7 = new TPrimitiva(FAROLA_ID, FAROLA_ID);
    farola7->tx = 53;
    farola7->ty = 0;
    farola7->tz = -37;
    AddObject(farola7);

    TPrimitiva *pozo1 = new TPrimitiva(POZO_ID, POZO_ID);
    pozo1->tx = 0;
    pozo1->ty = 0;
    pozo1->tz = 0;
    AddObject(pozo1);

    TPrimitiva *domo = new TPrimitiva(DOMO_ID, DOMO_ID);
    domo->tx = 0;
    domo->ty = 0;
    domo->tz = 0;
    AddObject(domo);

    TPrimitiva *gimnasio = new TPrimitiva(GIMNASIO_ID, GIMNASIO_ID);
    gimnasio->tx = 0;
    gimnasio->ty = 0;
    gimnasio->tz = 0;
    AddObject(gimnasio);

    TPrimitiva *vallas = new TPrimitiva(VALLAS_ID, VALLAS_ID);
    vallas->tx = 0;
    vallas->ty = 0;
    vallas->tz = 0;
    AddObject(vallas);

    TPrimitiva *cesped = new TPrimitiva(CESPED_ID, CESPED_ID);
    cesped->tx = 0;
    cesped->ty = 0;
    cesped->tz = 0;
    AddObject(cesped);

    TPrimitiva *pino1 = new TPrimitiva(PINO_ID, PINO_ID);
    pino1->tx = 1;
    pino1->ty = 0;
    pino1->tz = 0;
    AddObject(pino1);

    TPrimitiva *pino2 = new TPrimitiva(PINO_ID, PINO_ID);
    pino2->tx = -10;
    pino2->ty = 0;
    pino2->tz = 0;
    AddObject(pino2);

    TPrimitiva *pino3 = new TPrimitiva(PINO_ID, PINO_ID);
    pino3->tx = 35;
    pino3->ty = 0;
    pino3->tz = -65;
    AddObject(pino3);

    TPrimitiva *pino4 = new TPrimitiva(PINO_ID, PINO_ID);
    pino4->tx = 33;
    pino4->ty = 0;
    pino4->tz = -55;
    AddObject(pino4);

    TPrimitiva *pino5 = new TPrimitiva(PINO_ID, PINO_ID);
    pino5->tx = -15;
    pino5->ty = 0;
    pino5->tz = -65;
    AddObject(pino5);

    TPrimitiva *pino6 = new TPrimitiva(PINO_ID, PINO_ID);
    pino6->tx = -10;
    pino6->ty = 0;
    pino6->tz = -67;
    AddObject(pino5);

    TPrimitiva *senial = new TPrimitiva(SENIAL_ID, SENIAL_ID);
    senial->tx = 0;
    senial->ty = 0;
    senial->tz = 0;
    AddObject(senial);

    TPrimitiva *semaforo1 = new TPrimitiva(SEMAFORO_ID, SEMAFORO_ID);
    semaforo1->tx = 0;
    semaforo1->ty = 0;
    semaforo1->tz = 0;
    AddObject(semaforo1);

    TPrimitiva *semaforo2 = new TPrimitiva(SEMAFORO_ID, SEMAFORO_ID);
    semaforo2->tx = 88.5;
    semaforo2->ty = 0;
    semaforo2->tz = 10;

    TPrimitiva *semaforo3 = new TPrimitiva(SEMAFORO_ID, SEMAFORO_ID);
    semaforo3->tx = 88.5;
    semaforo3->ty = 0;
    semaforo3->tz = 0;
    AddObject(semaforo3);

    TPrimitiva *semaforo4 = new TPrimitiva(SEMAFORO_ID, SEMAFORO_ID);
    semaforo4->tx = 0;
    semaforo4->ty = 0;
    semaforo4->tz = -28;
    AddObject(semaforo4);

    TPrimitiva *tienda = new TPrimitiva(TIENDA_ID, TIENDA_ID);
    tienda->tx = 0;
    tienda->ty = -1;
    tienda->tz = 0;
    AddObject(tienda);

    TPrimitiva *panteon = new TPrimitiva(PANTEON_ID, PANTEON_ID);
    panteon->tx = 0;
    panteon->ty = 0;
    panteon->tz = 0;
    AddObject(panteon);

    TPrimitiva *marcador = new TPrimitiva(MARCADOR_ID, MARCADOR_ID);
    marcador->tx = 500;
    marcador->ty = 500;
    marcador->tz = 500;
    AddMarcador(marcador); // PINO_GRANDE_ID
}

//************************************************************** Clase TGui

TGui::TGui()
{
    sel = 1;
    enable_panel2 = 1;
    light0_enabled = 1;
    light1_enabled = 0;
    light2_enabled = 0;
    light0_intensity = 0.8;
    light1_intensity = 0.8;
    light2_intensity = 0.8;

    memcpy(light0_position, light0_position_c, 4 * sizeof(float));
    memcpy(light1_position, light1_position_c, 4 * sizeof(float));
    memcpy(light2_position, light2_position_c, 4 * sizeof(float));
}

void controlCallback(int control)
{
    gui.ControlCallback(control);
}

void __fastcall TGui::Init(int main_window)
{

    /****************************************************/
    /*        Código con el interfaz Gráfico GLUI       */
    /****************************************************/
    printf("GLUI version: %3.2f\n", GLUI_Master.get_version());

    window_id = main_window;

    /*** Crea a ventana lateral ***/
    glui = GLUI_Master.create_glui_subwindow(window_id, GLUI_SUBWINDOW_RIGHT);

    // Añade una separación
    new GLUI_StaticText(glui, "");

    // Añade un panel con texto con el valor de la selección
    GLUI_Panel *panel0 = new GLUI_Panel(glui, "Seleccion");

    radioGroup = new GLUI_RadioGroup(panel0, &sel, SEL_ID, controlCallback);
    glui->add_radiobutton_to_group(radioGroup, "NINGUNO");
    glui->add_radiobutton_to_group(radioGroup, "COCHE 1");
    glui->add_radiobutton_to_group(radioGroup, "COCHE 2");

    // Añade una separación
    new GLUI_StaticText(glui, "");

    obj_panel = new GLUI_Rollout(glui, "Propiedades", true);

    /***** Control para las propiedades de escena *****/

    GLUI_Panel *obj_panel_visualizacion = new GLUI_Panel(obj_panel, "Modo de visualizacion");
    // obj_panel_visualizacion = new GLUI_Rollout(obj_panel, "Modo de visualizacion", true );
    GLUI_RadioGroup *radioGroupModos = new GLUI_RadioGroup(obj_panel_visualizacion, &escena.modo_wireframe, CONTROL_WIREFRAME, controlCallback);
    glui->add_radiobutton_to_group(radioGroupModos, "Solido");
    glui->add_radiobutton_to_group(radioGroupModos, "Alambrico");
    glui->add_radiobutton_to_group(radioGroupModos, "Punteado");

    GLUI_Panel *obj_panel_sombras = new GLUI_Panel(obj_panel, "Modo de sombreado");
    // obj_panel_sombras = new GLUI_Rollout(obj_panel, "Modo de sombreado", true );
    GLUI_RadioGroup *radioGroupSombras = new GLUI_RadioGroup(obj_panel_sombras, &escena.sombreado, SOMBREADO, controlCallback);
    glui->add_radiobutton_to_group(radioGroupSombras, "Suave");
    glui->add_radiobutton_to_group(radioGroupSombras, "Plano");

    new GLUI_Checkbox(obj_panel, "Culling", &escena.culling, CULLING, controlCallback);
    new GLUI_Checkbox(obj_panel, "Z Buffer", &escena.z_buffer, ZBUFFER, controlCallback);

    GLUI_Panel *obj_panel_sentido = new GLUI_Panel(obj_panel, "Sentido");
    // obj_panel_sentido = new GLUI_Rollout(obj_panel, "Sentido", true );
    GLUI_RadioGroup *radioGroupSentido = new GLUI_RadioGroup(obj_panel_sentido, &escena.sentido_horario, HORARIO, controlCallback);
    glui->add_radiobutton_to_group(radioGroupSentido, "Horario");
    glui->add_radiobutton_to_group(radioGroupSentido, "Antihorario");

    /******** Añade controles para las luces ********/

    // Añade una separación
    new GLUI_StaticText(glui, "");

    GLUI_Rollout *roll_lights = new GLUI_Rollout(glui, "Luces", true);

    GLUI_Panel *light0 = new GLUI_Panel(roll_lights, "Luz 1");
    GLUI_Panel *light1 = new GLUI_Panel(roll_lights, "Luz 2");
    GLUI_Panel *light2 = new GLUI_Panel(roll_lights, "Luz 3");

    new GLUI_Checkbox(light0, "Encendida", &light0_enabled, LIGHT0_ENABLED_ID, controlCallback);
    light0_spinner = new GLUI_Spinner(light0, "Intensidad:", &light0_intensity,
                                      LIGHT0_INTENSITY_ID, controlCallback);
    light0_spinner->set_float_limits(0.0, 1.0);
    GLUI_Scrollbar *sb;
    sb = new GLUI_Scrollbar(light0, "X", GLUI_SCROLL_HORIZONTAL,
                            &escena.light0_position[0], LIGHT0_POSITION_ID, controlCallback);
    sb->set_float_limits(-100, 100);
    sb = new GLUI_Scrollbar(light0, "Y", GLUI_SCROLL_HORIZONTAL,
                            &escena.light0_position[1], LIGHT0_POSITION_ID, controlCallback);
    sb->set_float_limits(-100, 100);
    sb = new GLUI_Scrollbar(light0, "Z", GLUI_SCROLL_HORIZONTAL,
                            &escena.light0_position[2], LIGHT0_POSITION_ID, controlCallback);
    sb->set_float_limits(-100, 100);

    new GLUI_Checkbox(light1, "Encendida", &light1_enabled, LIGHT1_ENABLED_ID, controlCallback);
    light1_spinner = new GLUI_Spinner(light1, "Intensidad:", &light1_intensity,
                                      LIGHT1_INTENSITY_ID, controlCallback);
    light1_spinner->set_float_limits(0.0, 1.0);
    sb = new GLUI_Scrollbar(light1, "X", GLUI_SCROLL_HORIZONTAL,
                            &escena.light1_position[0], LIGHT1_POSITION_ID, controlCallback);
    sb->set_float_limits(-100, 100);
    sb = new GLUI_Scrollbar(light1, "Y", GLUI_SCROLL_HORIZONTAL,
                            &escena.light1_position[1], LIGHT1_POSITION_ID, controlCallback);
    sb->set_float_limits(-100, 100);
    sb = new GLUI_Scrollbar(light1, "Z", GLUI_SCROLL_HORIZONTAL,
                            &escena.light1_position[2], LIGHT1_POSITION_ID, controlCallback);
    sb->set_float_limits(-100, 100);

    new GLUI_Checkbox(light2, "Encendida", &light2_enabled, LIGHT2_ENABLED_ID, controlCallback);
    light2_spinner = new GLUI_Spinner(light2, "Intensidad:", &light2_intensity,
                                      LIGHT2_INTENSITY_ID, controlCallback);
    light2_spinner->set_float_limits(0.0, 1.0);
    light2_spinner->activate(false);
    sb = new GLUI_Scrollbar(light2, "X", GLUI_SCROLL_HORIZONTAL,
                            &escena.light2_position[0], LIGHT2_POSITION_ID, controlCallback);
    sb->set_float_limits(-100, 100);
    sb = new GLUI_Scrollbar(light2, "Y", GLUI_SCROLL_HORIZONTAL,
                            &escena.light2_position[1], LIGHT2_POSITION_ID, controlCallback);
    sb->set_float_limits(-100, 100);
    sb = new GLUI_Scrollbar(light2, "Z", GLUI_SCROLL_HORIZONTAL,
                            &escena.light2_position[2], LIGHT2_POSITION_ID, controlCallback);
    sb->set_float_limits(-100, 100);

    // Añade una separación
    new GLUI_StaticText(glui, "");

    /***  Rollout de Opciones ***/
    GLUI_Rollout *options = new GLUI_Rollout(glui, "Opciones", false);
    new GLUI_Checkbox(options, "Dibujar Coche", &escena.show_car);
    new GLUI_Checkbox(options, "Dibujar Ruedas", &escena.show_wheels);
    new GLUI_Checkbox(options, "Dibujar Carretera", &escena.show_road);
    new GLUI_Checkbox(options, "Dibujar Objetos", &escena.show_objetos);

    /*** Disable/Enable botones ***/
    // Añade una separación
    /*** Disable/Enable botones ***/
    // Añade una separación
    new GLUI_StaticText(glui, "");
    new GLUI_Checkbox(glui, "Permitir Movimiento", &enable_panel2);

    obj_panel_opcionescamara = new GLUI_Rollout(glui, "Camara", false);

    GLUI_Panel *panelCamaras = new GLUI_Panel(obj_panel_opcionescamara, "Camaras");
    GLUI_RadioGroup *radioGroupCamaras = new GLUI_RadioGroup(panelCamaras, &escena.camara, CONTROL_CAMARA, controlCallback);
    glui->add_radiobutton_to_group(radioGroupCamaras, "Camara Principal");
    glui->add_radiobutton_to_group(radioGroupCamaras, "Camara Seguimiento");
    glui->add_radiobutton_to_group(radioGroupCamaras, "Camara Aerea");
    glui->add_radiobutton_to_group(radioGroupCamaras, "Camara Conductor");

    /*** Radio Group para las proyecciones ***/
    GLUI_Panel *panelProyeccion = new GLUI_Panel(obj_panel_opcionescamara, "Proyeccion");
    GLUI_RadioGroup *radioGroupProyeccion = new GLUI_RadioGroup(panelProyeccion, &escena.proyeccion, CONTROL_PROYECCION, controlCallback);
    glui->add_radiobutton_to_group(radioGroupProyeccion, "Perspectiva");
    glui->add_radiobutton_to_group(radioGroupProyeccion, "Paralela");

    // Añade una separación
    new GLUI_StaticText(glui, "");
    new GLUI_Button(glui, "Resetear camara", RESET_ID, controlCallback);
    new GLUI_Button(glui, "Reset posicion de los coches", RESET_POS_COCHES, controlCallback);

    // Añade una separación
    new GLUI_StaticText(glui, "");

    new GLUI_Separator(glui);

    // Añade una separación
    new GLUI_StaticText(glui, "");

    new GLUI_StaticText(glui, "  Autor: Alejandro Moreno Rodríguez");
    new GLUI_StaticText(glui, "  2012-2023 (C) Juan Antonio Puchol");

    // Añade una separación
    new GLUI_StaticText(glui, "");

    new GLUI_Separator(glui);

    // Añade una separación
    new GLUI_StaticText(glui, "");

    /****** A 'quit' button *****/
    new GLUI_Button(glui, "Salir", 0, (GLUI_Update_CB)exit);

    // Crea la subventana inferior
    glui2 = GLUI_Master.create_glui_subwindow(window_id, GLUI_SUBWINDOW_BOTTOM);

    /**** Link windows to GLUI, and register idle callback ******/
    glui->set_main_gfx_window(window_id);
    glui2->set_main_gfx_window(window_id);

    view_rot = new GLUI_Rotation(glui2, "Rotacion Escena", escena.view_rotate);
    view_rot->set_spin(1.0);
    new GLUI_Column(glui2, false);
    GLUI_Translation *trans_xy = new GLUI_Translation(glui2, "Traslacion Escena XY", GLUI_TRANSLATION_XY, escena.view_position);
    trans_xy->set_speed(.005);
    new GLUI_Column(glui2, false);
    GLUI_Translation *trans_x = new GLUI_Translation(glui2, "Traslacion Escena X", GLUI_TRANSLATION_X, escena.view_position);
    trans_x->set_speed(.005);
    new GLUI_Column(glui2, false);
    GLUI_Translation *trans_y = new GLUI_Translation(glui2, "Traslacion Escena Y", GLUI_TRANSLATION_Y, &escena.view_position[1]);
    trans_y->set_speed(.005);
    new GLUI_Column(glui2, false);
    GLUI_Translation *trans_z = new GLUI_Translation(glui2, "Traslacion Escena Z", GLUI_TRANSLATION_Z, &escena.scale);
    trans_z->set_speed(.005);
}

/**************************************** TGui::ControlCallback() *******************/

void __fastcall TGui::ControlCallback(int control)
{
    switch (control)
    {
    case CONTROL_PROYECCION:
    {
        if (escena.proyeccion == 1)
        {
            memcpy(escena.view_position, view_position_c, 3 * sizeof(float));
            view_rot->reset();
            escena.scale = 100.0;
        }
        escena.proyeccion = escena.proyeccion;
        break;
    }
    case LIGHT0_ENABLED_ID:
    {
        if (light0_enabled)
            light0_spinner->enable();
        else
            light0_spinner->disable();
        break;
    }
    case LIGHT1_ENABLED_ID:
    {
        if (light1_enabled)
            light1_spinner->enable();
        else
            light1_spinner->disable();
        break;
    }
    case LIGHT0_INTENSITY_ID:
    {

        float v[] = {
            escena.light0_diffuse[0], escena.light0_diffuse[1],
            escena.light0_diffuse[2], escena.light0_diffuse[3]};

        v[0] *= light0_intensity;
        v[1] *= light0_intensity;
        v[2] *= light0_intensity;
        break;
    }
    case LIGHT1_INTENSITY_ID:
    {

        float v[] = {
            escena.light1_diffuse[0], escena.light1_diffuse[1],
            escena.light1_diffuse[2], escena.light1_diffuse[3]};

        v[0] *= light1_intensity;
        v[1] *= light1_intensity;
        v[2] *= light1_intensity;
        break;
    }
    case ENABLE_ID:
    {
        glui2->enable();
        break;
    }
    case DISABLE_ID:
    {
        glui2->disable();
        break;
    }
    case SOMBREADO:
    {
        glEnable(GL_SHADE_MODEL);
        switch (escena.sombreado)
        {

        case 0:
        {
            std::cout << "Suave" << std::endl;
            glShadeModel(GL_SMOOTH);
            glEnable(GL_DITHER);

            break;
        }
        case 1:
        {
            std::cout << "Plano" << std::endl;
            glShadeModel(GL_FLAT);
            break;
        }
        }
        break;
    }
    case HORARIO:
    {
        glEnable(GL_FRONT_FACE);
        switch (escena.sentido_horario)
        {
        case 0:
        {
            std::cout << "Sentido horario activado" << std::endl;
            glFrontFace(GL_CCW);
            break;
        }
        case 1:
        {
            std::cout << "Sentido antihorario activado" << std::endl;
            glFrontFace(GL_CW);
            break;
        }
        }
        break;
    }
    case CONTROL_WIREFRAME:
    {
        switch (escena.modo_wireframe)
        {
        case 0:
        {
            printf("Modo wireframe: Solido \n");
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            break;
        }
        case 1:
        {
            printf("Modo wireframe: Alambrico \n");
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            break;
        }
        case 2:
        {
            printf("Modo wireframe: Punteado \n");
            glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
            break;
        }
        }
        break;
    }
    case CULLING:
    {
        if (escena.culling == 1)
        {
            glEnable(GL_CULL_FACE);
            glCullFace(GL_FRONT);
        }
        else
        {
            glDisable(GL_CULL_FACE);
        }
        break;
    }
    case ZBUFFER:
    {
        if (escena.z_buffer == 1)
        {
            glEnable(GL_DEPTH_TEST);
        }
        else
        {
            glDisable(GL_DEPTH_TEST);
        }
        break;
    }
    case RESET_ID:
    {
        memcpy(escena.view_position, view_position_c, 3 * sizeof(float));
        view_rot->reset();
        escena.scale = 100.0;
        break;
    }
    case RESET_POS_COCHES:
    {
        TPrimitiva *coche1 = escena.GetCar(1);
        TPrimitiva *coche2 = escena.GetCar(2);
        coche1->tx = -3.0;
        coche1->ty = 0.0;
        coche1->tz = -18.0;
        coche1->rx = 0.0;
        coche1->ry = 0.0;
        coche1->rz = 0.0;
        coche1->rr = 0.0;
        coche1->giro = 0;
        coche2->tx = 2;
        coche2->ty = 0.0;
        coche2->tz = -20.0;
        coche2->rx = 0.0;
        coche2->ry = 0.0;
        coche2->rz = 0.0;
        coche2->rr = 0.0;
        coche2->giro = 0;

        TPrimitiva *marcador = escena.GetMarcador();
        if (escena.seleccion == 1)
        {
            escena.show_marcador = 1;
            marcador->ry = coche1->ry;
            marcador->tx = coche1->tx;
            marcador->tz = coche1->tz;
            marcador->ry = coche1->ty;
        }
        else if (escena.seleccion == 2)
        {
            escena.show_marcador = 1;
            marcador->ry = coche2->ry;
            marcador->tx = coche2->tx;
            marcador->tz = coche2->tz;
            marcador->ry = coche2->ty;
        }
        else
        {
            escena.show_marcador = 0;
        }

        break;
    }
    case SEL_ID:
    {
        escena.seleccion = sel;
        // GLUI_Master.SetFocus(true);
        TPrimitiva *marcador = escena.GetMarcador();
        TPrimitiva *coche = escena.GetCar(escena.seleccion);

        if (coche)
        {
            escena.show_marcador = 1;
            marcador->ry = coche->ry;
            marcador->tx = coche->tx;
            marcador->tz = coche->tz;
            marcador->ty = coche->ty;
        }
        else
        {
            escena.show_marcador = 0;
        }
        break;
    }
    case CONTROL_CAMARA:
    {
        escena.modo_camara = escena.camara;
        break;
    }
    } // switch
}

/***************************************** TGui::Idle() ***********/

void __fastcall TGui::Idle(void)
{
    /* According to the GLUT specification, the current window is
       undefined during an idle callback.  So we need to explicitly change
       it if necessary */
    if (glutGetWindow() != window_id)
        glutSetWindow(window_id);

    /*  GLUI_Master.sync_live_all();  -- not needed - nothing to sync in this
                                         application  */
    if (enable_panel2)

        glui2->enable();
    else
        glui2->disable();

    glutPostRedisplay();
}

/**************************************** TGui::reshape() *************/

void __fastcall TGui::Reshape(int xx, int yy)
{
    int x, y, ancho, alto;
    GLUI_Master.get_viewport_area(&x, &y, &ancho, &alto);
    glViewport(x, y, ancho, alto);

    // !!!!! ATENCIÓN: comprobar que alto no sea 0, sino división por 0 !!!!!!
    escena.xy_aspect = (float)ancho / (float)alto;
    escena.projectionMatrix = glm::perspective(45.0f, escena.xy_aspect, 0.1f, 1000.0f);
    glUniformMatrix4fv(escena.uProjectionMatrixLocation, 1, GL_FALSE, glm::value_ptr(escena.projectionMatrix));

    // std::cout << "xy aspect: " << escena.xy_aspect << std::endl;

    glutPostRedisplay();
}

/***************************************** gui::motion() **********/

void __fastcall TGui::Motion(int x, int y)
{
    // std::cout << "Escena: " << escena.raton << std::endl;
    if (escena.raton == 1)
    {
        if (x > escena.last_x)
        { // Nos movemos a la derecha
            escena.view_position[0] += escena.factor_movimiento_camara;
        }
        else if (x < escena.last_x)
        { // Nos movemos a la izquierda
            escena.view_position[0] -= escena.factor_movimiento_camara;
        }

        if (y > escena.last_y)
        { // Nos movemos arriba
            escena.view_position[1] -= escena.factor_movimiento_camara;
        }
        else if (y < escena.last_y)
        { // Nos movemos abajo
            escena.view_position[1] += escena.factor_movimiento_camara;
        }
    }
    else if (escena.raton == 2)
    {
        if (y < escena.last_y)
        {
            escena.view_position[2] += escena.factor_movimiento_camara * 2;
        }
        else if (y > escena.last_y)
        {
            escena.view_position[2] -= escena.factor_movimiento_camara * 2;
        }
    }
    else if (escena.raton == 3)
    {
        float rotacion[16];
        float rotacion_X_dec = x - escena.last_x;
        float rotacion_Y_dec = y - escena.last_y;

        escena.rotacion_X += rotacion_X_dec;
        escena.rotacion_Y += rotacion_Y_dec;

        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glLoadIdentity();

        glRotated(escena.rotacion_X * escena.factor_movimiento_camara, 0, 1, 0);
        glRotated(escena.rotacion_Y * escena.factor_movimiento_camara, 1, 0, 0);

        glGetFloatv(GL_MODELVIEW_MATRIX, rotacion);
        for (int i = 0; i < 16; i++)
        {
            if (escena.view_rotate[i] != rotacion[i])
            {
                escena.view_rotate[i] = rotacion[i];
            }
        }
        glPopMatrix();
    }
    else if (escena.raton == 4)
    {
        float rotacion[16];
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glLoadIdentity();

        float rotacion_Z_dec = (y - escena.last_y) - (x - escena.last_x);
        escena.rotacion_Z += rotacion_Z_dec;

        glRotated(escena.rotacion_Z * escena.factor_movimiento_camara, 0, 1, 0);

        glGetFloatv(GL_MODELVIEW_MATRIX, rotacion);

        for (int i = 0; i < 16; i++)
        {
            if (escena.view_rotate[i] != rotacion[i])
            {
                escena.view_rotate[i] = rotacion[i];
            }
        }
    }
    else if (escena.raton == 5)
    {
        if (y < escena.last_y)
        {
            escena.scale += escena.factor_movimiento_camara * 0.55;
            escena.scaleZ += 1.01;
        }
        else if (y > escena.last_y)
        {
            escena.scale -= escena.factor_movimiento_camara * 1.05;
            escena.scaleZ -= 1.01;
        }
    }
    else if (escena.raton == 6)
    {
        if (y > escena.last_y)
        {
            escena.scaleZ += 0.01;
        }
        else if (y < escena.last_y)
        {
            escena.scaleZ -= 0.01;
        }
    }
    escena.last_x = x;
    escena.last_y = y;
    glutPostRedisplay();
}

/***************************************** gui::Mouse() **********/

void __fastcall TGui::Mouse(int button, int button_state, int x, int y)
{
    if (button_state == GLUT_DOWN && escena.camara_Movil == 0)
    {
        // glutGetModifiers() devuelve GLUT_ACTIVE_CTRL, GLUT_ACTIVE_SHIFT, y GLUT_ACTIVE_ALT
        int x = glutGetModifiers();

        // FLECHA IZQUIERDA.
        if ((button == GLUT_LEFT_BUTTON && glutGetModifiers() == 3) || (button == GLUT_MIDDLE_BUTTON && button_state == GLUT_DOWN))
            escena.raton = 2; // MOVIMIENTO EN Z
                              // Izquierdo y shift y control
        else if (button == GLUT_LEFT_BUTTON && glutGetModifiers() != GLUT_ACTIVE_CTRL && glutGetModifiers() != GLUT_ACTIVE_SHIFT)
            escena.raton = 3; // ROTAR EN X Y
        // Solo boton izquierdo
        else if (button == GLUT_RIGHT_BUTTON && glutGetModifiers() != GLUT_ACTIVE_CTRL && glutGetModifiers() != GLUT_ACTIVE_SHIFT)
            escena.raton = 5; // Escalado
        // Solo boton derecho
        else if (button == GLUT_LEFT_BUTTON && glutGetModifiers() == GLUT_ACTIVE_CTRL)
            escena.raton = 4; // ROTAR EN Z
        // Boton izquierdo y control
        else if (button == GLUT_RIGHT_BUTTON && glutGetModifiers() == GLUT_ACTIVE_CTRL) // No hacer ahora
            escena.raton = 6;                                                           // Escalado en Z
        // Boton Derecho y control
        else if (button == GLUT_LEFT_BUTTON && glutGetModifiers() == GLUT_ACTIVE_SHIFT)
            escena.raton = 1; // MOVERSE CON RATON
        // Izquierdo y shift
        escena.last_x = x;
        escena.last_y = y;
    }
    else if (button_state == GLUT_UP) // Liberar tecla
    {
        escena.raton = 0;
        if (button == GLUT_LEFT_BUTTON && escena.camara_Movil == 0)
            escena.Pick3D(x, y);
    }
}
