#include "Result.h"

Result::Result() {

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFrameShape(NoFrame);

    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 800, 800);
    auto pixmap = new QPixmap(":/images/done");
    *pixmap = pixmap->scaled(800, 800, Qt::IgnoreAspectRatio);
    setBackgroundBrush(QPixmap(*pixmap));


    auto loading = new loadingBar(800, 800);
    scene->addItem(loading);
    loading->setPos(0, 0);


    addButton = new QTimer();
    addButton->setInterval(3000);
    connect(addButton, &QTimer::timeout, this, &Result::addHomeButton);
    addButton->start();


    setScene(scene);
}

Result::~Result() {
    delete addButton;
    delete scene;

}

void Result::back() {
    close();
    auto home = new Home();
    home->show();

}

void Result::addHomeButton() {
    auto homeIcon = new Button(100, 100, "home");
    scene->addItem(homeIcon);
    homeIcon->setPos(350, 150);
    connect(homeIcon, &Button::onPress, this, &Result::back);
}