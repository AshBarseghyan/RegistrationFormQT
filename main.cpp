#include "loginregistration.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginRegistration w;
    w.setWindowTitle("ABN");
    w.setWindowIcon(QIcon(":/imgs/icon.png"));
    w.show();
    return a.exec();
}
