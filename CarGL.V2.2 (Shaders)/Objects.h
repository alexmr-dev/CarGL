
/***************************************************************************************

    CarGL (Objects.h)

    Grado en Ingeniería Multimedia.
    Práctica de Gráficos por Computador.
    OpenGL con Shaders.
  --------------------------------------------------------------------------------------

    2012 - 2022 (C) Juan Antonio Puchol García (puchol@dccia.ua.es)

****************************************************************************************/

//---------------------------------------------------------------------------
#ifndef ObjectsH
#define ObjectsH
//---------------------------------------------------------------------------

#define GLEW_STATIC

#include "Shader.h"
#include "Program.h"

#include <GL/glui.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// Identificadores internos de los objetos y el coche
#define ACERA_ID        10
#define ARBELOA_ID      11
#define ARBOL_ID        12
#define ARCO_JAP_ID     13
#define AVION_ID        14
#define BANCO_ID        15
#define CARRETERA_ID    16
#define CESPED_ID       17
#define DOMO_ID         18
#define EDIFICIO_ID     19
#define FARO_ID         20
#define FAROLA_ID       21
#define FUENTE_ID       22
#define GIMNASIO_ID     23
#define LINES_ID        24
#define MARCADOR_ID     25
#define PANTEON_ID      26
#define PINO_ID         27
#define PINO_GRANDE_ID  28
#define POZO_ID         29
#define SEMAFORO_ID     30
#define SENIAL_ID       31
#define TIENDA_ID       32
#define VALLAS_ID       33
#define CARTEL_ID       34
#define CIELO_ID        35

#define COCHE_ID	    500

// IDs para los callbacks de TGui
#define LIGHT0_ENABLED_ID    200
#define LIGHT1_ENABLED_ID    201
#define LIGHT2_ENABLED_ID    202

#define LIGHT0_POSITION_ID   210
#define LIGHT1_POSITION_ID   211
#define LIGHT2_POSITION_ID   212

#define LIGHT0_INTENSITY_ID  220
#define LIGHT1_INTENSITY_ID  221
#define LIGHT2_INTENSITY_ID  225

#define ENABLE_ID            300
#define DISABLE_ID           301

#define ZBUFFER              398
#define CULLING              399
#define RESET_POS_COCHES     401
#define CONTROL_WIREFRAME    402
#define HORARIO              403
#define SOMBREADO            404
#define TRANSPARENCIA        405
#define CONTROL_PROYECCION   406

#define RESET_ID             400

#define SEL_ID               500
#define CONTROL_CAMARA       600

// Datos del formato 3DS (x, y, z, A, B, C, u, v)
#define POSITION_COMPONENT_COUNT    3
#define NORMAL_COMPONENT_COUNT      3
#define UV_COMPONENT_COUNT          2
// Cálculo del stride (3+3+2)*4 = 8*4 = 32
#define STRIDE                      32

// Nombre de los attributes
#define A_POSITION  "a_Position"
#define A_NORMAL    "a_Normal"

// Nombre de los uniforms
#define U_PROJECTIONMATRIX      "u_ProjectionMatrix"
#define U_MVMATRIX              "u_MVMatrix"
#define U_VMATRIX               "u_VMatrix"
#define U_COLOR                 "u_Color"
#define U_LUZ0                  "u_Luz0"
#define U_LUZ1                  "u_Luz1"
#define U_LUZ2                  "u_Luz2"

//Seleccion.
#define U_SELECTION_ENABLED     "u_selection_enabled"

//Texturas
#define A_TEXTURECORD "a_TextureCoord"
#define U_SAMPLER "u_Sampler"


//************************************************************** Clase TPrimtiva

class TPrimitiva
{
public: // Atributos de la clase
		int ID;				    // DisplayLists del objeto
		int tipo;               // Tipo de Objeto
		float tx,ty,tz; 	    // Posición del objeto
		float sx,sy,sz; 	    // Escalado del objeto
		float rx,ry,rz;     	// Rotación del objeto
		float rr;               // Rotación de las ruedas
		float colores[2][4];    // Color RGB y canal Alfa
		float giro;             // Giro del vehiculo

		float   *modelo0;        // modelo a representar
		int     num_vertices0;   // número de vértices

        float   *modelo1;        // modelo a representar
		int     num_vertices1;   // número de vértices

		float   *modelo2;        // modelo a representar
		int     num_vertices2;   // número de vértices

		float tdx, tdy, tdz;
		float tix, tiy, tiz;

		float rra;

		// giro de las ruedas
		float rrz;
		float rcar;

        float velocidad;

public: // Métodos
 		TPrimitiva(int DL, int tipo);
        void __fastcall Render(int seleccion, bool reflejo=false);
};

//************************************************************** Clase TEscena

class TEscena
{
public:
    // Texturas
    unsigned char *texturas[100];
    int texturas_width[100];
    int texturas_height[100];
    GLuint texturas_id[100];

public: // Atributos de la clase
		int   	seleccion;   	// Objeto seleccionado, 0=ninguno
        int		num_objects;    // Número de objetos (excepto coches)
        int     num_cars;       // Número de coches
        int     num_marcador;

        TPrimitiva  *cars[10];
        TPrimitiva  *objects[100];
        TPrimitiva  *marcadores[10];

        // Handles de los attributes y uniforms
        int aPositionLocation;
        int aNormalLocation;

        // Para las texturas
        int aTextureCoordLocation;
		int u_SamplerLocation;
		int activadaLocation;

		int u_Position_Luz0Location;
        int u_Position_Luz1Location;
        int u_Position_Luz2Location;

        int u_Intensidad0Location;
        int u_Intensidad1Location;
        int u_Intensidad2Location;

        int uProjectionMatrixLocation;
        int uMVMatrixLocation;
		int uVMatrixLocation;
		int uColorLocation;

		int uSelectionEnabledLocation;

        int uLuz0Location;      // Activada la luz 0
		int uLuz1Location;      // Activada la luz 1
		int uLuz2Location;      // Activada la luz 2

		int puntoPick3D;

		glm::mat4 projectionMatrix; // Almacena la matriz de proyección
        glm::mat4 viewMatrix;       // Almacena la matriz de la vista (cámara)

		Program  *shaderProgram;    // Almacena el programa de OpenGL (ShaderProgram)

        // Vectores de luces y materiales
        GLfloat light0_ambient[4];
        GLfloat light0_diffuse[4];
        GLfloat light0_specular[4];
        GLfloat light0_position[4];

        GLfloat light1_ambient[4];
        GLfloat light1_diffuse[4];
        GLfloat light1_specular[4];
        GLfloat light1_position[4];

        GLfloat light2_ambient[4];
        GLfloat light2_diffuse[4];
        GLfloat light2_specular[4];
        GLfloat light2_position[4];

        GLfloat mat_ambient[4];
        GLfloat mat_diffuse[4];
        GLfloat mat_specular[4];
        GLfloat mat_shininess[1];

        float   xy_aspect;
        int     last_x, last_y;

        // live variables usadas por GLUI en TGui
        int     wireframe;
        int     z_buffer;
        int     culling;

        int     show_car;
        int     show_wheels;
        int     show_road;

        //Personalizadas
        int     show_acera;
        int     show_objetos;
        int     show_marcador;

        int     camara;
        int     modo_camara;
        int     modo_wireframe;
        int     sentido_horario;
        int     sombreado;
        int     proyeccion;
        int     transparencia;

        int     raton;
        float   factor_movimiento_camara;
        int     rotacion_X;
        int     rotacion_Y;
        int     rotacion_Z;
        float   scaleZ;
        int     camara_Movil;

        GLfloat view_position[3];
        GLfloat view_rotate[16];
        float   scale;

public: // Métodos
		TEscena();

        void __fastcall InitGL();
		void __fastcall Render();
		void __fastcall RenderCars(bool reflejo=false);
		void __fastcall RenderObjects(bool reflejo=false);
		void __fastcall RenderMarcador(bool reflejo=false);

        void __fastcall RenderSelection();

		void __fastcall AddCar(TPrimitiva *car);
		void __fastcall AddObject(TPrimitiva *object);
		void __fastcall AddMarcador(TPrimitiva *marcador);
        void __fastcall CrearEscenario();

		TPrimitiva __fastcall *GetCar(int id);
		TPrimitiva __fastcall  *GetMarcador();

		void __fastcall Pick3D(int mouse_x, int mouse_y);


};

//************************************************************** Clase TGui

class TGui
{
public:
        int             window_id;

        // live variables usadas por GLUI
        int             sel;
        int             enable_panel2;
        int             light0_enabled;
        int             light1_enabled;
        int             light2_enabled;

        float           light0_intensity;
        float           light1_intensity;
        float           light2_intensity;

        float           light0_position[4];
        float           light1_position[4];
        float           light2_position[4];

        GLUI            *glui, *glui2;
        GLUI_Spinner    *light0_spinner;
        GLUI_Spinner    *light1_spinner;
        GLUI_Spinner    *light2_spinner;
        GLUI_RadioGroup *radioGroup;
        GLUI_RadioGroup *radioGroup_Selected;
        GLUI_Panel      *obj_panel;
        GLUI_Panel      *obj_panel_visualizacion;
        GLUI_Panel      *obj_panel_sombras;
        GLUI_Panel      *obj_panel_sentido;
        GLUI_Panel      *obj_panel_opcionescamara;
        GLUI_Rotation   *view_rot;

public:
        TGui();
        void __fastcall Init(int main_window);
        void __fastcall ControlCallback(int control);
        void __fastcall Idle( void );
        void __fastcall Reshape( int x, int y  );
        void __fastcall Motion( int x, int y  );
        void __fastcall Mouse(int button, int button_state, int x, int y );
};

//************************************************************** Variables de clase

extern TEscena  escena;
extern TGui     gui;

#endif
