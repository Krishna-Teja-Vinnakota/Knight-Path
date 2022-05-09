QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    board.cpp \
    board_label.cpp \
    canvas.cpp \
    form.cpp \
    list_item.cpp \
    main.cpp \
    piece.cpp \
    search.cpp \
    state.cpp \
    tile.cpp

HEADERS += \
    board.h \
    board_label.h \
    canvas.h \
    form.h \
    list_item.h \
    piece.h \
    search.h \
    state.h \
    tile.h \
    util.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

FORMS += \
    form.ui
