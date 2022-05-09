#include "form.h"
#include "ui_form.h"
#include <QRegExp>
#include "canvas.h"
#include "list_item.h"
#include "util.h"
#include "search.h"

extern Canvas *canvas;

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    ui->movesLabel->setVisible(false);
    ui->listWidget->setVisible(false);
}

Form::~Form()
{
    delete ui;
}

void Form::validateTextInput()
{
    QRegExp rx("[a-h][1-8]");

    bool isSrcValid = rx.exactMatch( ui->input1->text() );
    bool isDesValid = rx.exactMatch( ui->input2->text() )
                        && (ui->input1->text() != ui->input2->text());

    if (isSrcValid) {
        // get the co-ordinates from chess notation
        // and pass them over to drawPiece
        pi knightPos = toIndex(ui->input1->text());
        int row = knightPos.first, col = knightPos.second;
        if (canvas->isKnightThere) {
            canvas->knight->placePiece(canvas->tiles[row][col]);
            ui->movesLabel->setVisible(false);
            ui->listWidget->setVisible(false);
        } else {
            canvas->knight->drawPiece(row, col);
        }
    }

    bool flag = isSrcValid && isDesValid;
    ui->pushButton->setEnabled(flag);
}

void Form::onButtonClick()
{
    if (! ui->input1->isEnabled() ) return;

    QListWidget *listW = ui->listWidget;
    ListItem *item;

    listW->clear();

    pi a = toIndex(ui->input1->text());
    pi b = toIndex(ui->input2->text());

    Search aStarSearch(a, b);
    std::list<pi> path = aStarSearch.getPath();

    std::list<ListItem*> listItems;

    ui->input1->setEnabled(false);
    ui->input2->setEnabled(false);

    // add path moves into QWidgetList

    auto from = path.begin();
    auto to   = ++path.begin();

    while(to != path.end())
    {
        item = new ListItem(*from, *to);
        listW->addItem(item);
        listItems.push_back(item);
        from++; to++;
    }

    listW->setMinimumHeight(
            (listW->sizeHintForRow(0) + 2*listW->spacing())*listW->count()
                + 2*listW->frameWidth()
          );
    listW->setMaximumHeight(
            (listW->sizeHintForRow(0) + 2*listW->spacing())*listW->count()
                + 2*listW->frameWidth()
          );
    ui->movesLabel->setVisible(true);
    listW->setVisible(true);

    // render animation for moves

    delay(1000);

    auto curItem = listItems.begin();
    auto nextItem = ++listItems.begin();
    to   = ++path.begin();

    while(to != path.end())
    {
        (*curItem)->highlight();
        canvas->knight->movePieceTo(to->first, to->second);
        delay(2000);
        if (nextItem != listItems.end())
            (*nextItem)->highlight();
        (*curItem)->resetHighlight();
        curItem++, nextItem++, to++;
    }

    ui->input1->setEnabled(true);
    ui->input2->setEnabled(true);

}
