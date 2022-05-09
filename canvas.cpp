#include "canvas.h"

Canvas::Canvas(QWidget *parent): QGraphicsView(parent)
{   
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1400,900);

    setFixedSize(1400,900);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setScene(scene);

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::black);
    setBackgroundBrush(brush);
    setStyleSheet("border: 0px");
}

void Canvas::addToScene(QGraphicsItem *item)
{
    scene->addItem(item);
}

void Canvas::addWidgetToScene(QWidget *widget)
{
    scene->addWidget(widget);
}

void Canvas::removeFromScene(QGraphicsItem *item)
{
    scene->removeItem(item);

}

void Canvas::drawChessBoard()
{
    board = new Board();
    board->drawBoard(width()/2 - (400+175), 50);
}

void Canvas::prepare()
{
    drawChessBoard();

    form = new Form();
    form->setGeometry(1050,0,350,900);
    addWidgetToScene(form);

    knight = new Piece();

}
