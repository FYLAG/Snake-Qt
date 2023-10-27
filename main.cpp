#include "mainwindow.h"
#include "gamewindow.h"

#include <QApplication>

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    // MainWindow win;

    GameWindow game({10, 10}, 1);

    game.show();

    return app.exec();

}
