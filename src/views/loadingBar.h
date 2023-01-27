#ifndef HUFFMAN_LOADING_H
#define HUFFMAN_LOADING_H

#include<QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsScene>

class loading : public QObject, public QGraphicsPixmapItem {
Q_OBJECT
public:
    loading(int width, int height, QGraphicsPathItem *parent = nullptr);

    ~loading();

public slots:

    void animate();

    void end();

private:
    int width{};
    int height{};
    int frame = {};
    QList<QPixmap *> frames{};
    QTimer *animateTimer;
    QTimer *removeTimer;
    QGraphicsScene *scene;

};


#endif //HUFFMAN_LOADING_H
