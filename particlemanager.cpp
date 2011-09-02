#include "particlemanager.h"

ParticleManager::ParticleManager()
{
}

void ParticleManager::deleteAt(int i)
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

void ParticleManager::updateParticles()
{
    for(int i = 0; i<this->count(); ++i)
    {
        if (!this->at(i)->tick())
        {
            qDebug("Particle expired.");
            delete this->at(i);
            this->removeAt(i);
        }
    }
}
