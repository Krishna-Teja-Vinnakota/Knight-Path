#ifndef TILE_H
#define TILE_H

#include <QGraphicsRectItem>
#include <QBrush>
#include <QPen>

class Tile : public QGraphicsRectItem
{
public:
    Tile(QGraphicsItem *parent=0);

    // methods
    void setColor(QColor color);
    void resetOriginalColor();
    void setOriginalColor(QColor value);

    int row;
    int col;

private:
    QBrush brush;
    QPen pen;
    QColor originalColor;

};


#endif // TILE_H
