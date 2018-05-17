#include "widget.h"
#include <GL/glu.h>

Widget::Widget(QWidget *parent)
    : QGLWidget(parent){
     vx=vy=vz=0;
     dx=dy=dz=0;
     rx=ry=rz=0;
     ax=ay=az=0;
     lt=rt=up=dn=w=s=a=d=q=e=false;

     connect(&timer, SIGNAL(timeout()), SLOT(tick()));
     timer.start(33); // 30FPS
     //timer.start(100);  // dobrac czas
}

Widget::~Widget()
{

}

void Widget::tick(){
    float step=0.005;
    float max=0.3;
    float rstep=0.1;
    float rmax=15;

    if(lt)vx=valueChange(vx,-1,step,max);
    if(rt)vx=valueChange(vx,1,step,max);
    if(dn)vy=valueChange(vy,-1,step,max);
    if(up)vy=valueChange(vy,1,step,max);
    if(s) rx=valueChange(rx,-1,rstep,rmax);
    if(w) rx=valueChange(rx,1,rstep,rmax);
    if(a) rx=valueChange(ry,-1,rstep,rmax);
    if(d) rx=valueChange(ry,1,rstep,rmax);
    if(e) rx=valueChange(rz,-1,rstep,rmax);
    if(q) rx=valueChange(rz,1,rstep,rmax);

    dx+=vx;
    dy+=vy;
    dz+=vz;
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
    if(event->key()==Qt::Key_Left) lt=true;
    if(event->key()==Qt::Key_Right) rt=true;
    if(event->key()==Qt::Key_Up) up=true;
    if(event->key()==Qt::Key_Down) dn=true;
    if(event->key()==Qt::Key_W) w=true;
    if(event->key()==Qt::Key_S) s=true;
    if(event->key()==Qt::Key_A) a=true;
    if(event->key()==Qt::Key_D) d=true;
    if(event->key()==Qt::Key_Q) q=true;
    if(event->key()==Qt::Key_E) e=true;
    if(event->key()==Qt::Key_0) {
        dx=dy=dz=0;
        vx=vy=vz=0;
        rx=ry=rz=0;
        ax=ay=az=0;
    }
}

void Widget::keyReleaseEvent(QKeyEvent *event){
    if(event->key()==Qt::Key_Left) lt=false;
    if(event->key()==Qt::Key_Right) rt=false;
    if(event->key()==Qt::Key_Up) up=false;
    if(event->key()==Qt::Key_Down) dn=false;
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
         glTranslatef(dx, dy, dz);        // translacja
         glRotatef(ax, 1.0, 0  , 0);      // obroty
         glRotatef(ay, 0  , 1.0, 0);      // obroty
         glRotatef(az, 0  , 0  , 1.0);    // obroty

        glBegin(GL_QUADS);                // rysuje szczescian metoda QUADS

         glColor3f(  0.0f,  1.0f,   0.0f);// Color Blue
         glVertex3f( 1.0f,  1.0f,  -1.0f);// Top Right Of the Quad (TOP)
         glVertex3f(-1.0f,  1.0f,  -1.0f);// Top Left Of The Quad (TOP)
         glVertex3f(-1.0f,  1.0f,   1.0f);// Bottom Left Of The Quad (TOP)
         glVertex3f( 1.0f,  1.0f,   1.0f);// Bottom Right Of The Quad (TOP)

         glColor3f(  1.0f,  0.5f,  0.0f); // Color Orange
         glVertex3f( 1.0f, -1.0f,  1.0f); // Top Right Of The QUad (BOTTOM)
         glVertex3f(-1.0f, -1.0f,  1.0f); // Top Left Of The Quad (BOTTOM)
         glVertex3f(-1.0f, -1.0f, -1.0f); // Bottom Left Of The Quad (BOTTOM)
         glVertex3f( 1.0f, -1.0f, -1.0f); // Bottom Right Of The Quad (BOTTOM)

         glColor3f(  1.0f,  0.0f, 0.0f);  // Color Red
         glVertex3f( 1.0f,  1.0f, 1.0f);  // Top Right Of The Quad (FRONT)
         glVertex3f(-1.0f,  1.0f, 1.0f);  // Top Left Of The Quad (FRONT)
         glVertex3f(-1.0f, -1.0f, 1.0f);  // Bottom Left Of The Quad (FRONT)
         glVertex3f( 1.0f, -1.0f, 1.0f);  // Bottom Right Of The Quad (FRONT)

         glColor3f(  1.0f,  1.0f,  0.0f); // Color Yellow
         glVertex3f( 1.0f, -1.0f, -1.0f); // Top Right Of The Quad (BACK)
         glVertex3f(-1.0f, -1.0f, -1.0f); // Top Left Of The Quad (BACK)
         glVertex3f(-1.0f,  1.0f, -1.0f); // Bottom Left Of The Quad (BACK)
         glVertex3f( 1.0f,  1.0f, -1.0f); // Bottom Right Of The Quad (BACK)

         glColor3f(  0.0f,  0.0f,  1.0f); // Color Blue
         glVertex3f(-1.0f,  1.0f,  1.0f); // Top Right Of The Quad (LEFT)
         glVertex3f(-1.0f,  1.0f, -1.0f); // Top Left Of The Quad (LEFT)
         glVertex3f(-1.0f, -1.0f, -1.0f); // Bottom Left Of The Quad (LEFT)
         glVertex3f(-1.0f, -1.0f,  1.0f); // Bottom Right Of The Quad (LEFT)

         glColor3f( 1.0f,  0.0f,  1.0f);  // Color Violet
         glVertex3f(1.0f,  1.0f, -1.0f);  // Top Right Of The Quad (RIGHT)
         glVertex3f(1.0f,  1.0f,  1.0f);  // Top Left Of The Quad (RIGHT)
         glVertex3f(1.0f, -1.0f,  1.0f);  // Bottom Left Of The Quad (RIGHT)
         glVertex3f(1.0f, -1.0f, -1.0f);  // Bottom Right Of The Quad (RIGHT)
        glEnd();

}

void Widget::resizeGL(int width, int height){
    glViewport(0,0,width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);
    gluLookAt(20,0,15,0,0,0,0,1,0); // dobrac punkty obserwacj
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
