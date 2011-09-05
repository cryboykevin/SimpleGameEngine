#include "emitter.h"
#include <QString>

Emitter::Emitter(const QPointF &location, ParticleManager *manager) : Particle(location), particleManager(manager)
{
this->setMass(0);
TimeToLive = 1000;
}

bool Emitter::tick()
{
    double dt = 0.04; //(0.04s per frame, 1/(25fps))
    //qDebug(qPrintable(QString::number(this->location().x())));
    //qDebug("Emitter tick, calls:");

    int count = particleCreateCount();
    for(int i = 0; i<count; ++i)
    {
        //particleManager = null?
        particleManager->addParticle(this->location(),1,QPointF(0,0));
        // properly implement this

        //direction

        //velocity

        //mass

    }

    return Particle::tick();
}

int Emitter::particleCreateCount()
{
    //TODO: implement this
    switch (timeDist) {
    case Gauss: break;
    case Dirac: break;
    case Uniform: break;
    }

    return 1;
}
