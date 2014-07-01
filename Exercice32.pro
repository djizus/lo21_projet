greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += multimediawidgets
greaterThan(QT_MAJOR_VERSION, 4): QT += gui

RC_FILE = res.rc

SOURCES += \
    main.cpp \
    notes.cpp \
    ArticleEditeur.cpp \
    NotesEditeur.cpp \
    FoldableWidget.cpp \
    Audio.cpp \
    Image.cpp \
    Video.cpp

HEADERS += \
    notes.h \
    ArticleEditeur.h \
    NotesEditeur.h \
    FoldableWidget.h \
    Audio.h \
    Image.h \
    Video.h

RESOURCES +=
