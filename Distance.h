/**
 * Description:
 * this class the provides approximate distance between
 * two points using the Haversine formula.
 *
 * @author Paa Kwasi Kodua
 */

#ifndef ICP_INDIVIDUAL_PROJECT_C___HAVERSINE_H
#define ICP_INDIVIDUAL_PROJECT_C___HAVERSINE_H

#include <cmath>
class Distance {
public:
    /**
     * Description:
     * default constructor create Distance objects for
     * accessing non-static methods of the distance class
     */
    Distance();

    /**
     * Description:
     * this method computes the distance between two places
     * using their longitudes and latitudes
     *
     * @param lat1 the latitude in degrees of location 1
     * @param lon1 the longitude in degrees of location 1
     * @param lat2 the latitude in degrees of location 2
     * @param lon2 the longitude in degrees of location 2
     * @return double distance in km
     */
    double haversine(double lat1, double lon1, double lat2, double lon2) const;

private:
    /**
     * Description:
     * constant instance variables storing the
     * values of the radius of the earth and pi
     */
    const double earthRadius = 6378.137;
    const double pi = 3.141592653589793238462;
};

#endif //ICP_INDIVIDUAL_PROJECT_C___HAVERSINE_H