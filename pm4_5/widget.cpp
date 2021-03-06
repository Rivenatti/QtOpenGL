#include "widget.h"

Widget::Widget(QWidget *parent)
    : QGLWidget(parent)
{
}

Widget::~Widget()
{

}

void Widget::initalizeGL(){
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
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
        glVertex3f(-1.0, 2.0,0.0);
        glVertex3f(1.0, 2.0, 0.0);
        glVertex3f(4.0, 0.0, 0.0);
        glVertex3f(4.0, -1.0, 0.0);
        glVertex3f(-3.0,-1.0, 0.0);
        glVertex3f(-3.0, 1.0, 0.0);
     glEnd();
}

void Widget::resizeGL(int width, int height){
    glViewport(0,0,width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);
    gluLookAt(0,0,15,0,0,0,0,1,0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
