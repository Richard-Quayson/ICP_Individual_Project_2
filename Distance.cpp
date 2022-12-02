/**
 * Description:
 * this file implements the haversine method defined in the Distance.h class
 * the haversine method computes the distance between two places on the map
 * given their longitudes and latitude values in degrees
 *
 * @author Paa Kwasi Kodua
 */

#include "Distance.h"
using namespace std;

Distance::Distance() = default;

double Distance::haversine(double lat1, double lon1, double lat2, double lon2) const {

    // converting latitude and longitude values to radians
    double sLat1 = lat1 * (pi / 180);
    double sLat2 = lat2 * (pi / 180);
    double dLon = (lon2 - lon1) * (pi / 180);
    double dLat = (lat2 - lat1) * (pi / 180);

    // (source: https://en.wikipedia.org/wiki/Haversine_formula)
    double a = pow(sin(dLat / 2.0),2.0) +
            cos(sLat1) * cos(sLat2) * pow(sin(dLon/2.0),2.0);
    double circumference = 2 * atan2(sqrt(a),sqrt(1.0 - a));

    // distance in km
    return earthRadius * circumference;
}