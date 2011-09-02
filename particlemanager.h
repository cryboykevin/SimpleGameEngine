#ifndef PARTICLEMANAGER_H
#define PARTICLEMANAGER_H

#include <QList>
#include <particle.h>

class ParticleManager : public QList<Particle *>
{
public:
    ParticleManager();
    ~ParticleManager();
    void addParticle(Particle *particle);
    void deleteAt(int i);
    void updateParticles();
};

#endif // PARTICLEMANAGER_H
