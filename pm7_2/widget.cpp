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
    if(event->key()==Qt::Key_A) dx = dx-5;
    if(event->key()==Qt::Key_D) dx = dx+5;
    if(event->key()==Qt::Key_Down) dy--;
    if(event->key()==Qt::Key_Up) dy++;
    update();
}

void Widget::initalizeGL(){
    glShadeModel(GL_SMOOTH);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void Widget::paintGL(){
    gluLookAt(0,0,24,0,0,0,0,0,1);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glColor3f(1.0, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(dx, dy, 0);
    gluDisk(gluNewQuadric(), 0, 3.5, 32, 1);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(dx, dy, 0);
    gluDisk(gluNewQuadric(), 0, 3.5, 32, 1);
    glPopMatrix();

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
