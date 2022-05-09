#include "piece.h"
#include "canvas.h"

extern Canvas *canvas;

Piece::Piece(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent)
{
    setZValue(10);
}

QPointF Piece::getTilePoint(Tile *tile)
{
    return QPointF(
                tile->x() + 50 - pixmap().width() / 2,
                tile->y() + 50 - pixmap().height()/ 2
           );
}

void Piece::placePiece(Tile *tile)
{
    setPos(getTilePoint(tile));
}

void Piece::setImage()
{
    setPixmap(QPixmap(":/img/horse.png"));
}

void Piece::drawPiece(int row, int col)
{
    // PixMap must be set before calling placePiece
    setImage();
    placePiece( canvas->tiles[row][col] );
    canvas->addToScene(this);
    canvas->isKnightThere = true;
}

void Piece::movePieceTo(int x, int y)
{
    anim = new QPropertyAnimation(this, "pos");
    anim->setDuration(1000);
    anim->setStartValue( pos() );
    anim->setEndValue( getTilePoint(canvas->tiles[x][y]) );
    anim->setEasingCurve(QEasingCurve::InOutCubic);
    anim->start();
}
