
#include "Distance.h"
#include <math.h>
#include <algorithm> // for std::min
#include <iostream>  // std::cout
using namespace std;

Distance::Distance(void) {}

Distance::~Distance(void) {}

double Distance::haversine(double lat1, double lon1, double lat2, double lon2){
    // work in radians!
    //(from R. W. Sinnott, "Virtues of the Haversine," Sky and Telescope, vol. 68, no. 2, 1984, p. 159):
    double rlat1 = lat1*(pi()/180);
    double rlat2 = lat2*(pi()/180);
    double dlon = (lon2 - lon1) *(pi()/180);
    double dlat = (lat2 - lat1)*(pi()/180);
    double a = pow(sin(dlat/2.0),2.0) + cos(rlat1) * cos(rlat2) * pow(sin(dlon/2.0),2.0);
    //double c = 2 * asin(min(one,sqrt(a)));
    double c = 2 * atan2(sqrt(a),sqrt(1.0-a));
    return earthradius() * c;
}

double Distance::pythagores(double X1, double Y1, double X2,double Y2){
    // ignoring elevation diffrence - the world is flat ...
    double hypotenuse = sqrt(pow((X1 - X2),2) + pow((Y1 - Y2 ),2)  );
    return hypotenuse;
}