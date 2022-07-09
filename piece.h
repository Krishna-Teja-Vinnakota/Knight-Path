#ifndef PIECE_H
#define PIECE_H

#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>
#include <QObject>
#include "tile.h"

class Piece : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)

public:
    Piece(QString pieceName, QGraphicsItem *parent = 0);

    QPointF getTilePoint(Tile *tile);
    void placePiece(Tile *tile);
    void setImage(QString pieceName);
    void movePieceTo(int x, int y);

private:
    QPropertyAnimation *anim;

};


#endif // PIECE_H
