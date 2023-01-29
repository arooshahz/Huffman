#include "loadingBar.h"

using namespace std;

loadingBar::loadingBar(int width, int height, QGraphicsPathItem *parent) : width(width), height(height),
                                                                           QGraphicsPixmapItem(parent) {


    QPixmap pixmap1(":/images/l1");
    pixmap1 = pixmap1.scaled(width, height, Qt::IgnoreAspectRatio);
    setPixmap(pixmap1);


    auto pixmap = new QPixmap(":/images/l1");
    *pixmap = pixmap->scaled(width, height);
    frames.append(pixmap);
    setPixmap(*pixmap);

    pixmap = new QPixmap(":/images/l2");
    *pixmap = pixmap->scaled(width, height);
    frames.append(pixmap);

    pixmap = new QPixmap(":/images/l3");
    *pixmap = pixmap->scaled(width, height);
    frames.append(pixmap);

    pixmap = new QPixmap(":/images/l4");
    *pixmap = pixmap->scaled(width, height);
    frames.append(pixmap);

    pixmap = new QPixmap(":/images/l5");
    *pixmap = pixmap->scaled(width, height);
    frames.append(pixmap);

    pixmap = new QPixmap(":/images/l6");
    *pixmap = pixmap->scaled(width, height);
    frames.append(pixmap);

    pixmap = new QPixmap(":/images/l7");
    *pixmap = pixmap->scaled(width, height);
    frames.append(pixmap);

    pixmap = new QPixmap(":/images/l8");
    *pixmap = pixmap->scaled(width, height);
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
    frame = (frame + 1) % 8;
}

void loadingBar::end() {
    delete this;
}