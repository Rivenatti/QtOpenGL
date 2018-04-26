#ifndef WIDGET_H
#define WIDGET_H
//#include <QtOpenGL/QtOpenGL>
#include <QtOpenGL>
//#include <GL/GLU.h>
#include <QtGui>


#include <QWidget>

class Widget : public QGLWidget
{
    Q_OBJECT
    float dx, dy, dz;
    GLfloat y;
    GLfloat iLine;
    void keyPressEvent(QKeyEvent *);

protected:
    void initalizeGL();
    void paintGL();
    void resizeGL(int width, int height);

public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif // WIDGET_H
