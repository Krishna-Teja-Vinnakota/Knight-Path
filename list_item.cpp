#include "list_item.h"
#include "util.h"

ListItem::ListItem(pi from, pi to, QListWidget *parent): QListWidgetItem(parent)
{
    setTextAlignment(Qt::AlignHCenter);
    setBackground(QBrush(Qt::white));
    setText(
        toChessNotation(from) + " to " + toChessNotation(to)
    );
}

void ListItem::highlight()
{
    QGradient grad = QGradient(QGradient::MorpheusDen);
    grad.setCoordinateMode(QGradient::ObjectMode);
    setBackground(
            QGradient(grad)
    );

    setForeground(QBrush(Qt::white));

    // QGradient::NightFade
    // QGradient::WildApple
    // QGradient::ZeusMiracle
}

void ListItem::resetHighlight()
{
    setBackground(QBrush(Qt::white));
    setForeground(QBrush(Qt::black));
}
