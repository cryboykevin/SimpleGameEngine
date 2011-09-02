#ifndef PARTICLE_H
#define PARTICLE_H

#include <QPoint>
#include <QList>
#include <SDL/SDL_image.h>
#include <SDL.h>

class Particle : public QPointF
{
public:
    explicit Particle(const QPointF &location);

    virtual bool tick();

    int TimeToLive; //frames
    int TimeLived;  //frames

    SDL_Surface* sprite;
    SDL_Rect* rect;

    void setMass(const double &mass);
    double mass() const;

    void setVelocity(const QPointF &velocity);
    QPointF velocity() const;
    double velocityf() const;

private:

    QPointF Location;
    double Mass;
    QPointF Velocity;
    QPointF Force;
    QPointF g;

};

#endif // PARTICLE_H
