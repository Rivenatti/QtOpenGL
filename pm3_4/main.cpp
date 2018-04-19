#include "widget.h"
#include <QApplication>
#include <QtWidgets>
#include <QtCore>
#include <QLabel>
#include <QPixmap>

#include <algorithm>
#include <vector>
#define obraz "c:\\users\\hp\\lena2.jpg"

QPixmap calcHistogram(QImage &img){
    std::vector<uint> imgv((uint *)img.bits(), ((uing *)img.bits())+
                           img.width()*img.height());
    std::vector<uint> rv(256), gv(256), bv(256);
    std::fill_n(rv.begin(), 256,0);
    std::fill_n(gv.begin(), 256,0);
    std::fill_n(bv.begin(), 256,0);

    for(uint pixel: imgv){
        rv[qRed(pixel)]++;
        gv[qGreen(pixel)]++;
        bv[qBlue(pixel)]++;
    }

    auto maxv=std::max(std::max)
}





int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();
}
