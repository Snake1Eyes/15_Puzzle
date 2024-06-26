#include <QApplication>
#include "GameController.h"
#include "MenuController.h"
#include "ManagersSystem/Managers.h"

void clearResources(AbstractController &menuController, AbstractController &gameController);

int main(int argc, char **argv) {
    QApplication gameApp{argc, argv};
    Managers::startManagers();
    GameController gameController;
    MenuController menuController;
    AbstractController::interconnectControllers(&menuController, &gameController);
    menuController.initializeController(nullptr);
    int execCode = QApplication::exec();
    Managers::getSavings()->savePreferences();
    clearResources(menuController, gameController);
    return execCode;
}

void clearResources(AbstractController &menuController, AbstractController &gameController) {
    menuController.dispose();
    gameController.dispose();
    Managers::getScene()->clearScenes();
}

#include "main.moc"