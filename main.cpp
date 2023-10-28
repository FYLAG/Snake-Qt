#include "mainwindow.h"
#include "gamewindow.h"

#include <QApplication>

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    GameWindow *game = nullptr;
    Presenter *presenter = nullptr;

    MainWindow win(game, presenter);

    win.show();

    return app.exec();

}
