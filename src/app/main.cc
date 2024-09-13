#include <QApplication>
#include "uiBase/uimainwin.h"

int main(int argc, char* argv[]) 
{
    QApplication app(argc, argv);

    uiMainWin mainWindow;
    mainWindow.show();

    return app.exec();
}
