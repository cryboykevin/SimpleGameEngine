#ifndef EMITTER_H
#define EMITTER_H

#include <QPointF>
#include <QList>
#include <particle.h>
#include <helper.h>

class Emitter : public Particle
{
public:
    explicit Emitter(const QPointF &location, QList<Particle*>& particles);

    virtual bool tick();

private:
    int particleCreateCount();

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
