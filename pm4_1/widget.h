#ifndef WIDGET_H
#define WIDGET_H
#include <QtOpenGL>
#include <GL/GLU.h>
#include <QWidget>

class Widget : public QGLWidget
{
    Q_OBJECT
protected:
    void initalizeGL();
    void paintGL();
    void resizeGL(int width, int height);

public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif // WIDGET_H
