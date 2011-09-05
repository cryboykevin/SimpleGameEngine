#include "particlemanager.h"

ParticleManager::ParticleManager()
{
}

void ParticleManager::deleteAt(const int &i)
{
    delete this->at(i);
    removeAt(i);
}

ParticleManager::~ParticleManager()
{
    while(this->size() != 0) deleteAt(0);
}

void ParticleManager::addParticle(Particle *particle)
{
    this->append(particle);
}

void ParticleManager::addParticle(const QPointF &location, const double &mass, const QPointF &velocity)
{
    Particle* particle = new Particle(location, mass, velocity);
    this->append(particle);
}

void ParticleManager::updateParticles()
{
    for(int i = 0; i<this->count(); ++i)
    {
        //tick returns false if particle has reached its TTL
        if (!this->at(i)->tick())
        {
            qDebug("Particle expired.");
            delete this->at(i);
            this->removeAt(i);
        }
    }
}
