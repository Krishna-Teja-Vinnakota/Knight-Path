#ifndef LISTITEM_H
#define LISTITEM_H

#include <QListWidgetItem>
#include <QGraphicsRectItem>

class ListItem : public QListWidgetItem
{
public:
    ListItem(std::pair<int,int> from, std::pair<int,int> to);
    void highlight();
    void resetHighlight();

};


#endif // LISTITEM_H
