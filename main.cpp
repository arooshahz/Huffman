#include <QApplication>
#include <QPushButton>
#include <QString>

#include <string>
#include "src/windows/Home.h"
using namespace std;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);


//    string inputFile, outputFile;
//    QTextStream qtin(stdin);
//    QString word1, word2;
//    qtin >> word1 >> word2;
//    Encode(word1.toStdString(), word2.toStdString());

    (new Home())->show();


    return QApplication::exec();
}
