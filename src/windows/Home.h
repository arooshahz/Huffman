#ifndef HUFFMAN_HOME_H
#define HUFFMAN_HOME_H

#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QPushButton>

class Home : public QGraphicsView {
Q_OBJECT
private:
    QGraphicsScene *scene;

public:
    Home();

    ~Home();

    void startEncoding();

    void startDecoding();


};


#endif //HUFFMAN_HOME_H
