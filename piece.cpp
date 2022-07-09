#include "piece.h"
#include "canvas.h"

extern Canvas *canvas;

Piece::Piece(QString pieceName, QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent)
{
    setZValue(10);
    setImage(pieceName);
    placePiece( canvas->tiles[0][0] );
    setVisible(false);                      // reset visibility toggled by placePiece
    canvas->addToScene(this);
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
    setVisible(true);
}

void Piece::setImage(QString pieceName)
{
    // init PixMap from res
    setPixmap(QPixmap(":/img/" + pieceName + ".png"));
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
