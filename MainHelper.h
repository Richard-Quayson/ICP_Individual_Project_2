
#ifndef ICP_INDIVIDUAL_PROJECT_C___MAINHELPER_H
#define ICP_INDIVIDUAL_PROJECT_C___MAINHELPER_H

#include "Airport.h"
#include "Airline.h"
#include "Route.h"
#include "ReadWriteFile.h"
#include "CreateObjects.h"
#include "Distance.h"
#include <vector>
#include <unordered_map>
using namespace std;

class MainHelper {

public:
    MainHelper();
    static unordered_map<int, Airport> airportData;
    static unordered_map<int, Airline> airlineData;
    static unordered_map<int, vector<Route>> routeData;

    void instantiateAirportData();
    void instantiateAirlineData();
    void instantiateRouteData();
    vector<int> getAirportByCityCountry(string city, string country);
    double getDistance(int sourceAirportId, int destinationAirportId);
};

#endif //ICP_INDIVIDUAL_PROJECT_C___MAINHELPER_H
