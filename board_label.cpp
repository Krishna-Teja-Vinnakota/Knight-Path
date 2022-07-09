#include <QFont>
#include "board_label.h"

BoardLabel::BoardLabel(QString text, QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    setZValue(2);
    QFont font = QFont("cursive", 17);         // font family, point
    font.setStyleHint(QFont::Cursive);
    setFont(font);
    setDefaultTextColor(QColor(238,238,210));
    setPlainText(text);
}

qreal BoardLabel::width()
{
    return boundingRect().width();
}

qreal BoardLabel::height()
{
    return boundingRect().height();
}

qreal BoardLabel::halfWidth()
{
    return boundingRect().width() / 2;
}

qreal BoardLabel::halfHeight()
{
    return boundingRect().height() / 2;
}
