#include <helper.h>

double gauss(double mean, double variance)
{
    boost::mt11213b rng;
    boost::normal_distribution<> dist(mean, variance);
    return dist(rng);
}

double unif(double min, double max)
{
    boost::mt11213b rng;
    boost::uniform_real<> dist(min,max);
    return dist(rng);
}

double dirac(double center)
{
    return center;
}

double dgauss(double variance)
{
    return gauss(0,variance);
}

double ddirac()
{
    return 0;
}

double dunif(double delta)
{
    return unif(-delta/2,delta/2);
}

double drand(Distribution dist)
{
    return 0;
}

double drand(Distribution dist, double dev)
{
    switch (dist) {
        case Dirac: return ddirac();
        case Gauss: return dgauss(dev);
        case Uniform: return dunif(dev);
    }
}

double rand(Distribution dist, double dev, double center)
{
    return center+drand(dist,dev);
}
