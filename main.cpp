#include "scythe_calqlator.h"
#include <QApplication>
#include "qfile.h"
#include "qtextstream.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Scythe_calqlator w;




    w.show();

    return a.exec();
}
