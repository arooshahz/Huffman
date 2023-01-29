#ifndef HUFFMAN_MAINPAGE_H
#define HUFFMAN_MAINPAGE_H

#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QObject>
#include "../views/Button.h"
#include "../Huffman.h"
#include "../views/Label.h"

class mainPage : public QGraphicsView {
Q_OBJECT
private:
    int index;
    Label *label;
    QString inFileName, outFileName;
    Button *buttonInFile;
    Button *buttonOutFile;
    Button *buttonStart;
    QGraphicsScene *scene;
public:
    mainPage(int index);

    ~mainPage();


    void openFile();

    void start();

    void saveFile();
};


#endif //HUFFMAN_MAINPAGE_H
