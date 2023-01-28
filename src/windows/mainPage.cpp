#include "mainPage.h"
#include "QFileDialog"
#include "../Encode.h"

#include "../views/textField.h"



mainPage::mainPage(int index) : index(index) {
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    showFullScreen();
    setFrameShape(NoFrame);



    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, width(), height());
    scene->setBackgroundBrush(QColor("white"));

    setScene(scene);

    label = new Label();
    scene->addItem(label);
    label->setPlainText("inFileName:");
    label->setPos((width() / 2) - 300, height() / 2+200);

    auto buttonInFile = new Button(100, 100);
    scene->addItem(buttonInFile);
    buttonInFile->setPos((width() / 2) - 300, height() / 2);
    connect(buttonInFile, &Button::onPress, this, &mainPage::openFile);

    label = new Label();
    scene->addItem(label);
    label->setPlainText("outFileName:");
    label->setPos((width() / 2), height() / 2+200);

    auto buttonOutfile = new Button(100, 100);
    scene->addItem(buttonOutfile);
    buttonOutfile->setPos((width() / 2) , height() / 2);
    connect(buttonOutfile, &Button::onPress, this, &mainPage::saveFile);

    label = new Label();
    scene->addItem(label);
    label->setPlainText("start:");
    label->setPos((width() / 2) - 600, height() / 2 + 200);

     buttonStart = new Button(100, 100);
    scene->addItem(buttonStart);
    buttonStart->setPos((width() / 2) - 600, height() / 2);
    connect(buttonStart, &Button::onPress, this, &mainPage::start );


//
//    auto textfield = new textField(width() / 4.2, height() / 12.5);
//    textfield->setPlainText(outFileName);
//    scene->addItem(textfield);
//    textfield->setPos((width() / 2) + button->boundingRect().width(), height() / 2);

//    outFileName=QFileDialog::getSaveFileName(this,tr("save file"),"c://","AllFiles(*.*);;compressFiles(*.cmp);;TextFiles(*.txt)");





    label = new Label();
    scene->addItem(label);
    label->setPos((scene->width() / 2) - 600, scene->height() / 2 + 200);


}

void mainPage::openFile() {


    if (index % 2 == 0) {
        inFileName = QFileDialog::getOpenFileName(this, tr("open file to encode"), "c://", "TextFiles(*.txt)");
        label->setPlainText(inFileName);

    } else {
        inFileName = QFileDialog::getOpenFileName(this, tr("open file to decode"), "c://", "compressFiles(*.cmp)");

    }


}

void mainPage::saveFile() {
    outFileName = QFileDialog::getSaveFileName(this, tr("save file"), "c://",
                                               "AllFiles(*.*);;compressFiles(*.cmp);;TextFiles(*.txt)");


}

void mainPage::start() {


        auto loading=new loadingBar(143,143);
    scene->addItem(loading);
    loading->setPos((width() / 2) - 600, height() / 2);

    Encode test(inFileName, outFileName, this->scene);


    if (index % 2 == 0) {
        test.compress();


    } else {
        test.decompress();
    }
    qInfo("done!");
    delete buttonStart;
}
