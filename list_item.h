#ifndef LISTITEM_H
#define LISTITEM_H

#include <QListWidgetItem>

class ListItem : public QListWidgetItem
{
public:
    ListItem(std::pair<int,int> from, std::pair<int,int> to, QListWidget *parent = nullptr);
    void highlight();
    void resetHighlight();
};


#endif // LISTITEM_H
