#include <QApplication>
#include <QPushButton>
#include <QString>
#include "src/Encode.h"
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
//    QPushButton button("Hello world!", nullptr);
//    button.resize(200, 100);
//    button.show();
    string inputFile, outputFile;
    QTextStream qtin(stdin);
    QString word1, word2;
    qtin >> word1 >> word2;
    Encode(word1.toStdString(), word2.toStdString());
    return QApplication::exec();
}
