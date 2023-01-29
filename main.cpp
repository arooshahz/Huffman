#include <QApplication>
#include <QPushButton>
#include <QString>

#include <string>
#include "src/windows/Home.h"
using namespace std;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    (new Home())->show();


    return QApplication::exec();
}
