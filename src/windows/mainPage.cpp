#include "mainPage.h"
#include "QFileDialog"
#include "../Encode.h"

#include "../views/textField.h"

mainPage::mainPage(int index) : index(index) {
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    showFullScreen();
    setFrameShape(NoFrame);


    auto scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, width(), height());
    scene->setBackgroundBrush(QColor("white"));


    auto button = new Button(100, 100);
    scene->addItem(button);
    button->setPos((width() / 2) - 300, height() / 2);
    connect(button, &Button::onPress, this, &mainPage::openFile);


    auto textfield = new textField(width() / 4.2, height() / 12.5);
    textfield->setPlainText(outFileName);
    scene->addItem(textfield);
    textfield->setPos((width() / 2) + button->boundingRect().width(), height() / 2);


    setScene(scene);
}

void mainPage::openFile() {

    if (index % 2 == 0) {
        inFileName = QFileDialog::getOpenFileName(this, tr("open file to encode"), "c://", "TextFiles(*.txt)");


    } else {
        inFileName = QFileDialog::getOpenFileName(this, tr("open file to decode"), "c://", "compressFiles(*.cmp)");
    }
    Encode(inFileName, outFileName);
}