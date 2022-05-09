#include "board.h"
#include "tile.h"
#include "canvas.h"
#include "board_label.h"

extern Canvas *canvas;

Board::Board()
{

}

void Board::drawTiles(int x, int y)
{
    int OFFSET = 100;                                               // tile is 100x100

    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++)
        {
            Tile *tile = new Tile();
            tile->row = i;
            tile->col = j;
            tile->setPos(x + OFFSET*j, y + OFFSET*i);
            if ( (i+j)%2==0 ) {
                tile->setOriginalColor(QColor(238,238,210));        // light QColor(r,g,b)
            } else {
                tile->setOriginalColor(QColor(118,150, 86));        // dark
            }
            canvas->tiles[i][j] = tile;
            canvas->addToScene(tile);
        }
    }
}

void Board::drawLabels(int x, int y)
{
    int OFFSET = 100;                                               // tile is 100x100
    int HALF_OFFSET = 50;
    for (int i=0; i<8; i++) {
        BoardLabel *alphaLabel = new BoardLabel(QString('a'+i));
        alphaLabel->setPos(
                      x + OFFSET*i + HALF_OFFSET - alphaLabel->halfWidth(),
                      y + OFFSET*8
                    );
        canvas->addToScene(alphaLabel);

        BoardLabel *numLabel = new BoardLabel(QString('8'-i));
        numLabel->setPos(
                    x - numLabel->width() - 5,
                    y + OFFSET*i + HALF_OFFSET - numLabel->halfHeight()
                  );
        canvas->addToScene(numLabel);
    }
}

void Board::drawBoard(int x, int y)
{
    drawTiles(x, y);
    drawLabels(x,y);
}
