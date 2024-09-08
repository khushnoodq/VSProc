#include "uiBase/uimainwin.h"
#include <QMenuBar>
#include <QStatusBar>
#include <QToolBar>

uiMainWin::uiMainWin( QWidget* parent )
    : QMainWindow( parent ) 
{
    setupUi();
}

uiMainWin::~uiMainWin() 
{
    // Destructor implementation (if needed)
}

void uiMainWin::setupUi() 
{
    // Set up the main window
    setWindowTitle( "VSProc" );
}