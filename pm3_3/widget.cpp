#include "widget.h"

Widget::Widget(QWidget *parent)
    : QGLWidget(parent)
{
}

Widget::~Widget()
{

}

void Widget::initializeGL(){
    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void Widget::paintGL(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(-1.5f,0.0f,-6.0f);         // Porusz 1.5 w lewo i 6.0 wgłąb

    glBegin(GL_TRIANGLES);         // Rysujemy trójkąty
        glVertex3f( 0.0f, 1.0f, 0.0f);         // Góra
        glVertex3f(-1.0f,-1.0f, 0.0f);         // Lewy
        glVertex3f( 1.0f,-1.0f, 0.0f);         // Prawy
        glEnd();         // Koniec rysowania trójkąta


        glTranslatef(3.0f,0.0f,0.0f);         // Porusz 3 w prawo

    glBegin(GL_QUADS);

    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-1.0f, 1.0f, 0.0f);
    glVertex3f( 1.0f, 1.0f, 0.0f);
    glVertex3f( 1.0f,-1.0f, 0.0f);
    glVertex3f(-1.0f,-1.0f, 0.0f);

    glEnd();

}

void Widget::resizeGL(int width, int height){
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);
    gluLookAt(0,0,3,0,0,0,0,1,0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
