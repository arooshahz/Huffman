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

    setScene(scene);

    auto button = new Button(100, 100);
    scene->addItem(button);
    button->setPos((width() / 2) - 300, height() / 2);
    connect(button, &Button::onPress, this, &mainPage::openFile);

    auto button2 = new Button(100, 100);
    scene->addItem(button2);
    button2->setPos((width() / 2) - 600, height() / 2);
    connect(button2, &Button::onPress, this, &mainPage::start);


    auto textfield = new textField(width() / 4.2, height() / 12.5);
    textfield->setPlainText(outFileName);
    scene->addItem(textfield);
    textfield->setPos((width() / 2) + button->boundingRect().width(), height() / 2);
//    outFileName=QFileDialog::getSaveFileName(this,tr("save file"),"c://","AllFiles(*.*);;compressFiles(*.cmp);;TextFiles(*.txt)");



    label=new Label();
    scene->addItem(label);
    label->setPos((scene->width() / 2) - 600, scene->height() / 2+200);




}

void mainPage::openFile() {


    if (index % 2 == 0) {
        inFileName = QFileDialog::getOpenFileName(this, tr("open file to encode"), "c://", "TextFiles(*.txt)");
        label->setPlainText(inFileName);

    } else {
        inFileName = QFileDialog::getOpenFileName(this, tr("open file to decode"), "c://", "compressFiles(*.cmp)");

    }






}
void mainPage::start() {


            Encode test(inFileName, outFileName,this->scene);



    if (index % 2 == 0) {
      test.compress();
        qInfo("hi");

    } else {
     test.decompress();
    }


}