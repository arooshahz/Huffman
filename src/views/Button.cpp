
#include "Button.h"
#include <QTextDocument>
#include <QFont>
#include <QPainter>


Button::Button(int width, int height, QString index, QGraphicsPathItem *parent) : index(index), width(width),
                                                                                  height(height),
                                                                                  QGraphicsPixmapItem(parent) {
    QPixmap pixmap1(":/images/" + index);
    pixmap1 = pixmap1.scaled(width, height, Qt::KeepAspectRatioByExpanding);
    setPixmap(pixmap1);

}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    emit onPress();
}