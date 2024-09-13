/*+
________________________________________________________________________

    Author: Khushnood Qadir
________________________________________________________________________

-*/

#include <QApplication>
#include "uiMain/uiapp.h"

int main(int argc, char* argv[]) 
{
    QApplication app(argc, argv);

    AppMainWin().show();

    return app.exec();
}
