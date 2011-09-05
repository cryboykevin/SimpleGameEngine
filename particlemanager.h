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
    void addParticle(const QPointF &location = QPointF(0,0),  const double &mass = 1, const QPointF &velocity = QPointF(0,0));
    void deleteAt(const int &i);
    void updateParticles();
};

#endif // PARTICLEMANAGER_H
