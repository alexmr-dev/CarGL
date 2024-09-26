
/****************************************************************************************************

    CarGL (main.cpp)

    Grado en Ingenier�a Multimedia.
    Pr�ctica de Gr�ficos por Computador.
    OpenGL con Shaders.
  ------------------------------------------------------------------------------------------

    CarsGL, 2012 - 2022 (C) Juan Antonio Puchol Garc�a (puchol@dccia.ua.es)

    Changelog:

    Versi�n 1.0 (Noviembre 2012)
        - Versi�n inicial para Code::Blocks 10.05

    Versi�n 1.1 (Noviembre 2012)
        - Arreglado el bug de selecci�n incorrecta debido al panel inferior de controles

    Versi�n 1.2 (Octubre 2013 )
        - Adaptaci�n de la librer�a GLUI a Code::Blocks 12.11 y 13.12

    Versi�n 1.3 (Octubre 2014 )
        - Adaptaci�n de la librer�a GLUI a Code::Blocks 13.12

    Versi�n 2.0 (Octubre 2015 )
        - Adaptaci�n del c�digo empleando Shaders (Modern OpenGL Graphics)

    Versi�n 2.1 (Septiembre 2016 )
        - Modificaci�n de los scrollbars de las luces para manipular la posisi�n (compatible con Code::Blocks 16.01)

    Versi�n 2.2 (Octubre 2022 )
        - Correcci�n de peque�os bugs
        - A�adidos dos edificios de ejemplo (m�todo TEscena::CrearEscena)

    ----------------------------------------------------------------------------------------------------------------

    NOTA:   Para que esta aplicaci�n compile correctamente se necesita tener copiados los
            siguientes archivos desde la carpeta "Para Copiar":

            glut32.dll  -> C:\Windows\system

            Si es un Windows de 32 bits:
            glew32s.lib -> C:\Program Files\CodeBlocks\MinGW\lib
            glew32.lib  -> C:\Program Files\CodeBlocks\MinGW\lib
            libglui32.a -> C:\Program Files\CodeBlocks\MinGW\lib
            glut32.lib  -> C:\Program Files\CodeBlocks\MinGW\lib

            glui.h      -> C:\Program Files\CodeBlocks\MinGW\include\GL
            glut.h      -> C:\Program Files\CodeBlocks\MinGW\include\GL
            glew.h      -> C:\Program Files\CodeBlocks\MinGW\include\GL

            y la carpeta completa
            glm         -> C:\Program Files\CodeBlocks\MinGW\include

            Si es un Windows de 64 bits:
            glew32s.lib -> C:\Program Files (x86)\CodeBlocks\MinGW\lib
            glew32.lib  -> C:\Program Files (x86)\CodeBlocks\MinGW\lib
            libglui32.a -> C:\Program Files (x86)\CodeBlocks\MinGW\lib
            glut32.lib  -> C:\Program Files (x86)\CodeBlocks\MinGW\lib

            glui.h      -> C:\Program Files (x86)\CodeBlocks\MinGW\include\GL
            glut.h      -> C:\Program Files (x86)\CodeBlocks\MinGW\include\GL
            glew.h      -> C:\Program Files (x86)\CodeBlocks\MinGW\include\GL

            y la carpeta completa
            glm         -> C:\Program Files (x86)\CodeBlocks\MinGW\include


            ACLARACI�N:
                Hay varias librer�as libglui32.a en la carpeta "otros"
                - Renombrar libglui32.10.05.a a libglui32.a para usar Code::Blocks 10.05
                - Renombrar libglui32.12.11.a a libglui32.a para usar Code::Blocks 12.11
                - Renombrar libglui32.13.12.a a libglui32.a para usar Code::Blocks 13.12 a 17.12
                - De momento no funciona con la versi�n Code::Blocks 20.03

****************************************************************************************************/

#include "Objects.h"
#include <GL\glui.h>
#include "loadjpeg.c"


/**************************************** myGlutKeyboard() **********/

void Keyboard(unsigned char Key, int x, int y)
{
    switch(Key)
    {
        case 27:
        case 'q':
            exit(0);
            break;
        case 'x':
        case 'X':
            escena.rotacion_X=1;
            escena.rotacion_Y=0;
            escena.rotacion_Z=0;
        break;
        case 'y':
        case 'Y':
            escena.rotacion_X=0;
            escena.rotacion_Y=1;
            escena.rotacion_Z=0;
        break;

        case 'z':
        case 'Z':
            escena.rotacion_X=0;
            escena.rotacion_Y=0;
            escena.rotacion_Z=1;
        break;

    }

    glutPostRedisplay();
}

/**************************************** mySpecialKey() *************/

static void SpecialKey(int key, int x, int y)
{
    if(escena.seleccion!=0) {

        TPrimitiva *car = escena.GetCar(escena.seleccion);
        TPrimitiva *marcador = escena.GetMarcador();
        float grados = car->ry*3.14159265358979/180;

        switch (key)
        {
            case GLUT_KEY_UP:   // El coche avanza
                car->rr+=8;
                car->tx += 0.8*sin(grados);
                car->tz += 0.8*cos(grados);
                car->ry += 0.1*car->giro;
                marcador->rr+=8;
                marcador->tx += 0.8*sin(grados);
                marcador->tz += 0.8*cos(grados);
                marcador->ry += 0.1*car->giro;
                break;
            case GLUT_KEY_DOWN:   // El coche retrocede
                car->rr-=8;
                car->tx -= 0.8*sin(grados);
                car->tz -= 0.8*cos(grados);
                car->ry -= 0.1*car->giro;
                marcador->rr-=8;
                marcador->tx -= 0.8*sin(grados);
                marcador->tz -= 0.8*cos(grados);
                marcador->ry -= 0.1*car->giro;
                break;
            case GLUT_KEY_LEFT:  { //El coche gira a la izq
                if(car->giro < 30) car->giro += 4;
                break;
            }
            case GLUT_KEY_RIGHT: { //El coche gira a la dere
                if(car->giro > -30) car->giro -= 4;
                break;
            }
        }

    }
    else {
        printf("Ningun coche seleccionado \n", escena.seleccion);
    }
    glutPostRedisplay();
}

/***************************************** myGlutMenu() ***********/

void Menu( int value )
{
  Keyboard( value, 0, 0 );
}

void Mouse(int button, int button_state, int x, int y )
{
    gui.Mouse(button, button_state, x, y);
}

void Render()
{
    escena.Render();
}

void Idle()
{
    gui.Idle();
}

void Reshape(int x, int y){
    gui.Reshape(x, y);
}

void Motion(int x, int y){
    gui.Motion(x, y);
}

/**************************************** Texturas ******************/
void cargarTextura(int id){
    int width, height;
    unsigned char *img;

    width = escena.texturas_width[id];
    height = escena.texturas_height[id];
    img = escena.texturas[id];

    glBindTexture(GL_TEXTURE_2D, escena.texturas_id[id]);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, img);
}

void cargarTexturas(){

    escena.texturas[0] = LoadJPEG("../../Texturas/Acera.jpg",
                                  &escena.texturas_width[0],
                                  &escena.texturas_height[0]);
    escena.texturas[1] = LoadJPEG("../../Texturas/Arbeloa.jpg",
                                  &escena.texturas_width[1],
                                  &escena.texturas_height[1]);
    escena.texturas[2] = LoadJPEG("../../Texturas/Arbol.jpg",
                                  &escena.texturas_width[2],
                                  &escena.texturas_height[2]);
    escena.texturas[3] = LoadJPEG("../../Texturas/Arco_Jap.jpg",
                                  &escena.texturas_width[3],
                                  &escena.texturas_height[3]);
    escena.texturas[4] = LoadJPEG("../../Texturas/Banco.jpg",
                                  &escena.texturas_width[4],
                                  &escena.texturas_height[4]);
    escena.texturas[5] = LoadJPEG("../../Texturas/Carretera.jpg",
                                  &escena.texturas_width[5],
                                  &escena.texturas_height[5]);
    escena.texturas[6] = LoadJPEG("../../Texturas/Cesped.jpg",
                                  &escena.texturas_width[6],
                                  &escena.texturas_height[6]);
    escena.texturas[7] = LoadJPEG("../../Texturas/Domo.jpg",
                                  &escena.texturas_width[7],
                                  &escena.texturas_height[7]);
    escena.texturas[8] = LoadJPEG("../../Texturas/Edificio.jpg",
                                  &escena.texturas_width[8],
                                  &escena.texturas_height[8]);
    escena.texturas[9] = LoadJPEG("../../Texturas/Faro.jpg",
                                  &escena.texturas_width[9],
                                  &escena.texturas_height[9]);
    escena.texturas[10] = LoadJPEG("../../Texturas/Farola.jpg",
                                  &escena.texturas_width[10],
                                  &escena.texturas_height[10]);
    escena.texturas[11] = LoadJPEG("../../Texturas/Fuente.jpg",
                                  &escena.texturas_width[11],
                                  &escena.texturas_height[11]);
    escena.texturas[12] = LoadJPEG("../../Texturas/Gimnasio.jpg",
                                  &escena.texturas_width[12],
                                  &escena.texturas_height[12]);
    escena.texturas[13] = LoadJPEG("../../Texturas/Lineas.jpg",
                                  &escena.texturas_width[13],
                                  &escena.texturas_height[13]);
    escena.texturas[14] = LoadJPEG("../../Texturas/Panteon.jpg",
                                  &escena.texturas_width[14],
                                  &escena.texturas_height[14]);
    escena.texturas[15] = LoadJPEG("../../Texturas/Pino.jpg",
                                  &escena.texturas_width[15],
                                  &escena.texturas_height[15]);
    escena.texturas[16] = LoadJPEG("../../Texturas/Pozo.jpg",
                                  &escena.texturas_width[16],
                                  &escena.texturas_height[16]);
    escena.texturas[17] = LoadJPEG("../../Texturas/Semaforo.jpg",
                                  &escena.texturas_width[17],
                                  &escena.texturas_height[17]);
    escena.texturas[18] = LoadJPEG("../../Texturas/Senial.jpg",
                                  &escena.texturas_width[18],
                                  &escena.texturas_height[18]);
    escena.texturas[19] = LoadJPEG("../../Texturas/Tienda.jpg",
                                  &escena.texturas_width[19],
                                  &escena.texturas_height[19]);
    escena.texturas[20] = LoadJPEG("../../Texturas/Vallas.jpg",
                                  &escena.texturas_width[20],
                                  &escena.texturas_height[20]);
    escena.texturas[21] = LoadJPEG("../../Texturas/Coche.jpg",
                                  &escena.texturas_width[21],
                                  &escena.texturas_height[21]);
    escena.texturas[22] = LoadJPEG("../../Texturas/Cartel.jpg",
                                  &escena.texturas_width[22],
                                  &escena.texturas_height[22]);
    escena.texturas[23] = LoadJPEG("../../Texturas/Marcador.jpg",
                                  &escena.texturas_width[23],
                                  &escena.texturas_height[23]);
    escena.texturas[24] = LoadJPEG("../../Texturas/RuedaNueva.jpg",
                                  &escena.texturas_width[24],
                                  &escena.texturas_height[24]);

    glGenTextures(100, escena.texturas_id);

    for(int i = 0; i < 100; i++){
        cargarTextura(i);
    }
    std::cout << std::endl;
}
//SKYBOX

/**************************************** main() ********************/

int main(int argc, char* argv[])
{
    // Inicializa GLUT and crea la ventana principal
    glutInit(&argc, argv);
    glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH | GLUT_STENCIL | GLUT_MULTISAMPLE );
    glutInitWindowPosition( 10, 10 );
    glutInitWindowSize( 1200, 800 );

    int main_window = glutCreateWindow( "CarGL V2.2 (2023) con Shaders - Alejandro Moreno Rodriguez" );

    // Inicializa los valores de OpenGL para esta Aplicaci�n
    escena.InitGL();
    gui.Init(main_window);

    glutDisplayFunc( Render );
    GLUI_Master.set_glutReshapeFunc( Reshape );
    GLUI_Master.set_glutKeyboardFunc( Keyboard );
    GLUI_Master.set_glutSpecialFunc( SpecialKey );
    GLUI_Master.set_glutMouseFunc( Mouse );
    glutMotionFunc( Motion );

    /**** We register the idle callback with GLUI, *not* with GLUT ****/
    GLUI_Master.set_glutIdleFunc( Idle );

    // Crea el escenario
    escena.CrearEscenario();

    cargarTexturas();

    /**** Regular GLUT main loop ****/
    glutMainLoop();

    return EXIT_SUCCESS;
}

