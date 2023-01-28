
#include "Home.h"
#include "../views/Button.h"

#include "mainPage.h"
#include "../views/loadingBar.h"
#include "../views/loadingBar.h"

Home::Home() {
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//    showFullScreen();
    setFrameShape(NoFrame);

    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 800, 800);
    auto pixmap = new QPixmap(":/images/wallpaper");
    *pixmap = pixmap->scaled(800, 700, Qt::IgnoreAspectRatio);
    setBackgroundBrush(QPixmap(*pixmap));


    auto encodeButton = new Button(250, 250,"1");
    scene->addItem(encodeButton);
    encodeButton->setPos(450, 200);
    connect(encodeButton, &Button::onPress, this, &Home::startEncoding);


    auto decodeButton = new Button(250, 250,"2");
    scene->addItem(decodeButton);
    decodeButton->setPos(340-encodeButton->boundingRect().width(), 200);
    connect(decodeButton, &Button::onPress, this, &Home::startDecoding);


    setScene(scene);
}

Home::~Home() {
    delete scene;
}


void Home::startEncoding() {

    close();
    auto main = new mainPage(0);
    main->show();


}

void Home::startDecoding() {


    close();
    auto main = new mainPage(1);
    main->show();

}