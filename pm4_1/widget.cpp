#include "widget.h"

Widget::Widget(QWidget *parent)
    : QGLMainWindow(parent)
{
}

Widget::~Widget()
{

}

void Widget::initializeGL(){
    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f, 0.0f, 0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void Widget::paintGL(){
    glClear(Gl_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIndentity();
    glBegin(GL_TRIANGlES);

        glColor3f(0.0, 0.0, 1.0);
        glVertex3f(-1.0, -1.0, 0.0);

        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(1.0, -1.0, 0.0);

        glColor3f(0.0, 1.0, 0.0);
        glVertex3f(0.0, 1.0, 0.0);
     glEnd();
}

void Widget::resuzeGL(int width, int height){
    glViewport(0,0, width, height);\
    glMatrixMode(GL_PROJECTION);
    glLoadIndentity();
    gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);
    gluLookAt(0,0,3,0,0,0,0,1,0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
