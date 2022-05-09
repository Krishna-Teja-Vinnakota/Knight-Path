#ifndef BOARD_H
#define BOARD_H

#include <QGraphicsRectItem>

class Board
{
public:
    Board();

    void drawTiles(int x, int y);
    void drawLabels(int x, int y);
    void drawBoard(int x, int y);

};


#endif // BOARD_H
