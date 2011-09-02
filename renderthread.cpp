#include "renderthread.h"
#include <ostream>
#include <QDebug>


RenderThread::RenderThread( QObject* ptrParent ) : QThread( ptrParent )
{
   SDL_Init( SDL_INIT_VIDEO );

   particleManager = new ParticleManager;

   Particle* testParticle = new Particle(QPointF(50,50));
   testParticle->setVelocity(QPointF(200,-200));

   particleManager->append(testParticle);

   p_ptrScreen = SDL_SetVideoMode( 640, 480, 0, 0 );
   //TODO: check if file exists
   p_ptrBMP = SDL_LoadBMP( "test.bmp" );
   particleSprite = IMG_Load("/home/jf/Documents/simplegameengine/particlesprite.png"); if (particleSprite == 0) qDebug("img_load returned null!");
   p_ptrBMP = particleSprite;

   p_rctPosition.x = 0;
   p_rctPosition.y = 0;

   if (p_ptrBMP == 0) qDebug("bmp ptr is null");

   p_rctPosition.w = p_ptrBMP->w;
   p_rctPosition.h = p_ptrBMP->h;
}

RenderThread::~RenderThread()
{
   qDebug( "Cleaning up the mess" );
   SDL_FreeSurface( p_ptrBMP );
   SDL_Quit();
}

void RenderThread::run()
{
   SDL_Event event;
   bool bRunning = false;
   
   while( 1 )
   {
      if( SDL_PollEvent( &event ) )
      {
         if( event.type == SDL_KEYDOWN )
         {
            if( event.key.keysym.sym == SDLK_ESCAPE )
            {
               exit( 0 );
               return;
            }
            else if( event.key.keysym.sym == SDLK_SPACE )
            {
               bRunning = bRunning == true ? false : true;
            }
         }
      }
      
      if( bRunning )
      {
         move();
         particleManager->updateParticles();
      }
      


      SDL_FillRect( p_ptrScreen, 0, 0 );
      SDL_BlitSurface( p_ptrBMP, 0, p_ptrScreen, &p_rctPosition );
      renderParticles();
      SDL_Flip( p_ptrScreen );
      
      // Limit to 25 fps
      SDL_Delay( 40 ); //1000ms/25frames = 40ms/frame
   }
   
   exit( 1 );
}

void RenderThread::addParticle(Particle* particle)
{

}

void RenderThread::renderParticles()
{
    int count = particleManager->count();
    for(int i = 0; i<count;++i)
    {
        Particle* current = particleManager->at(i);
        SDL_BlitSurface(current->sprite, 0, p_ptrScreen, current->rect);
    }
}



void RenderThread::move()
{
   p_rctPosition.x += 5;
   if( p_rctPosition.x + p_rctPosition.w >= p_ptrScreen->w )
   {
      p_rctPosition.x = 0;
      p_rctPosition.y += 5;
   }
   if( p_rctPosition.y + p_rctPosition.h >= p_ptrScreen->h )
   {
      p_rctPosition.x = 0;
      p_rctPosition.y = 0;
   }
}
