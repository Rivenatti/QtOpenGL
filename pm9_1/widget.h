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

    QTimer timer;
    float rx, ry, rz;
    float ax, ay, az;
    bool w, s, a, d, q, e;
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);

    static float valueChange (float value, int direction, float step, float max);

protected:
    void initalizeGL();
    void paintGL();
    void resizeGL(int width, int height);

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void tick();

};
#endif // WIDGET_H
