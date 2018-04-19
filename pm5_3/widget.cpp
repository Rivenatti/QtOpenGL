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
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f); //biale tlo
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void Widget::paintGL(){
    z = 5.0;
    float x,y;
    float ang;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLineWidth(6.0f);  // grubosc linii
    glLoadIdentity();
    glBegin(GL_LINE_STRIP);
    glColor3f(1.0f,0.0f,1.0f); // ustawia kolor obiektu: czerwony


        for(ang=0.0; ang<30.0; ang+=0.1f){
            x = 2.1f*sin(ang); // gdy czynniki nierowne
            y = 2.1f*cos(ang); // rysowana jest spirala eliptyczna
            glVertex3f(x,y,z);
            z+=0.02f; // mozna zmieniac wartosc
        }

     glEnd();
}

void Widget::resizeGL(int width, int height){
    glViewport(0,0,width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);
    gluLookAt(0,0,16,0,0,0,0,1,0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
