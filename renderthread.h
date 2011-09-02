#pragma once

#include <QThread>
#include <SDL.h>
#include <particlemanager.h>
#include <particle.h>
#include <emitter.h>
#include <SDL/SDL_image.h>

class RenderThread : public QThread
{
   Q_OBJECT
   
   public:
      RenderThread( QObject* ptrParent );
      ParticleManager* particleManager;
      virtual ~RenderThread();
   
   protected:
      virtual void run();

   private:
      void move();
      void addParticle(Particle* particle);
      void renderParticles();

   private:
      SDL_Surface* p_ptrScreen;
      SDL_Surface* p_ptrBMP;
      SDL_Surface* particleSprite;
      SDL_Rect p_rctPosition;
};
