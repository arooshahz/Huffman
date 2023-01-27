#include "loading.h"

loading::loading(int width, int height, QGraphicsPathItem *parent) : width(width), height(height),
                                                                           QGraphicsPixmapItem(parent) {


    QPixmap pixmap1(":/images/loading2");
    pixmap1= pixmap1.scaled(width, height, Qt::IgnoreAspectRatio);
    setPixmap(pixmap1);

//    qInfo("hi");
    auto pixmap = new QPixmap(":/images/loading1");
    *pixmap = pixmap->scaled(150, 150);
    frames.append(pixmap);
    setPixmap(*pixmap);

    pixmap = new QPixmap(":/images/loading2");
    *pixmap = pixmap->scaled(150, 150);
    frames.append(pixmap);

    pixmap = new QPixmap(":/images/loading3");
    *pixmap = pixmap->scaled(150, 150);
    frames.append(pixmap);

    pixmap = new QPixmap(":/images/loading4");
    *pixmap = pixmap->scaled(150, 150);
    frames.append(pixmap);

    qInfo("hi");
    setPixmap(*frames.at(0));
    animateTimer = new QTimer();
    animateTimer->setInterval(100);
    connect(animateTimer, &QTimer::timeout, this, &loading::animate);
    animateTimer->start();

    qInfo("hi");

    removeTimer = new QTimer();
    removeTimer->setInterval(3000);
    connect(removeTimer, &QTimer::timeout, this, &loading::end);
    removeTimer->start();


}

loading::~loading() {
    qDeleteAll(frames);
    delete animateTimer;
    delete removeTimer;

}

void loading::animate() {
    setPixmap(*frames.at(frame));
    frame = (frame + 1) % 4;
}

void loading::end() {
    delete this;
}