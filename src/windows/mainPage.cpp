#include "mainPage.h"
#include "QFileDialog"
#include "Result.h"
#include <filesystem>


mainPage::mainPage(int index) : index(index) {
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFrameShape(NoFrame);


    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 800, 800);
    auto pixmap = new QPixmap(":/images/mainPage");
    *pixmap = pixmap->scaled(800, 800, Qt::IgnoreAspectRatio);
    setBackgroundBrush(QPixmap(*pixmap));
    setScene(scene);


    buttonInFile = new Button(480, 45, "b");
    scene->addItem(buttonInFile);
    buttonInFile->setPos(130, 200);
    connect(buttonInFile, &Button::onPress, this, &mainPage::openFile);


    buttonOutFile = new Button(480, 45, "b");
    scene->addItem(buttonOutFile);
    buttonOutFile->setPos(130, 350);
    connect(buttonOutFile, &Button::onPress, this, &mainPage::saveFile);


    buttonStart = new Button(400, 100, "s");
    scene->addItem(buttonStart);
    buttonStart->setPos(200, 500);
    connect(buttonStart, &Button::onPress, this, &mainPage::start);


    label = new Label();
    scene->addItem(label);
    label->setPos((scene->width() / 2) - 600, scene->height() / 2 + 200);


}

mainPage::~mainPage() {
    delete scene;
    delete buttonStart;
    delete buttonOutFile;
    delete buttonInFile;
}

void mainPage::openFile() {


    if (index % 2 == 0) {
        inFileName = QFileDialog::getOpenFileName(this, tr("open file to encode"), "c://", "TextFiles(*.txt)");
        outFileName = "C://Users//Lenovo//Desktop//" + inFileName + ".cmp";
    } else {
        inFileName = QFileDialog::getOpenFileName(this, tr("open file to decode"), "c://", "compressFiles(*.cmp)");
        outFileName = "C://Users//Lenovo//Desktop//" + inFileName + ".txt";
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
    Huffman convert(inFileName, outFileName);

    if (index % 2 == 0) {
        convert.compress();
    } else {
        convert.decompress();
    }
    close();
    auto result = new Result();
    result->show();


}
