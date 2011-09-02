#include "emitter.h"

Emitter::Emitter(const QPointF &location, QList<Particle*>& particles) : Particle(location)
{
this->setMass(0);
TimeToLive = 1000;
}

bool Emitter::tick()
{
    double dt = 0.04; //(0.04s per frame, 1/(25fps))

    int count = particleCreateCount();
    for(int i = 0; i<count; ++i)
    {

        //direction

        //velocity

        //mass

    }

    return Particle::tick();
}

int Emitter::particleCreateCount()
{
    switch (timeDist) {
    case Gauss: break;
    case Dirac: break;
    case Uniform: break;
    }
}
