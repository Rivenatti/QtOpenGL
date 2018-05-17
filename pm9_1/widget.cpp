#include "widget.h"
#include <GL/glu.h>

Widget::Widget(QWidget *parent)
    : QGLWidget(parent){
     rx=ry=rz=0;
     ax=ay=az=0;
     w=s=a=d=q=e=false;

     connect(&timer, SIGNAL(timeout()), SLOT(tick()));
     //timer.start(33); // 30FPS
     timer.start(100);  // dobrac czas
}

Widget::~Widget()
{

}

void Widget::tick(){
    float rstep=0.1;
    float rmax=15;

    if(s) rx=valueChange(rx,-1,rstep,rmax);
    if(w) rx=valueChange(rx,1,rstep,rmax);
    if(a) rx=valueChange(ry,-1,rstep,rmax);
    if(d) rx=valueChange(ry,1,rstep,rmax);
    if(e) rx=valueChange(rz,-1,rstep,rmax);
    if(q) rx=valueChange(rz,1,rstep,rmax);

    ax+=rx;
    ay+=ry;
    az+=rz;

    if(ax>=360) ax=0; if(ax<=-360) ax=0;
    if(ay>=360) ay=0; if(ay<=-360) ay=0;
    if(az>=360) az=0; if(az<=-360) az=0;

    update();
}

float Widget::valueChange(float value, int direction, float step, float max){
    if(direction>0)
         value+=value<max?step:0;
    else
        value-=value>0?step:0;
    if(direction<0)
        value-=value>-max?step:0;
    else
        value+=value<0?step:0;
    return value;
}

void Widget::keyPressEvent(QKeyEvent *event){
    if(event->key()==Qt::Key_W) w=true;
    if(event->key()==Qt::Key_S) s=true;
    if(event->key()==Qt::Key_A) a=true;
    if(event->key()==Qt::Key_D) d=true;
    if(event->key()==Qt::Key_Q) q=true;
    if(event->key()==Qt::Key_E) e=true;
    if(event->key()==Qt::Key_0) {
        rx=ry=rz=0;
        ax=ay=az=0;
    }
}

void Widget::keyReleaseEvent(QKeyEvent *event){
    if(event->key()==Qt::Key_W) w=false;
    if(event->key()==Qt::Key_S) s=false;
    if(event->key()==Qt::Key_A) a=false;
    if(event->key()==Qt::Key_D) d=false;
    if(event->key()==Qt::Key_Q) q=false;
    if(event->key()==Qt::Key_E) e=false;
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
    glRotatef(ax, 1.0, 0, 0);
    glRotatef(ay,0,1.0,0);
    glRotatef(az,0,0,1.0);
    glScaled(8.0f,8.0f,8.0f); // skaluje bryle(4x)

    glBegin(GL_QUADS);
     glColor3f(1.0f,0.0f,0.5f); // Color Red, kwadrat, podstawa
     glVertex3f(1.0f,1.0f,1.0f);
     glVertex3f(-1.0f, 1.0f, 1.0f);
     glVertex3f(-1.0f,-1.0f,1.0f);
     glVertex3f(1.0f, -1.0f, 1.0f);
    glEnd();

    glBegin(GL_TRIANGLES);
     glColor3f(1.0f, 0.0f, 0.0f);    // Color Yellow, 1T - gora
     glVertex3f(1.0f,1.0f,1.0f);
     glVertex3f(0.0f, 0.0f, -1.0f);
     glVertex3f(-1.0f, 1.0f, 1.0f);
    glEnd();

    glBegin(GL_TRIANGLES);
     glColor3f(1.0f, 1.0f, 0.0f);    // Color Orange, 2T - prawy bok
     glVertex3f(1.0f, 1.0f, 1.0f);
     glVertex3f(1.0f, -1.0f, 1.0f);
     glVertex3f(0.0f, 0.0f, -1.0f);
    glEnd();

    glBegin(GL_TRIANGLES);
     glColor3f(0.0f, 1.0f, 0.2f);   // Color Blue, 3T - dol bok
     glVertex3f(-1.0f, -1.0f, 1.0f);
     glVertex3f(1.0f, -1.0f, 1.0f);
     glVertex3f(0.0f, 0.0f, -1.0f);
     glEnd();

    glBegin(GL_TRIANGLES);
     glColor3f(0.0f, 0.2f, 1.0f);   // Color Violet, 4T - lewy bok
     glVertex3f(-1.0f, 1.0f, 1.0f);
     glVertex3f(-1.0f, -1.0f, 1.0f);
     glVertex3f(0.0f, 0.0f, -1.0f);
    glEnd();

}

void Widget::resizeGL(int width, int height){
    glViewport(0,0,width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);
    gluLookAt(25,30,15,0,0,0,0,1,0); // dobrac punkty obserwacj
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
