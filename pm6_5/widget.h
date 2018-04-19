#ifndef WIDGET_H
#define WIDGET_H
#include <QtOpenGL/QtOpenGL>
#include <GL/GLU.h>
#include <QtGui>


#include <QWidget>

class Widget : public QGLWidget
{
    Q_OBJECT
    QTimer timer;
    float vx, vy, vz;
    float dx, dy, dz;

protected:
    void initalizeGL();
    void paintGL();
    void resizeGL(int width, int height);

private slots:
    void tick();

public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif // WIDGET_H
