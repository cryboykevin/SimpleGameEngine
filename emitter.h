#ifndef EMITTER_H
#define EMITTER_H

#include <QPointF>
#include <QList>
#include <particle.h>
#include <particlemanager.h>
#include <helper.h>

class Emitter : public Particle
{
public:
    explicit Emitter(const QPointF &location, ParticleManager *manager);

    virtual bool tick();

private:
    int particleCreateCount();
    ParticleManager *particleManager;

    Distribution velocityDist;
    double avgVelocity;

    Distribution angleDist;
    double avgAngle;

    Distribution massDist;
    double avgMass;

    Distribution timeDist;
    int particleTTL;
    int particleCount;

};

#endif // EMITTER_H
