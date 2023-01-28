#ifndef HUFFMAN_MAINPAGE_H
#define HUFFMAN_MAINPAGE_H

#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QObject>
#include "../views/Button.h"
#include "../views/Label.h"
#include "../views/loadingBar.h"

class mainPage : public QGraphicsView {
Q_OBJECT


private:
    int index;
    QString inFileName, outFileName;
    Label *label;
    Button* buttonStart;

public:
    mainPage(int index);

    QGraphicsScene *scene;

    void openFile();

    void start();

    void saveFile();
};


#endif //HUFFMAN_MAINPAGE_H
