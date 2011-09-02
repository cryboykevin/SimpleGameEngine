#include <SDL.h>

#include <QApplication>

#include "controlwidget.h"


int main( int argc, char* argv[] )
{
   QApplication app( argc, argv );
   
   ControlWidget* ptrWgt = new ControlWidget();
   
   ptrWgt->show();
   
   return app.exec();
}
