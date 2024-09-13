#include "uiBase/uimainwin.h"
#include <QMenuBar>
#include <QStatusBar>
#include <QToolBar>

uiMainWin::uiMainWin( QWidget* p )
    : QMainWindow( p ) 
{
    setWindowTitle("VSProc");
}

uiMainWin::~uiMainWin() 
{}
