#ifndef UTIL_H
#define UTIL_H

// below two are required for delay function
#include <QTimer>
#include <QEventLoop>

// required for toChessNotation function
#include <QString>

typedef std::pair<int, int> pi;

inline void delay(int millisecondsWait)
{
    QEventLoop loop;
    QTimer t;
    t.connect(&t, &QTimer::timeout, &loop, &QEventLoop::quit);
    t.start(millisecondsWait);
    loop.exec();
}

inline pi toIndex(QString str)
{
    std::string s = str.toStdString();
    int x = 7 - (s[1] - '1');
    int y = s[0] - 'a';
    return std::make_pair(x, y);
}

inline QString toChessNotation(pi point)
{
    QString a = QString('a'+point.second);
    QString b = QString('8'-point.first);
    return a+b;
}

#endif // UTIL_H
