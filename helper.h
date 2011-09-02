#ifndef HELPER_H
#define HELPER_H
#include <QtCore/qmath.h>
#include <boost/random.hpp>
#include <boost/random/random_number_generator.hpp>
#include <boost/random/normal_distribution.hpp>
#include <boost/random/mersenne_twister.hpp>

#define pi 3.14159265358979323846

enum Distribution {Dirac, Gauss, Uniform};

double gauss(double mean, double variance);

double unif(double min, double max);

double dirac(double center);

double dgauss(double variance);

double dunif(double delta);

double ddirac();

double drand(Distribution dist, double dev);

double rand(Distribution dist, double dev, double center);


#endif // HELPER_H
