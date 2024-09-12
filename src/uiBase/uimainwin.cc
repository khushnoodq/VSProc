#include "uiBase/uimainwin.h"
#include <QMenuBar>
#include <QStatusBar>
#include <QToolBar>

uiMainWin::uiMainWin()
    : QMainWindow( nullptr ) 
{
    setWindowTitle("VSProc");
}

uiMainWin::~uiMainWin() 
{}
