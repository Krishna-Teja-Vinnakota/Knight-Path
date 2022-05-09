#include "tile.h"

Tile::Tile(QGraphicsItem *parent): QGraphicsRectItem(parent)
{
    setRect(0,0,100,100);

    // brush is for background
    brush.setStyle(Qt::SolidPattern);
    setZValue(-1);
}

void Tile::setColor(QColor color)
{
    brush.setColor(color);
    setBrush(color);
    pen.setColor(color);
    setPen(pen);
}

void Tile::resetOriginalColor()
{
    setColor(originalColor);
}

void Tile::setOriginalColor(QColor value)
{
    originalColor = value;
    setColor(originalColor);
}
