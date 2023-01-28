#include "loadingBar.h"

loadingBar::loadingBar(int width, int height, QGraphicsPathItem *parent) : width(width), height(height),
                                                                           QGraphicsPixmapItem(parent) {


    QPixmap pixmap1(":/images/loading2");
    pixmap1= pixmap1.scaled(width, height, Qt::IgnoreAspectRatio);
    setPixmap(pixmap1);

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

    setPixmap(*frames.at(0));
    animateTimer = new QTimer();
    animateTimer->setInterval(100);
    connect(animateTimer, &QTimer::timeout, this, &loadingBar::animate);
    animateTimer->start();


    removeTimer = new QTimer();
    removeTimer->setInterval(3000);
    connect(removeTimer, &QTimer::timeout, this, &loadingBar::end);
    removeTimer->start();


}

loadingBar::~loadingBar() {
    qDeleteAll(frames);
    delete animateTimer;
    delete removeTimer;

}

void loadingBar::animate() {
    setPixmap(*frames.at(frame));
    frame = (frame + 1) % 4;
}

void loadingBar::end() {
    delete this;
}