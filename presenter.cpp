#include "presenter.h"

Presenter::Presenter(IViewGame *view, QObject *parent)
    : QObject(parent), view(view) {

    QObject *viewObject = dynamic_cast<QObject*>(this->view);
    QObject::connect(viewObject, SIGNAL(signalFrameNext()), this, SLOT(refreshView()));

}

void Presenter::refreshView() {

    this->view->drawGrid();

}

