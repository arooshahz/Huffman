#include <QApplication>
#include <QPushButton>
#include "src/Encode.h"
using namespace std;
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QPushButton button("Hello world!", nullptr);
    button.resize(200, 100);
    button.show();
Encode *test=new Encode();
test->getFrequencies("aroosha");

    return QApplication::exec();
}
