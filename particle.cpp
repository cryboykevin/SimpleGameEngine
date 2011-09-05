#include "particle.h"
#include <iostream>
#include <QString>


Particle::Particle(const QPointF &location, const double &mass, const QPointF &velocity) : Location(location), Mass(mass), Velocity(velocity)
{
    qDebug("Particle created.");
    g = QPointF(0,981); // 1m == 100px
    TimeToLive = 100;
    TimeLived = 0;
    sprite = IMG_Load("/home/jf/Documents/simplegameengine/particlesprite.png");
    if (sprite == 0) qDebug("img_load returned null!");
    rect = new SDL_Rect;
    rect->x = location.x();
    rect->y = location.y();
}

//returns false if particle has expired
bool Particle::tick()
{
    //qDebug("Particle tick");
    ++TimeLived;

    double dt = 0.04; //1/25, 25fps
    if (Mass != 0) {
        Force = Mass*g;   //just gravity
        Velocity += Force/Mass*dt;} //explicit Euler
    else Force = QPointF(0,0);

    Location += Velocity*dt;   //explicit Euler

    rect->x = Location.x();
    rect->y = Location.y();

    //qDebug(qPrintable(QString::number(TimeLived)+" of "+QString::number(TimeToLive)));

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

void Particle::setLocation(const QPointF &location)
{
    Location = location;
}

QPointF Particle::location() const
{
    return Location;
}
