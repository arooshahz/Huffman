#include "mainPage.h"
#include "QFileDialog"
#include "../views/textField.h"
#include "Result.h"
#include <filesystem>


mainPage::mainPage(int index) : index(index) {
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFrameShape(NoFrame);


    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 800, 800);
    auto pixmap = new QPixmap(":/images/mainPage");
    *pixmap = pixmap->scaled(800, 700, Qt::IgnoreAspectRatio);
    setBackgroundBrush(QPixmap(*pixmap));
    setScene(scene);


    auto buttonInFile = new Button(480, 45,"b");
    scene->addItem(buttonInFile);
    buttonInFile->setPos( 130, 200);
    connect(buttonInFile, &Button::onPress, this, &mainPage::openFile);


    auto buttonOutfile = new Button(480, 45,"b");
    scene->addItem(buttonOutfile);
    buttonOutfile->setPos(130, 350);
    connect(buttonOutfile, &Button::onPress, this, &mainPage::saveFile);



     buttonStart = new Button(400,100,"s");
    scene->addItem(buttonStart);
    buttonStart->setPos(200, 500);
    connect(buttonStart, &Button::onPress, this, &mainPage::start );







    label = new Label();
    scene->addItem(label);
    label->setPos((scene->width() / 2) - 600, scene->height() / 2 + 200);


}

void mainPage::openFile() {


    if (index % 2 == 0) {
        inFileName = QFileDialog::getOpenFileName(this, tr("open file to encode"), "c://", "TextFiles(*.txt)");
        label->setPlainText(inFileName);

        outFileName="C://Users//Lenovo//Desktop//"+inFileName+".cmp";
    } else {
        inFileName = QFileDialog::getOpenFileName(this, tr("open file to decode"), "c://", "compressFiles(*.cmp)");
        outFileName="C://Users//Lenovo//Desktop//"+inFileName+".txt";
    }


}

void mainPage::saveFile() {



    if (index % 2 == 0) {
        outFileName = QFileDialog::getSaveFileName(this, tr("save file"), "c://", "compressFiles(*.cmp)");


    } else {
        outFileName = QFileDialog::getSaveFileName(this, tr("save file"), "c://", "TextFiles(*.txt)");

    }


}

void mainPage::start() {


    Encode convert(inFileName,outFileName);



    if (index % 2 == 0) {
        convert.compress();


    } else {
        convert.decompress();
    }

    close();
    auto result = new Result();
    result->show();





}
