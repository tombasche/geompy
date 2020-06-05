#include <math.h>

const float EARTH_RADIUS = 6371.0;

double degreesToRadians(double degrees)
{
    const double halfC = M_PI / 180;
    return degrees * halfC;
}

float metreDistance(double lonA, double latA, double lonB, double latB)
{
    lonA = degreesToRadians(lonA);
    latA = degreesToRadians(latA);
    lonB = degreesToRadians(lonB);
    latB = degreesToRadians(latB);

    float dlon = lonB - lonA;
    float dlat = latB - latA;

    float a = pow(sin(dlat / 2), 2) + cos(latA) * cos(latB) * pow(sin(dlon / 2), 2);
    float c = 2 * asin(sqrt(a));

    return EARTH_RADIUS * c * 1000;
}
