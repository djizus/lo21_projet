#include <QApplication>
#include "NotesEditeur.h"

int main(int argc, char *argv[]){
    QApplication app(argc, argv);
    NotesEditeur editeur;
    editeur.show();
    return app.exec();
}
