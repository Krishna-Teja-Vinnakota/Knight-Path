#ifndef BOARDLABEL_H
#define BOARDLABEL_H

#include <QGraphicsTextItem>

class BoardLabel : public QGraphicsTextItem
{
public:
    BoardLabel(QString text, QGraphicsItem *parent=0);

    qreal width();
    qreal height();
    qreal halfWidth();
    qreal halfHeight();

};


#endif // BOARDLABEL_H
