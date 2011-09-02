#include "particle.h"
#include <iostream>


Particle::Particle(const QPointF &location) : Location(location)
{
    Mass = 1;
    g = QPointF(0,981); // 1m == 100px
    TimeToLive = 150;
    sprite = IMG_Load("/home/jf/Documents/simplegameengine/particlesprite.png");
    if (sprite == 0) qDebug("img_load returned null!");
    rect = new SDL_Rect;
    rect->x = location.x();
    rect->y = location.y();
}

//returns false if particle has expired
bool Particle::tick()
{
    ++TimeLived;

    double dt = 0.04; //1/25, 25fps
    if (Mass != 0) Force = Mass*g;   //just gravity
    else Force = QPointF(0,0);
    Velocity += Force/Mass*dt; //explicit Euler
    Location += Velocity*dt;   //explicit Euler

    rect->x = Location.x();
    rect->y = Location.y();

    return (this->TimeLived<=this->TimeToLive);

}

double Particle::mass() const
{
    return Mass;
}

double Particle::velocityf() const
{
    return 0.0;
}

QPointF Particle::velocity() const
{
    return Velocity;
}

void Particle::setMass(const double &mass)
{
    Mass = mass;
}

void Particle::setVelocity(const QPointF &velocity)
{
    Velocity = velocity;
}
