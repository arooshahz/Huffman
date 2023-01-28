#ifndef HUFFMAN_RESULT_H
#define HUFFMAN_RESULT_H
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsView>
#include "../views/loadingBar.h"
#include "Home.h"
#include "../views/Button.h"
class Result :public QGraphicsView{
Q_OBJECT
private:
    QGraphicsScene *scene;
    QTimer *addButton;

public:
    Result();

    ~Result();
    void back();
    void addHomeButton();
};


#endif //HUFFMAN_RESULT_H
