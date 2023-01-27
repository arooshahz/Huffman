//
// Created by Lenovo on 1/27/2023.
//

#ifndef HUFFMAN_TEXTFIELD_H
#define HUFFMAN_TEXTFIELD_H

#include <QGraphicsTextItem>

class textField : public QGraphicsTextItem {

private:
    int width{};
    int height{};

public:
    textField(int width, int height);

    ~textField();

    QRectF boundingRect() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

};

#endif //HUFFMAN_TEXTFIELD_H
