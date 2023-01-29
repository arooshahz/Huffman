#include <QFont>
#include <QTextDocument>
#include "Label.h"

Label::Label() {


    setDefaultTextColor(QColor("black"));
    QFont font;
    font.setPixelSize(20);
    font.setBold(true);
    setFont(font);


    document()->setDocumentMargin(10);

}