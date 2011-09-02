#include <QLayout>
#include <QPushButton>

#include <SDL.h>

#include "controlwidget.h"
#include "renderthread.h"
#include "particle.h"

ControlWidget::ControlWidget() : QWidget( 0L ),
   p_btnRunPause( new QPushButton( tr( "Run/Pause" ), this ) ), p_ptrThread( new RenderThread( this ) )
{
   QVBoxLayout* ptrLayout = new QVBoxLayout( this );
   QPushButton* btnStop = new QPushButton( tr( "Stop" ), this );
   
   ptrLayout->addWidget( p_btnRunPause );
   ptrLayout->addWidget( btnStop );
   
   connect( p_btnRunPause, SIGNAL( clicked() ), this, SLOT( runPause() ) );
   connect( btnStop, SIGNAL( clicked() ), this, SLOT( stop() ) );
   
   connect( p_ptrThread, SIGNAL( finished() ), this, SLOT( close() ) );
   
   p_ptrThread->start();
}

void ControlWidget::runPause()
{
   SDL_Event event;
   event.type = SDL_KEYDOWN;
   event.key.keysym.sym = SDLK_SPACE;
   
   SDL_PushEvent( &event );
}

void ControlWidget::stop()
{
   SDL_Event event;
   event.type = SDL_KEYDOWN;
   event.key.keysym.sym = SDLK_ESCAPE;
   
   SDL_PushEvent( &event );
}
