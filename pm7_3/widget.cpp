#include "widget.h"
#include <GL/glu.h>
//#include <cmath>

GLfloat fExtent = 20.0f;
GLfloat fStep = 1.0f;

Widget::Widget(QWidget *parent)
    : QGLWidget(parent){
     dx=dy=dz=0;
     y = -0.4f;
}

Widget::~Widget()
{

}

void Widget::keyPressEvent(QKeyEvent *event){
    if(event->key()==Qt::Key_Left) dx --;
    if(event->key()==Qt::Key_Right) dx ++;
    if(event->key()==Qt::Key_Down) dz++;
    if(event->key()==Qt::Key_Up) dz--;
    if(event->key()==Qt::Key_P){
        dz--;
        dx++;
    }
    if(event->key()==Qt::Key_Z){
        dz++;
        dx--;
    }

    update();
}

void Widget::initalizeGL(){
    glShadeModel(GL_SMOOTH);
    glClearColor(1.0f, 0.2f, 1.0f, 0.0f); // kolor nieba
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void Widget::paintGL(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glColor3f(0.3f, 1.0f, 0.0f); // kolor wody
    glBegin(GL_QUADS);
        glVertex3f(-100.0, 0.0, -1.0);
        glVertex3f(100.0, 0.0, -1.0);
        glVertex3f(100.0, -100.0, -1.0);
        glVertex3f(-100.0, -100.0, -1.0);
    glEnd();


    glLoadIdentity();
    glColor3f(0.0f, 0.0f, 0.0f); // kolor linii
    glBegin(GL_LINES);
    for(iLine = -fExtent; iLine <= fExtent; iLine+=fStep){
        glVertex3f(iLine, y, fExtent);
        glVertex3f(iLine, y, -fExtent);
        glVertex3f(fExtent, y, iLine);
        glVertex3f(-fExtent, y, iLine);
    }
    glEnd();


    glLoadIdentity();
    glColor3f(1.0, 0.0, 0.0);
    glTranslatef(dx, dy, dz);
    glBegin(GL_TRIANGLE_STRIP);
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
    gluLookAt(0,10,45,0,0,0,0,1,0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
