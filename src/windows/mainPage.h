#ifndef HUFFMAN_MAINPAGE_H
#define HUFFMAN_MAINPAGE_H

#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QObject>
#include "../views/Button.h"

class mainPage : public QGraphicsView {
Q_OBJECT
private:
    QGraphicsScene *scene;
    int index;
    QString inFileName, outFileName;
public:
    mainPage(int index);

    void openFile();
};


#endif //HUFFMAN_MAINPAGE_H
