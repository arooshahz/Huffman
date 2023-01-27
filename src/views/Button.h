

#ifndef HUFFMAN_BUTTON_H
#define HUFFMAN_BUTTON_H

#include <QGraphicsPixmapItem>

#include <QObject>

class Button : public QObject, public QGraphicsPixmapItem {
Q_OBJECT
private:
    int width{};
    int height{};
public:
    Button(int width, int height, QGraphicsPathItem *parent = nullptr);


protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

signals:

    void onPress();
};


#endif //HUFFMAN_BUTTON_H
