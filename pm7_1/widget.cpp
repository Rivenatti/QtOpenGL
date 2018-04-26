#include "widget.h"
#include <GL/glu.h>
#include <cmath>

Widget::Widget(QWidget *parent)
    : QGLWidget(parent){
     dx=dy=dz=0;
}

Widget::~Widget()
{

}

void Widget::keyPressEvent(QKeyEvent *event){
    if(event->key()==Qt::Key_Q) dx--;
    if(event->key()==Qt::Key_E) dx++;
    update();
}

void Widget::initalizeGL(){
    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f, 0.2f, 1.0f, 0.0f); //kolor tla
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void Widget::paintGL(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glColor3f(0.3f, 1.0f, 0.0f); // kolor wody
    glBegin(GL_QUADS); // rysuje wode
        glVertex3f(-100.0, 0.0, -1.0);
        glVertex3f(100.0, 0.0, -1.0);
        glVertex3f(100.0, -100.0, -1.0);
        glVertex3f(-100.0, -100.0, -1.0);
    glEnd();

    glLoadIdentity();
    glColor3f(1.0, 0.0, 0.0); // kolor okretu
    glTranslatef(dx,dy,dz); // aktywowane klawiszami
    glBegin(GL_TRIANGLE_STRIP); // rysuje okret
        glVertex3f(-1.0, 5.0, 0.0);
        glVertex3f(1.0, 5.0, 0.0);
        glVertex3f(-1.0, 3.0, 0.0);
        glVertex3f(1.0, 3.0, 0.0);
        glVertex3f(5.0, 3.0, 0.0);
        glVertex3f(4.0, -1.0, 0.0);
        glVertex3f(1.0, 3.0, 0.0);
        glVertex3f(-1.0, -1.0, 0.0);
        glVertex3f(-5.0, 3.0, 0.0);
        glVertex3f(-4.0, -1.0, 0.0);
     glEnd();

}

void Widget::resizeGL(int width, int height){
    glViewport(0,0,width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);
    gluLookAt(0,0,45,0,0,0,0,1,0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
