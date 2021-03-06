#include "widget.h"
#include <GL/glu.h>
#include <cmath>

Widget::Widget(QWidget *parent)
    : QGLWidget(parent)
{
}

Widget::~Widget()
{

}

void Widget::initalizeGL(){
    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); //biale tlo
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void Widget::paintGL(){
    gluLookAt(0,0,24,0,0,0,0,0,1);
    glClearColor(1.0,1.0,1.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glPushMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(-2.5,0);
    glVertex2f(-2.5,1.5);
    glVertex2f(-1, 1.5);
    glVertex2f(-0.5,2);
    glVertex2f(0.5, 2);
    glVertex2f(1, 1.5);
    glVertex2f(2.5, 1.5);
    glVertex2f(2.5,1.5);
    glVertex2f(2.5,0);

     glEnd();

     glColor3f(1.0,0.0,0.0);
     glPushMatrix();
     glTranslatef(1,0,0);
     gluDisk(gluNewQuadric(),0,0.5,32,1);
     glPopMatrix();
     glPushMatrix();
     glTranslatef(-1,0,0);
     gluDisk(gluNewQuadric(),0, 0.5, 32,1);
     glPopMatrix();
     glPushMatrix();
     glFlush();


}

void Widget::resizeGL(int width, int height){
    glViewport(0,0,width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);
    gluLookAt(0,0,12,0,0,0,0,1,0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
