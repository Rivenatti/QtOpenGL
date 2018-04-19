/*#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();
}
*/
#include "widget.h"
#include <QtCore>
#include <QApplication>
#include <QLabel>
#include <QPixmap>
#define obraz "c:\\Users\\HP\\lena.jpg"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QImage img(obraz);
    QImage original_img(obraz);
    short bri=60;
    for(int y=0;y<img.height();y++){
        QRgb *line=(QRgb*)img.scanLine(y);
        for(int x=0;x<img.width();x++){
            QRgb color=line[x];
            color=qRgb(qRed(color)+bri>255?255:qRed(color)+bri,
                       qGreen(color)+bri>255?255:qRed(color)+bri,
                       qBlue(color)+bri>255?255:qRed(color)+bri);
            line[x]=color;
        }
    }
    QLabel label("");
    label.setPixmap(QPixmap::fromImage(img));
    QLabel original_label("");
    original_label.setPixmap(QPixmap::fromImage(img));
    original_label.setWindowTitle("original");
    original_label.show();
    label.setWindowTitle("jasny");


    label.show();

    return a.exec();
}
