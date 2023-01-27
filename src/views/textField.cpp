
#include "textField.h"
#include <QFont>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QTextDocument>

textField::textField(int width, int height) : width(width), height(height),
                                              QGraphicsTextItem() {
    setDefaultTextColor(QColor("black"));
    QFont font;
    font.setPixelSize(20);
    font.setBold(true);
    setFont(font);
    setTextInteractionFlags(Qt::TextEditorInteraction);
    setTextWidth(width);
    document()->setDocumentMargin(10);


}

textField::~textField() {

}

void textField::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {

    painter->drawRect(boundingRect());

    QStyleOptionGraphicsItem newOption(*option);
    newOption.state = QStyle::State_None;
    QGraphicsTextItem::paint(painter, &newOption, widget);
}

QRectF textField::boundingRect() const {
    auto rect = QGraphicsTextItem::boundingRect();
    rect.setWidth(width);
    rect.setHeight(height);
    return rect;
}