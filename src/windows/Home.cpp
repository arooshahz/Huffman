
#include "Home.h"
#include "../views/Button.h"

#include "mainPage.h"
#include "../views/loadingBar.h"
#include "../views/loadingBar.h"

Home::Home() {
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    showFullScreen();
    setFrameShape(NoFrame);

    auto scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 500, 500);

    auto encodeButton = new Button(143, 143);
    scene->addItem(encodeButton);
    encodeButton->setPos(width() / 10 + encodeButton->boundingRect().width(), height() / 15);
    connect(encodeButton, &Button::onPress, this, &Home::startEncoding);


    auto decodeButton = new Button(143, 143);
    scene->addItem(decodeButton);
    decodeButton->setPos(-width() / 10, height() / 15);
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