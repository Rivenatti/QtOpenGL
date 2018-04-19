#include <QtCore>
#include <QApplication>
#include <QLabel>
#include <QPixmap>
#define obraz "c:\\Users\\HP\\lena.jpg"


int main(int argc, char *argv[])
{
    QApplication  a(argc, argv);
    QLabel img("");
    img.setPixmap(QPixmap(obraz));
    img.show();

    return a.exec();
}
