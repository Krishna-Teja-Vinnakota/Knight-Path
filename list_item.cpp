#include "list_item.h"
#include "util.h"

ListItem::ListItem(pi from, pi to): QListWidgetItem()
{
    setTextAlignment(Qt::AlignHCenter);
    setBackground(QBrush(Qt::white));
    setText(
        toChessNotation(from) + " to " + toChessNotation(to)
    );
}

void ListItem::highlight()
{
    // QGradient grad;
    // grad.setCoordinateMode(QGradient::ObjectMode);
    // grad = QGradient(QGradient::MorpheusDen);
    // QGradient::NightFade
    // QGradient::WildApple
    // QGradient::ZeusMiracle

    setBackground(QBrush(QColor(51,8,103)));
    setForeground(QBrush(Qt::white));
}

void ListItem::resetHighlight()
{
    setBackground(QBrush(Qt::white));
    setForeground(QBrush(Qt::black));
}
