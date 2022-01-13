#include "MainFen.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MaFenetre ines;
    ines.show();
    return app.exec();
}
