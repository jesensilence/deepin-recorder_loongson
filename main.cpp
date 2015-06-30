#include "drecorder.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DRecorder w;
    w.show();

    return a.exec();
}
