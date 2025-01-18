//Mauricio Farro Izquierdo
#include <GL/glut.h> //funciones de OpenGL
#include <iostream>  //para imprimir en consola
#include <ctime>     //para obtener la hora actual
#include <cstdlib>   //para funciones aleatorias
#include <cmath>     //para funciones matemáticas

using namespace std;

//variables globales:
//variables para el color (los mas comunes que voy a usar)
const float celeste[3] = {0.7, 0.7, 1}; 
const float rojo[3] = {1, 0, 0};     
const float verde[3] = {0, 1, 0};     
const float gris[3] = {0.9, 0.9, 0.9}; 
//variables usadas tanto en actualizar como en dibujar
int scoreazul = 0;
int scorerojo = 0;
int tiempo = 0; // Inicializar tiempo a 0
bool isfirsthalf = true;

//estadisticas (dibujar , actualizar)
int saquesdebandaazul, saquesdebandarojo;
int saquesdecentroazul, saquesdecentrorojo;
int lanzamientosdemetrosazul, lanzamientosdemetrosrojo;
int tiroslibresazul, tiroslibresrojo;
int faltasazul, faltasrojo;
int sancionesazul, sancionesrojo;
int tirosapuertaazul, tirosapuertarojo;

//inicializacion de variables
void initstatistics() {
    
    saquesdebandaazul = 0 ;
    saquesdebandarojo = 0;
    saquesdecentroazul = 0;
    saquesdecentrorojo = 0;
    lanzamientosdemetrosazul = 0;
    lanzamientosdemetrosrojo = 0;
    tiroslibresazul = 0;
    tiroslibresrojo = 0;
    faltasazul = 0;
    faltasrojo = 0;
    sancionesazul = 0;
    sancionesrojo = 0,
    tirosapuertaazul = 0;
    tirosapuertarojo = 0;
}

/* x:posicio en x ; posicion en y ; fuente ; string : texto a mostrar
    funcion para mostrar texto en pantalla
*/
void renderbitmapstring(float x, float y, void *font, const char *string) {
    glRasterPos2f(x, y);
    while (*string)
        glutBitmapCharacter(font, *string++);
}
//Proceso para dibujar rectangulos
/*variables : x , y : cordenadas - ancho , largo : longitud
            r:controla el color rojo 
						g:controla el color verde
						b:controla el color azul    */
void rectangulo (float x, float y, float ancho, float largo, float r, 
float g, float b) {
  glPushMatrix();
	glColor3f(r, g, b); //para q en la llamada yo pueda darle color
	glBegin(GL_QUADS);  //funcion para dibujar cuadrilateros 
	glVertex2f(x, y);   //funcion de los vertices
	glVertex2f(x + ancho, y);
	glVertex2f(x + ancho, y + largo); 
	glVertex2f(x, y + largo);
  glPopMatrix();
  glEnd();
}

// proceso dibujar circulos
/*variables  : 1.cx : cordenadas en x - 2.cy:cordenadas en y - 3.radio  
               4.ainicial : angulo inicial - 5.afinal : angulo final 
	             6.color : !aqui coloco el array de los colores  
               7.completo es para que el circulo tenga relleno o no  */
void circulos(float cx, float cy, float radio, float ainicial, float afinal, 
const float color[3], bool completo = false) { 
  int n_segmentos = 100; // Mayor número, más suave será el círculo
  float rotacionang = (afinal - ainicial) / n_segmentos;
  
  if (completo) {
  	glColor3fv(color);  // !aqui va el arreglo
    glBegin(GL_TRIANGLE_FAN); // para que tenga relleno
    glVertex2f(cx, cy); // ubicacion
  } 
	else {
   glBegin(GL_LINE_STRIP); // solo la linea
  }
  for (int i = 0; i <= n_segmentos; ++i) {
  	//Dibujar lineas juntas para formar un círculo rotandolas
    float angulo = ainicial + i * rotacionang;
    float x = cx + radio * cos(angulo); // curva x
    float y = cy + radio * sin(angulo); // curva y
    glVertex2f(x, y);//ubicacion de la linea
  }
  glEnd();//acaba dibujo
}
//proceso para dibujar nube
 void nube(float x , float y ){
 	glPushMatrix(); //en esta funcion se puede modificar sin afectar lo de afuera
  	glTranslated(x,y,0);//para poder dibujar el personaje donde sea
  	glScalef(1, 1, 1);  //escala
  	
    circulos(-0.,-0.5,0.4,0, 2* M_PI , celeste , true );
    circulos(-0.4,-0.3,0.4,0, 2* M_PI , celeste , true );
    circulos(-0.1,-0.6,0.4,0, 2* M_PI , celeste , true );
    circulos(0.3,-0.3,0.4,0, 2* M_PI , celeste , true );
    circulos(0.6,-0.5,0.4,0, 2* M_PI , celeste , true );
  	
  	glPopMatrix();
 	
 }
//processo para dibujar
void dibujar() {
  glClear(GL_COLOR_BUFFER_BIT);
    
  nube (0,0);
  rectangulo(-0.61,0.63,1.23,0.13,0.9,0.9,0.9);
  
  glPushMatrix();
	glColor3f(0.9,0.9,0.9);  //para q en la llamada yo pueda darle color
	glBegin(GL_POLYGON);     //funcion para dibujar poligonos
	glVertex2f(-0.3, 0.76);  //funcion de los vertices
	glVertex2f(-0.2 , 0.86);
	glVertex2f(0.2 , 0.86); 
	glVertex2f(+0.3, 0.76);
  glPopMatrix();
  glEnd();
  
  glPushMatrix();
	glColor3f(0.95,0.95,0.95); 
	glBegin(GL_POLYGON); 
	glVertex2f(-0.27, 0.77);  
	glVertex2f(-0.18, 0.84);
	glVertex2f(0.18, 0.84); 
	glVertex2f(+0.27, 0.77);
  glPopMatrix();
  glEnd();
  
  glPushMatrix();
	glColor3f(0.3,0.3,0.3); 
	glBegin(GL_POLYGON); 
	glVertex2f(-0.61, 0.65);  
	glVertex2f(-0.61, 0.74);
	glVertex2f(-0.23, 0.74); 
	glVertex2f(-0.10, 0.65);
  glPopMatrix();
  glEnd();
  
  glPushMatrix();
	glColor3f(0.3,0.3,0.3); 
	glBegin(GL_POLYGON); 
	glVertex2f(0.10, 0.65);  
	glVertex2f(0.23, 0.74);
	glVertex2f(0.61, 0.74); 
	glVertex2f(0.61, 0.65);
  glPopMatrix();
  glEnd();
  
  circulos(-0.7,0.7,0.12,0, 2* M_PI , gris , true );
  circulos(0.7,0.7,0.12,0, 2* M_PI , gris , true );
  circulos(-0.7,0.7,0.1,0, 2* M_PI , rojo , true );
  circulos(0.7,0.7,0.1,0, 2* M_PI , verde , true );  
  
  rectangulo(0.668,0.60,0.07,0.2,0.9,0.9,0.9);
  rectangulo(-0.735,0.60,0.07,0.2,0.9,0.9,0.9);
  
  rectangulo(-0.81,-0.53,1.63,1,0.9,0.9,1);
  rectangulo(-0.81,-0.53,0.52,1,0.6,0.8,1);
  rectangulo(0.3,-0.53,0.52,1,0.6,0.8,1);
  
  //barras
  rectangulo(-0.81,0.20,0.52,0.12,0.8,0.9,1);
  rectangulo(0.3,0.20,0.52,0.12,0.8,0.9,1);
  rectangulo(-0.29,0.20,0.585,0.12,0.9,0.9,0.9);
  
  rectangulo(-0.81,-0.05,0.52,0.12,0.8,0.9,1);
  rectangulo(0.3,-0.05,0.52,0.12,0.8,0.9,1);
  rectangulo(-0.29,-0.05,0.585,0.12,0.9,0.9,0.9);
  
  rectangulo(-0.81,-0.30,0.52,0.12,0.8,0.9,1);
  rectangulo(0.3,-0.30,0.52,0.12,0.8,0.9,1);
  rectangulo(-0.29,-0.30,0.585,0.12,0.9,0.9,0.9);
  
  rectangulo(-0.81,-0.53,0.52,0.12,0.8,0.9,1);
  rectangulo(0.3,-0.53,0.52,0.12,0.8,0.9,1);
  rectangulo(-0.29,-0.53,0.585,0.12,0.9,0.9,0.9);


  glColor3f(1, 1, 1);
  renderbitmapstring(-0.55, 0.67, GLUT_BITMAP_HELVETICA_18, "E. ROJO");
  glColor3f(1, 1, 1);
  renderbitmapstring(0.28, 0.67, GLUT_BITMAP_HELVETICA_18, "E. VERDE");

  glColor3f(0, 0, 0);
  renderbitmapstring(-0.13, 0.79, GLUT_BITMAP_HELVETICA_12, "MARCADOR");

  int minutos = tiempo / 60;
  int segundos = tiempo % 60;
  char tiempostr[20];
  sprintf(tiempostr, "%02d:%02d", minutos, segundos); // Formato de tiempo
  renderbitmapstring(-0.08, 0.68, GLUT_BITMAP_HELVETICA_18, tiempostr);
  
    // Mostrar 1er tiempo o 2do tiempo
  glColor3f(1, 1, 1);
  const char* tiempoTexto = isfirsthalf ? "1er tiempo" : "2do tiempo";
  renderbitmapstring(-0.15, 0.55, GLUT_BITMAP_HELVETICA_18, tiempoTexto);   
  //goles
  glColor3f(0.2, 0.2, 0.6);
  renderbitmapstring(-0.05, 0.35, GLUT_BITMAP_HELVETICA_18, "Goles");
  glColor3f(0.2, 0.2, 0.6);
  string scoreazulstr = " " + to_string(scoreazul);
  renderbitmapstring(-0.6, 0.35, GLUT_BITMAP_HELVETICA_18,scoreazulstr.c_str());
  string scorerojostr = " " + to_string(scorerojo);
  renderbitmapstring(0.6, 0.35, GLUT_BITMAP_HELVETICA_18, scorerojostr.c_str());
  //saques de banda                     
  glColor3f(0.2, 0.2, 0.6);
  renderbitmapstring(-0.23, 0.23, GLUT_BITMAP_HELVETICA_18, "Saques de Banda");
  string saquesdebandaazulstr = " " + to_string(saquesdebandaazul);
  renderbitmapstring(-0.6, 0.23, GLUT_BITMAP_HELVETICA_18, 
  saquesdebandaazulstr.c_str());
  string saquesdebandaRojostr = " " + to_string(saquesdebandarojo);
  renderbitmapstring(+0.6, 0.23, GLUT_BITMAP_HELVETICA_18, 
  saquesdebandaRojostr.c_str());
  //saques de centro
  glColor3f(0.2, 0.2, 0.6);
  renderbitmapstring(-0.24, 0.11, GLUT_BITMAP_HELVETICA_18, "Saques de Centro");
  string saquesdecentroazulstr = "  " + to_string(scoreazul);
  renderbitmapstring(-0.61, 0.11, GLUT_BITMAP_HELVETICA_18, 
  saquesdecentroazulstr.c_str());
  string saquesdecentrorojostr = "  " + to_string(scorerojo);
  renderbitmapstring(+0.59, 0.11, GLUT_BITMAP_HELVETICA_18, 
  saquesdecentrorojostr.c_str());
  //lanzamientos
  glColor3f(0.2, 0.2, 0.6);
  renderbitmapstring(-0.21, -0.01, GLUT_BITMAP_HELVETICA_18, "Lanzamiento 9m");
  string lanzamientosdemetrosazulstr = "" + to_string(lanzamientosdemetrosazul); 
  renderbitmapstring(-0.6, -0.01, GLUT_BITMAP_HELVETICA_18, 
  lanzamientosdemetrosazulstr.c_str());
  string lanzamientosdemetrosrojostr = "" + to_string(lanzamientosdemetrosrojo);
  renderbitmapstring(+0.6, -0.01, GLUT_BITMAP_HELVETICA_18, 
  lanzamientosdemetrosrojostr.c_str());
  //tiros libres
  glColor3f(0.2, 0.2, 0.6);
  renderbitmapstring(-0.19, -0.12, GLUT_BITMAP_HELVETICA_18, "Tiros Libres");
  string tiroslibresazulstr = " " + to_string(tiroslibresazul);
  renderbitmapstring(-0.6, -0.12, GLUT_BITMAP_HELVETICA_18, 
  tiroslibresazulstr.c_str());
  string tiroslibresrojostr = " " + to_string(tiroslibresrojo);
  renderbitmapstring(+0.6, -0.12, GLUT_BITMAP_HELVETICA_18, 
  tiroslibresrojostr.c_str());
  //faltas
  glColor3f(0.2, 0.2, 0.6);
  renderbitmapstring(-0.11, -0.24, GLUT_BITMAP_HELVETICA_18, "Faltas");
  string faltasazulstr = " " + to_string(faltasazul);
  renderbitmapstring(-0.6, -0.24, GLUT_BITMAP_HELVETICA_18, 
  faltasazulstr.c_str());
  string faltasrojostr = "  " + to_string(faltasrojo);
  renderbitmapstring(+0.59, -0.24, GLUT_BITMAP_HELVETICA_18, 
  faltasrojostr.c_str());
  //sanciones
  glColor3f(0.2, 0.2, 0.6);
  renderbitmapstring(-0.14, -0.36, GLUT_BITMAP_HELVETICA_18, "Sanciones");
  string sancionesazulstr = " " + to_string(sancionesazul);
  renderbitmapstring(-0.6, -0.36, GLUT_BITMAP_HELVETICA_18, 
  sancionesazulstr.c_str());
  string sancionesrojostr = " " + to_string(sancionesrojo);
  renderbitmapstring(+0.6, -0.36, GLUT_BITMAP_HELVETICA_18, 
  sancionesrojostr.c_str());
  //tiros a puerta
  glColor3f(0.2, 0.2, 0.6);
  renderbitmapstring(-0.21, -0.48, GLUT_BITMAP_HELVETICA_18, "Tiros a Puerta");
  string tirosapuertaazulstr = "  " + to_string(tirosapuertaazul);
  renderbitmapstring(-0.62, -0.48, GLUT_BITMAP_HELVETICA_18, 
  tirosapuertaazulstr.c_str());
  string tirosapuertarojostr = " " + to_string(tirosapuertarojo);
  renderbitmapstring(+0.6, -0.48, GLUT_BITMAP_HELVETICA_18, 
  tirosapuertarojostr.c_str());

  glutSwapBuffers();
}

//proceso para manejar el teclado
void teclado(unsigned char tecla, int x, int y){
  if (tecla == 32) //si se presiona la tecla ESC
  exit(1);  
}
//processo para iniciar el contexto de OpenGL
void iniciar() {
 glClearColor(0.3f, 0.5f, 1.0f, 1.0f);
  glLineWidth(10.0f);
  glOrtho(0, 800, 0, 600, -1, 1);

  glMatrixMode(GL_MODELVIEW); 
  glLoadIdentity();
}
//processo para actualizar
void actualizar() {
    if (tiempo < 3600) { // Incrementar tiempo hasta 3600 (60 minutos)
        tiempo++;
        if (tiempo == 1800) {
            isfirsthalf = false; // Cambiar a 2do tiempo en 30 minutos
        }

        // Contador para actualizar estadísticas cada 2 segundos
        static int stat_contador = 0;
        stat_contador++;
        if (stat_contador >= 200) { // Cada 2 segundos
            stat_contador=0;

            // Incrementar estadísticas aleatoriamente
            saquesdebandaazul += rand() % 2;       // Incrementa entre 0 y 1
            saquesdebandarojo += rand() % 2;
            lanzamientosdemetrosazul += rand() % 2; 
            lanzamientosdemetrosrojo += rand() % 2;
            faltasazul += rand() % 2;
            faltasrojo += rand() % 2;
            sancionesazul += rand() % 2;
            sancionesrojo += rand() % 2;
            tiroslibresazul += rand() % 3;// Incrementa entre 0 y 2
            tiroslibresrojo += rand() % 3;
        }

        static int score_contador = 0;
        score_contador++;
        // Incrementar puntajes aleatoriamente cada 60 segundos
        if (score_contador >=60 ) { 
            score_contador = 0;
            // Incrementar puntajes de los equipos aleatoriamente
            scoreazul += rand() % 2; // Incrementa entre 0 y 1
            scorerojo += rand() % 2;


        }
        
       tirosapuertaazul = scoreazul + 2;
       tirosapuertarojo = scorerojo + 1;

        glutPostRedisplay();
    }
}
//proceso para el temporizador
void timer(int value){
    actualizar(); //actualizar la animación
    //la función de temporizador para que se llame 60 veces por segundo
    glutTimerFunc(1000 / 120, timer, 0); 
}
//funcion principal
int main(int argc, char** argv) {
    srand(time(0)); // Inicializar la semilla de números aleatorios

    glutInit(&argc, argv); //inicializar GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); //modo de visualización
    glutInitWindowSize(600, 600); //tamaño de la ventana
    glutInitWindowPosition(100, 100); //posición de la ventana
    glutCreateWindow("TABLERO"); //crear la ventana
    glutDisplayFunc(dibujar); //registrar la función de dibujo
    // glutIdleFunc(actualizar); //funciona pero desde la funcion timer
    glutTimerFunc(100, timer, 0); // con esto el mov es mas fluido
    glutKeyboardFunc(teclado); //registrar la función de teclado
    iniciar(); //iniciar el contexto de OpenGL
    glutMainLoop(); //iniciar el bucle principal de GLUT
    return 0; //salir del programa
}
