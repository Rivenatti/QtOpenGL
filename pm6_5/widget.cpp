#include "widget.h"
#include <GL/glu.h>
#include <cmath>

Widget::Widget(QWidget *parent)
    : QGLWidget(parent)
{
    dx=dy=dz=0;
    vx=0.02;
    vy=0.1;
    vz=-0.05;
    connect(&timer,SIGNAL(timeout()), SLOT(tick()));
    timer.start(60);
}

void Widget::tick(){
    dx+=2*vx;
    dy+=0.5*vy;
    dz+=vz;
    update();
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
    glVertex3f(-3.0+dx, 3.0+dy, 0.0+dz);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0.0+dx, 4.5+dy, 0.0+dz);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(3.0+dx, 3.0+dy, 0.0+dz);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(3.0+dx, -3.0+dy, 0.0+dz);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-3.0+dx, -3.0+dy, 0.0+dz);

    glEnd();

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
