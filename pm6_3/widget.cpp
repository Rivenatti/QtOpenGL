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

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(-2.0, 1.0);
    glVertex2f(-2.0, 2.0);
    glVertex2f(0.5, 2.0);
    glVertex2f(0.5, 1.0);

     glEnd();

     glBegin(GL_LINES);
     glColor3f(1.0f, 0.0f, 0.0f);
     glVertex2f(-10.0f, -2.0f);
     glVertex2f(10.0f, 2.0f);
     glEnd();

     glTranslatef(2,0,0);
     glBegin(GL_QUADS);
     glColor3f(1.0,0.0,0.0);
     glVertex2f(-0.5, 0.8);
     glVertex2f(-0.5, 1.8);
     glVertex2f(0.5, 1.8);
     glVertex2f(0.5, 0.8);
     glEnd();

     glTranslatef(3,0,0);
     glBegin(GL_QUADS);
     glColor3f(1.0,0.0,0.0);
     glVertex2f(-0.5, 2.1);
     glVertex2f(-0.5, 3.1);
     glVertex2f(0.5, 3.1);
     glVertex2f(0.5, 2.1);
     glEnd();
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
