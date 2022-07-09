#include <QApplication>
#include <QHBoxLayout>

#include "canvas.h"
#include "form.h"

Canvas *canvas;
Form *form;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    canvas = new Canvas();

    // canvas->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    canvas->prepare();

    canvas->show();

    return a.exec();
}
