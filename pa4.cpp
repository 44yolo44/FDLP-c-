#include <GL/glut.h>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

float movnube = -0.8;
float movimientoy[14] = {0.0f};
bool direcciony[14] = {true};
float movimientox[14] = {0.0f};
bool direccionx[14] = {true};
float bolay = 0.0f;
bool direccionbola = true;
float f = 0;
float b = 0;
float c = 0;

const float azul[3] = {0, 0.12, 0.45};
const float blanco[3] = {1, 1, 1};
const float negro[3] = {0, 0, 0};
const float celeste[3] = {0.7, 0.7, 1};
const float rojo[3] = {1, 0, 0};
const float verde[3] = {0, 1, 0};
const float gris[3] = {0.9, 0.9, 0.9};
const float verdeos[3] = {0.01, 0.34, 0};
const float verdecl[3] = {0.02, 0.65, 0};

int scoreazul = 0;
int scorerojo = 0;
int tiempo = 0;
bool isfirsthalf = true;

int saquesdebandaazul, saquesdebandarojo;
int saquesdecentroazul, saquesdecentrorojo;
int lanzamientosdemetrosazul, lanzamientosdemetrosrojo;
int tiroslibresazul, tiroslibresrojo;
int faltasazul, faltasrojo;
int sancionesazul, sancionesrojo;
int tirosapuertaazul, tirosapuertarojo;

void initstatistics() {
    saquesdebandaazul = 0;
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
    sancionesrojo = 0;
    tirosapuertaazul = 0;
    tirosapuertarojo = 0;
}

void movimientop(float f = 0) {
    if (f == 0) {
        glTranslated(0.06, 0.0, 0);
        glRotated(22.5, 0, 0, 1);
    }
}

void movimientob(float b = 0) {
    if (b == 2) {
        glTranslated(0.2, 0.02, 0);
        glRotated(45, 0, 0, 1);
    }
    if (b == 1) {
        glTranslated(-0.14, 0.12, 0);
        glRotated(-45, 0, 0, 1);
    }
}

void renderbitmapstring(float x, float y, void *font, const char *string) {
    glRasterPos2f(x, y);
    while (*string)
        glutBitmapCharacter(font, *string++);
}

void rectangulo(float x, float y, float ancho, float largo, float r, float g, float b) {
    glPushMatrix();
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + ancho, y);
    glVertex2f(x + ancho, y + largo);
    glVertex2f(x, y + largo);
    glPopMatrix();
    glEnd();
}

void circulos(float cx, float cy, float radio, float ainicial, float afinal, const float color[3], bool completo = false) {
    int n_segmentos = 100;
    float rotacionang = (afinal - ainicial) / n_segmentos;

    if (completo) {
        glColor3fv(color);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(cx, cy);
    } else {
        glBegin(GL_LINE_STRIP);
    }
    for (int i = 0; i <= n_segmentos; ++i) {
        float angulo = ainicial + i * rotacionang;
        float x = cx + radio * cos(angulo);
        float y = cy + radio * sin(angulo);
        glVertex2f(x, y);
    }
    glEnd();
}

void piernas(float x) {
    if (x == 1) {
        rectangulo(0.02, 0.04, 0.02, 0.04, 1, 0.6, 0.5);
        rectangulo(0.02, 0.08, 0.02, 0.04, 0.7, 0.7, 0.7);
        rectangulo(0, 0.02, 0.04, 0.02, 0, 0, 0);
    } else {
        rectangulo(0.1, 0.04, 0.02, 0.04, 1, 0.6, 0.5);
        rectangulo(0.1, 0.08, 0.02, 0.04, 0.5, 0.5, 0.5);
        rectangulo(0.1, 0.02, 0.04, 0.02, 0, 0, 0);
    }
}

void brazos(float x) {
    if (x == 1) {
        rectangulo(0, 0.1, 0.02, 0.12, 1, 0.6, 0.5);
        rectangulo(0, 0.22, 0.02, 0.04, 1, 0, 0);
    } else {
        rectangulo(0.12, 0.1, 0.02, 0.12, 0.8, 0.5, 0.5);
        rectangulo(0.12, 0.22, 0.02, 0.04, 0.8, 0, 0);
    }
}

void nube(float x, float y) {
    glPushMatrix();
    glTranslated(x, y, 0);
    glScalef(0.3, 0.4, 1);

    circulos(-0., -0.5, 0.4, 0, 2 * M_PI, celeste, true);
    circulos(-0.4, -0.3, 0.4, 0, 2 * M_PI, celeste, true);
    circulos(-0.1, -0.6, 0.4, 0, 2 * M_PI, celeste, true);
    circulos(0.3, -0.3, 0.4, 0, 2 * M_PI, celeste, true);
    circulos(0.6, -0.5, 0.4, 0, 2 * M_PI, celeste, true);

    glPopMatrix();
}

void personaje1(float x, float y, float r, float g, float f, float b = 0) {
    glPushMatrix();
    glTranslated(x, y, 0);
    glPushMatrix();
    glScalef(0.25, 0.25, 1.0);
    rectangulo(0, 0, 0.14, 0.02, 0, 0.05, 0.25);
    rectangulo(0.02, -0.02, 0.1, 0.02, 0, 0.06, 0.4);
    rectangulo(0.04, 0.02, 0.06, 0.02, 0, 0.06, 0.4);
    glPushMatrix();
    movimientop(f);
    piernas(1);
    glPopMatrix();
    glPushMatrix();
    movimientop(f);
    piernas(2);
    glPopMatrix();
    rectangulo(0.02, 0.1, 0.08, 0.02, 0.7, 0.7, 0.7);
    rectangulo(0.1, 0.1, 0.02, 0.02, 0.5, 0.5, 0.5);
    rectangulo(0.02, 0.12, 0.08, 0.14, 1 * r, 1 * g, 0);
    rectangulo(0.1, 0.12, 0.02, 0.14, 0.8 * r, 0.8 * g, 0);
    glPushMatrix();
    movimientob(b);
    brazos(1);
    glPopMatrix();
    glPushMatrix();
    movimientob(b);
    brazos(2);
    glPopMatrix();
    glPushMatrix();
    glTranslated(0.04, 0.26, 0);
    rectangulo(0, 0, 0.06, 0.02, 1, 0.6, 0.5);
    rectangulo(-0.04, 0.02, 0.14, 0.16, 1, 0.6, 0.5);
    rectangulo(0.1, 0.06, 0.04, 0.1, 1, 0.6, 0.5);
    rectangulo(-0.08, 0.06, 0.04, 0.06, 1, 0.6, 0.5);
    rectangulo(-0.06, 0.12, 0.02, 0.04, 1, 0.6, 0.5);
    rectangulo(-0.1, 0.08, 0.02, 0.04, 1, 0.6, 0.5);
    rectangulo(-0.12, 0.1, 0.02, 0.04, 1, 0.6, 0.5);
    rectangulo(0.14, 0.08, 0.02, 0.04, 1, 0.6, 0.5);
    rectangulo(0.16, 0.1, 0.02, 0.04, 1, 0.6, 0.5);
    rectangulo(-0.06, 0.04, 0.02, 0.02, 1, 0.6, 0.5);
    rectangulo(-0.08, 0.12, 0.02, 0.02, 1, 0.6, 0.5);
    rectangulo(0.1, 0.04, 0.02, 0.02, 1, 0.6, 0.5);
    rectangulo(0.1, 0.16, 0.02, 0.02, 1, 0.6, 0.5);
    rectangulo(-0.04, 0.18, 0.14, 0.12, 0.45, 0.2, 0.07);
    rectangulo(-0.1, 0.18, 0.06, 0.08, 0.45, 0.2, 0.07);
    rectangulo(-0.1, 0.12, 0.02, 0.06, 0.45, 0.2, 0.07);
    rectangulo(-0.12, 0.16, 0.02, 0.06, 0.45, 0.2, 0.07);
    rectangulo(0.14, 0.16, 0.02, 0.06, 0.45, 0.2, 0.07);
    rectangulo(0.1, 0.24, 0.06, 0.04, 0.45, 0.2, 0.07);
    rectangulo(0.1, 0.22, 0.08, 0.02, 0.45, 0.2, 0.07);
    rectangulo(0.1, 0.1, 0.08, 0., 0.23, 0.09, 0);
    rectangulo(0.12, 0.18, 0.02, 0.04, 0.45, 0.2, 0.07);
    rectangulo(0.1, 0.28, 0.02, 0.04, 0.45, 0.2, 0.07);
    rectangulo(0.12, 0.28, 0.02, 0.02, 0.45, 0.2, 0.07);
    rectangulo(-0.08, 0.18, 0.02, 0.02, 0.45, 0.2, 0.07);
    rectangulo(-0.08, 0.14, 0.02, 0.04, 0.23, 0.09, 0);
    rectangulo(-0.06, 0.16, 0.02, 0.02, 0.23, 0.09, 0);
    rectangulo(0.16, 0.14, 0.02, 0.08, 0.23, 0.09, 0);
    rectangulo(0.14, 0.1, 0.02, 0.06, 0.23, 0.09, 0);
    rectangulo(0.12, 0.16, 0.02, 0.02, 0.23, 0.09, 0);
    rectangulo(0.1, 0.18, 0.02, 0.04, 0.23, 0.09, 0);
    rectangulo(-0.04, 0.12, 0.02, 0.02, 0, 0, 0);
    rectangulo(0.08, 0.12, 0.02, 0.02, 0, 0, 0);
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
}

void marcador(float x, float y) {
    glPushMatrix();
    glPushMatrix();
    glTranslated(x, y, 0);
    glScalef(0.51, 0.57, 0.5);

    rectangulo(-0.61, 0.63, 1.23, 0.13, 0.9, 0.9, 0.9);

    glPushMatrix();
    glColor3f(0.9, 0.9, 0.9);
    glBegin(GL_POLYGON);
    glVertex2f(-0.3, 0.76);
    glVertex2f(-0.2, 0.86);
    glVertex2f(0.2, 0.86);
    glVertex2f(+0.3, 0.76);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.95, 0.95, 0.95);
    glBegin(GL_POLYGON);
    glVertex2f(-0.27, 0.77);
    glVertex2f(-0.18, 0.84);
    glVertex2f(0.18, 0.84);
    glVertex2f(+0.27, 0.77);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.3, 0.3, 0.3);
    glBegin(GL_POLYGON);
    glVertex2f(-0.61, 0.65);
    glVertex2f(-0.61, 0.74);
    glVertex2f(-0.23, 0.74);
    glVertex2f(-0.10, 0.65);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.3, 0.3, 0.3);
    glBegin(GL_POLYGON);
    glVertex2f(0.10, 0.65);
    glVertex2f(0.23, 0.74);
    glVertex2f(0.61, 0.74);
    glVertex2f(0.61, 0.65);
    glEnd();
    glPopMatrix();

    circulos(-0.7, 0.7, 0.12, 0, 2 * M_PI, gris, true);
    circulos(0.7, 0.7, 0.12, 0, 2 * M_PI, gris, true);
    circulos(-0.7, 0.7, 0.1, 0, 2 * M_PI, rojo, true);
    circulos(0.7, 0.7, 0.1, 0, 2 * M_PI, verde, true);

    rectangulo(0.668, 0.60, 0.07, 0.2, 0.9, 0.9, 0.9);
    rectangulo(-0.735, 0.60, 0.07, 0.2, 0.9, 0.9, 0.9);

    rectangulo(-0.81, -0.53, 1.63, 1, 0.9, 0.9, 1);
    rectangulo(-0.81, -0.53, 0.52, 1, 0.6, 0.8, 1);
    rectangulo(0.3, -0.53, 0.52, 1, 0.6, 0.8, 1);

    rectangulo(-0.81, 0.20, 0.52, 0.12, 0.8, 0.9, 1);
    rectangulo(0.3, 0.20, 0.52, 0.12, 0.8, 0.9, 1);
    rectangulo(-0.29, 0.20, 0.585, 0.12, 0.9, 0.9, 0.9);

    rectangulo(-0.81, -0.05, 0.52, 0.12, 0.8, 0.9, 1);
    rectangulo(0.3, -0.05, 0.52, 0.12, 0.8, 0.9, 1);
    rectangulo(-0.29, -0.05, 0.585, 0.12, 0.9, 0.9, 0.9);

    rectangulo(-0.81, -0.30, 0.52, 0.12, 0.8, 0.9, 1);
    rectangulo(0.3, -0.30, 0.52, 0.12, 0.8, 0.9, 1);
    rectangulo(-0.29, -0.30, 0.585, 0.12, 0.9, 0.9, 0.9);

    rectangulo(-0.81, -0.53, 0.52, 0.12, 0.8, 0.9, 1);
    rectangulo(0.3, -0.53, 0.52, 0.12, 0.8, 0.9, 1);
    rectangulo(-0.29, -0.53, 0.585, 0.12, 0.9, 0.9, 0.9);

    glColor3f(1, 1, 1);
    renderbitmapstring(-0.55, 0.67, GLUT_BITMAP_HELVETICA_18, "E. ROJO");
    glColor3f(1, 1, 1);
    renderbitmapstring(0.26, 0.67, GLUT_BITMAP_HELVETICA_18, "E. VERDE");
    glColor3f(0, 0, 0);
    renderbitmapstring(-0.13, 0.79, GLUT_BITMAP_HELVETICA_12, "MARCADOR");
    int minutos = tiempo / 60;
    int segundos = tiempo % 60;
    char tiempostr[20];
    sprintf(tiempostr, "%02d:%02d", minutos, segundos);
    renderbitmapstring(-0.08, 0.68, GLUT_BITMAP_HELVETICA_18, tiempostr);
    glColor3f(1, 1, 1);
    if(tiempo<1800){
    glColor3f(1, 1, 1);
    renderbitmapstring(-0.15, 0.55, GLUT_BITMAP_HELVETICA_18, "1er tiempo");
		}
		else{
		glColor3f(1, 1, 1);
    renderbitmapstring(-0.15, 0.55, GLUT_BITMAP_HELVETICA_18, "2do tiempo");	
			
		}
    
 	  /*glColor3f(1, 1, 1);
	  const char* tiempoTexto = isfirsthalf ? "1er tiempo" : "2do tiempo";
	  renderbitmapstring(-0.15, 0.55, GLUT_BITMAP_HELVETICA_18, tiempoTexto);*/
    glColor3f(0.2, 0.2, 0.6);
    renderbitmapstring(-0.08, 0.35, GLUT_BITMAP_HELVETICA_18, "Goles");
    glColor3f(0.2, 0.2, 0.6);
    string scoreazulstr = " " + to_string(scoreazul);
    renderbitmapstring(-0.6, 0.35, GLUT_BITMAP_HELVETICA_18, 
		scoreazulstr.c_str());
    string scorerojostr = " " + to_string(scorerojo);
    renderbitmapstring(0.6, 0.35, GLUT_BITMAP_HELVETICA_18, 
		scorerojostr.c_str());
    glColor3f(0.2, 0.2, 0.6);
    renderbitmapstring(-0.23, 0.23, GLUT_BITMAP_HELVETICA_18, "Saques/Banda");
    string saquesdebandaazulstr = " " + to_string(saquesdebandaazul);
    renderbitmapstring(-0.6, 0.23, GLUT_BITMAP_HELVETICA_18, 
		saquesdebandaazulstr.c_str());
    string saquesdebandaRojostr = " " + to_string(saquesdebandarojo);
    renderbitmapstring(+0.6, 0.23, GLUT_BITMAP_HELVETICA_18, 
		saquesdebandaRojostr.c_str());
    glColor3f(0.2, 0.2, 0.6);
    renderbitmapstring(-0.24, 0.11, GLUT_BITMAP_HELVETICA_18, 
		"Saques/Centro");
    string saquesdecentroazulstr = "  " + to_string(scoreazul);
    renderbitmapstring(-0.62, 0.11, GLUT_BITMAP_HELVETICA_18, 
		saquesdecentroazulstr.c_str());
    string saquesdecentrorojostr = "  " + to_string(scorerojo);
    renderbitmapstring(+0.58, 0.11, GLUT_BITMAP_HELVETICA_18, 
		saquesdecentrorojostr.c_str());
    glColor3f(0.2, 0.2, 0.6);
    renderbitmapstring(-0.24, -0.01, GLUT_BITMAP_HELVETICA_18, 
		"Lanzamiento 9m");
    string lanzamientosdemetrosazulstr = "" +
		 to_string(lanzamientosdemetrosazul);
    renderbitmapstring(-0.58, -0.01, GLUT_BITMAP_HELVETICA_18, 
		lanzamientosdemetrosazulstr.c_str());
    string lanzamientosdemetrosrojostr = "" 
		+ to_string(lanzamientosdemetrosrojo);
    renderbitmapstring(+0.62, -0.01, GLUT_BITMAP_HELVETICA_18, 
		lanzamientosdemetrosrojostr.c_str());
    glColor3f(0.2, 0.2, 0.6);
    renderbitmapstring(-0.19, -0.12, GLUT_BITMAP_HELVETICA_18, "Tiros Libres");
    string tiroslibresazulstr = " " + to_string(tiroslibresazul);
    renderbitmapstring(-0.6, -0.12, GLUT_BITMAP_HELVETICA_18, 
		tiroslibresazulstr.c_str());
    string tiroslibresrojostr = " " + to_string(tiroslibresrojo);
    renderbitmapstring(+0.6, -0.12, GLUT_BITMAP_HELVETICA_18, 
		tiroslibresrojostr.c_str());
    glColor3f(0.2, 0.2, 0.6);
    renderbitmapstring(-0.06, -0.24, GLUT_BITMAP_HELVETICA_18, "Faltas");
    string faltasazulstr = " " + to_string(faltasazul);
    renderbitmapstring(-0.6, -0.24, GLUT_BITMAP_HELVETICA_18, 
		faltasazulstr.c_str());
    string faltasrojostr = "  " + to_string(faltasrojo);
    renderbitmapstring(+0.58, -0.24, GLUT_BITMAP_HELVETICA_18, 
		faltasrojostr.c_str());
    glColor3f(0.2, 0.2, 0.6);
    renderbitmapstring(-0.14, -0.36, GLUT_BITMAP_HELVETICA_18, "Sanciones");
    string sancionesazulstr = " " + to_string(sancionesazul);
    renderbitmapstring(-0.6, -0.36, GLUT_BITMAP_HELVETICA_18, 
		sancionesazulstr.c_str());
    string sancionesrojostr = " " + to_string(sancionesrojo);
    renderbitmapstring(+0.6, -0.36, GLUT_BITMAP_HELVETICA_18, 
		sancionesrojostr.c_str());
    glColor3f(0.2, 0.2, 0.6);
    renderbitmapstring(-0.21, -0.48, GLUT_BITMAP_HELVETICA_18, 
		"Tiros a Puerta");
    string tirosapuertaazulstr = "  " + to_string(tirosapuertaazul);
    renderbitmapstring(-0.62, -0.48, GLUT_BITMAP_HELVETICA_18, 
		tirosapuertaazulstr.c_str());
    string tirosapuertarojostr = " " + to_string(tirosapuertarojo);
    renderbitmapstring(+0.6, -0.48, GLUT_BITMAP_HELVETICA_18, 
		tirosapuertarojostr.c_str());
    glPopMatrix();
    glPopMatrix();
}

void arbusto(float x, float y) {
    glPushMatrix();
    glTranslated(x, y, 0);
    glRotated(-90, 0, 0, 1);
    glScalef(0.5, 0.4, 1);

    circulos(-0, -0.5, 0.4, 0, 2 * M_PI, verdecl, true);
    circulos(-0.4, -0.3, 0.4, 0, 2 * M_PI, verdecl, true);
    circulos(-0.1, -0.6, 0.4, 0, 2 * M_PI, verdecl, true);
    circulos(0.3, -0.3, 0.4, 0, 2 * M_PI, verdecl, true);
    circulos(0.6, -0.5, 0.4, 0, 2 * M_PI, verdecl, true);

    circulos(-0.1, -0.5, 0.4, 0, 2 * M_PI, verdeos, true);
    circulos(-0.5, -0.3, 0.4, 0, 2 * M_PI, verdeos, true);
    circulos(-0.2, -0.6, 0.4, 0, 2 * M_PI, verdeos, true);
    circulos(0.2, -0.3, 0.4, 0, 2 * M_PI, verdeos, true);
    circulos(0.5, -0.5, 0.4, 0, 2 * M_PI, verdeos, true);
}

void campo(float x, float y, float z) {
    glPushMatrix();
    glTranslated(x, y, z);
    glScalef(0.8, 0.8, 1);

    glBegin(GL_LINE_LOOP);
    glLineWidth(10);
    glColor3f(0.5, 0.5, 0.5);
    glVertex2d(-0.53, 0.75);
    glVertex2d(0.53, 0.75);
    glVertex2d(0.53, 1.75);
    glVertex2d(-0.53, 1.75);
    glEnd();
    rectangulo(-1.5, -0.9, 3, 1.6, 1, 0.5, 0);
    rectangulo(-0.3, 0.5, 0.05, 0.25, 0.5, 0.5, 0.5);
    rectangulo(0.2, 0.5, 0.05, 0.25, 0.5, 0.5, 0.5);
    rectangulo(-1.3, -0.9, 0.5, 1.6, 0, 1, 0);
    rectangulo(0.8, -0.9, 0.5, 1.6, 0, 1, 0);

    glPushMatrix();
    arbusto(-0.85, 0);
    glPopMatrix();
    arbusto(1.2, 0);

    glPopMatrix();

    glPushMatrix();
    glTranslated(0, 0, 0);
    glBegin(GL_POINTS);
    glColor3f(1, 1, 1);
    glVertex2d(-0.7, 0.6);
    glVertex2d(0.7, 0.6);
    glVertex2d(0.7, -0.6);
    glVertex2d(-0.7, -0.6);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glLineWidth(10);
    glColor3f(1, 1, 1);
    glVertex2d(-0.7, 0.6);
    glVertex2d(0.7, 0.6);
    glVertex2d(0.7, -0.6);
    glVertex2d(-0.7, -0.6);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0, 0.55, 0.8);
    glVertex2d(-0.7, 0.6);
    glVertex2d(0.7, 0.6);
    glVertex2d(0.7, -0.6);
    glVertex2d(-0.7, -0.6);
    glEnd();

    glPushMatrix();
    glLineWidth(10);
    glTranslated(-0.7, -0.35, 0);
    glRotated(270, 0, 0, 1);
    glColor3f(1, 1, 1);
    circulos(-0.35, 0., 0.3, 0, M_PI, blanco, false);
    circulos(-0.35, 0, 0.3, 0, M_PI, azul, true);
    glPopMatrix();

    glPushMatrix();
    glLineWidth(10);
    glTranslated(0.7, 0.35, 0);
    glRotated(90, 0, 0, 1);
    glColor3f(1, 1, 1);
    circulos(-0.35, 0, 0.3, 0, M_PI, blanco, false);
    circulos(-0.35, 0, 0.3, 0, M_PI, azul, true);
    glPopMatrix();

    glBegin(GL_QUADS);
    glColor3f(0, 0.55, 0.8);
    glVertex2d(-0.5, 0.5);
    glVertex2d(0.5, 0.5);
    glVertex2d(0.5, -0.5);
    glVertex2d(-0.5, -0.5);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3f(1, 1, 1);
    glVertex2d(-0.5, 0.23);
    glVertex2d(-0.5, -0.23);
    glVertex2d(0.5, 0.23);
    glVertex2d(0.5, -0.23);
    glEnd();

    glPushMatrix();
    glLineWidth(10);
    glTranslated(-0.7, -0.7, 0);
    glRotated(270, 0, 0, 1);
    circulos(-0.7, 0, 0.6, 0, M_PI, blanco, false);
    glPopMatrix();

    glPushMatrix();
    glLineWidth(10);
    glTranslated(0.7, 0.7, 0);
    glRotated(90, 0, 0, 1);
    circulos(-0.7, 0, 0.6, 0, M_PI, blanco, false);
    glPopMatrix();

    glBegin(GL_QUADS);
    glColor3f(0, 0.55, 0.8);
    glVertex2d(-0.35, 0.5);
    glVertex2d(0.35, 0.5);
    glVertex2d(0.35, -0.5);
    glVertex2d(-0.35, -0.5);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3f(1, 1, 1);
    glVertex2d(-0.35, 0.5);
    glVertex2d(-0.35, -0.5);
    glVertex2d(0.35, 0.5);
    glVertex2d(0.35, -0.5);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3f(1, 1, 1);
    glVertex2d(0, 0.6);
    glVertex2d(0., -0.6);
    glEnd();

    glPushMatrix();
    glLineWidth(10);
    circulos(0, 0, 0.1, 0, 2 * M_PI, blanco, false);
    circulos(0, 0, 0.1, 0, 2 * M_PI, azul, true);
    glPopMatrix();
    glPopMatrix();
}

void balon(float x, float y, float radio) {
    glPushMatrix();
    glScalef(0.4f, 0.4f, 1.0f);
    circulos(x, y, radio, 0, 2 * M_PI, blanco, true);
    glPopMatrix();
}

void dibujar() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    nube(movnube, 0.7);
    nube(-1 + movnube, 0.7);
    nube(0.8 + movnube, 0.6);
    nube(-2 + movnube, 0.6);
    marcador(0, 0.5);
    campo(0, -0.4, 0);

    personaje1(1.55, 0 + (movimientoy[0] / 5), 0, 1, 1, 1);

    personaje1(0.52, -0.5 + (movimientoy[0] / 2), 0, 1, 1, 1);
    personaje1(0.28 + (movimientox[1] / 2), 0 + (movimientoy[1] / 5), 0, 1, f, b);
    personaje1(0.28 + (movimientox[2] / 2), -0.8 + (movimientoy[2] / 5), 0, 1, f, b);
    personaje1(0.08 + movimientox[3], -0.2 + movimientoy[3], 0, 1, f, b);
    personaje1(0.08 + movimientox[4], -0.4 + movimientoy[4], 0, 1, f, b);
    personaje1(0.08 + movimientox[5], -0.5 + movimientoy[5], 0, 1, f, b);
    personaje1(-0.2 + movimientox[6], -0.5 + movimientoy[5], 0, 1, f, b);

    personaje1(-0.56, -0.5 + (movimientoy[7] / 2), 1, 0, 1, 2);
    personaje1(-0.38 + (movimientox[8] / 2), 0.0 + (movimientoy[0] / 5), 1, 0, f, c);
    personaje1(-0.38 + (movimientox[9] / 2), -0.8 + (movimientoy[0] / 5), 1, 0, f, c);
    personaje1(-0.06 + movimientox[10], -0.2 + movimientoy[10], 1, 0, f, c);
    personaje1(-0.06 + movimientox[11], -0.4 + movimientoy[12], 1, 0, f, c);
    personaje1(-0.06 + movimientox[12], -0.5 + movimientoy[11], 1, 0, f, c);
    personaje1(-0.2 + movimientox[13], -0.5 + movimientoy[12], 1, 0, f, c);
    
    circulos(0.05 + (movimientox[13] * 2.2), -0.5 + (movimientoy[12] * 1.5), 0.04, 0, 2 * M_PI, blanco, true);

    glutSwapBuffers();
}

void teclado(unsigned char tecla, int x, int y) {
    if (tecla == 32)
        exit(1);
}

void iniciar() {
    glClearColor(0.3f, 0.5f, 1.0f, 1.0f);
    glPointSize(10);
    glLineWidth(10);
    glOrtho(-1, 1, -1, 1, -1, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void actualizar() {
	
	    if (movnube < 1.2) {
        movnube += 0.01;
    } else {
        movnube = -0.8;
    }
	
	  if(tiempo < 3600 ){

    if (tiempo < 3600) {
        tiempo+=7;
        if (tiempo == 1800) {
            isfirsthalf = false;
        }
    }

    static int stat_contador = 0;
    stat_contador++;
    if (stat_contador >= 10) {
        stat_contador = 0;

        saquesdebandaazul += rand() % 2;
        saquesdebandarojo += rand() % 2;
        lanzamientosdemetrosazul += rand() % 2;
        lanzamientosdemetrosrojo += rand() % 2;
        faltasazul += rand() % 2;
        faltasrojo += rand() % 2;
        sancionesazul += rand() % 2;
        sancionesrojo += rand() % 2;
        tiroslibresazul += rand() % 3;
        tiroslibresrojo += rand() % 3;
    }

    static int score_contador = 0;
    score_contador++;
    if (score_contador >= 15) {
        score_contador = 0;
        scoreazul += rand() % 2;
        scorerojo += rand() % 2;
    }

    tirosapuertaazul = scoreazul + 2;
    tirosapuertarojo = scorerojo + 1;
 
    if (c >= 2) {
        c = 0;
    } else {
        c += 2;
    }
    if (b >= 1) {
        b = 0;
    } else {
        b += 1;
    }

    if (f >= 1) {
        f = 0;
    } else {
        f += 1;
    }

    for (int i = 0; i < 14; ++i) {
        float deltay = (rand() % 100) / 1000.0f;
        if (direcciony[i]) {
            movimientoy[i] += deltay;
            if (movimientoy[i] >= 0.1f) {
                direcciony[i] = false;
            }
        } else {
            movimientoy[i] -= deltay;
            if (movimientoy[i] <= -0.1f) {
                direcciony[i] = true;
            }
        }
    }

    for (int i = 0; i < 14; ++i) {
        float deltax = (rand() % 100) / 1000.0f;
        if (direccionx[i]) {
            movimientox[i] += deltax;
            if (movimientox[i] >= 0.2f) {
                direccionx[i] = false;
            }
        } else {
            movimientox[i] -= deltax;
            if (movimientox[i] <= -0.2f) {
                direccionx[i] = true;
            }
        }
    }
  }
  else{
  for (int i = 0; i < 14; ++i) {
  movimientox[i]+=0.1;
  movimientoy[i]+=0.1;
  }
  }
    glutPostRedisplay();
}

void timer(int value) {
    actualizar();
    glutTimerFunc(1000 / 12, timer, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1000, 720);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Campo de balonmano");
    glutDisplayFunc(dibujar);
    glutTimerFunc(100, timer, 0);
    glutKeyboardFunc(teclado);
    iniciar();
    glutMainLoop();
    return 0;
}