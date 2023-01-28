#ifndef HUFFMAN_LOADINGBAR_H
#define HUFFMAN_LOADINGBAR_H

#include<QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsScene>

class loadingBar : public QObject, public QGraphicsPixmapItem {
Q_OBJECT
public:
    loadingBar(int width, int height, QGraphicsPathItem *parent = nullptr);

    ~loadingBar();

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


#endif //HUFFMAN_LOADINGBAR_H
