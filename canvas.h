#ifndef CANVAS_H
#define CANVAS_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QPen>
#include <QPropertyAnimation>
#include <stack>
#include "form.h"
#include "board.h"
#include "tile.h"
#include "piece.h"

class Canvas : public QGraphicsView
{

public:
    // contructor
    Canvas(QWidget *parent = 0);

    // methods
    void drawChessBoard();
    void addToScene(QGraphicsItem *item);
    void addWidgetToScene(QWidget *widget);
    void removeFromScene(QGraphicsItem *item);
    void prepare();
    void markStep(int x, int y);
    void resetSteps();

    Piece *knight, *flag, *start, *step;
    std::stack<Piece*> stepStack;
    Tile *tiles[8][8];

//public slots:
//    void start();

private:
    QGraphicsScene *scene;
    Form *form;
    Board *board;

};


#endif // CANVAS_H
