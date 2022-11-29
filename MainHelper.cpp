
#include "MainHelper.h"

unordered_map<int, Airport> MainHelper::airportData;
unordered_map<int, Airline> MainHelper::airlineData;
unordered_map<int, vector<Route>> MainHelper::routeData;

MainHelper::MainHelper() {}

// Function to check if the key is present or not using count()
bool containsKey(unordered_map<int, vector<Route>> unorderedMap, int key) {
    bool isPresent = true;
    if (unorderedMap.count(key) == 0) {
        isPresent = false;
    }
    return isPresent;
}

void MainHelper::instantiateAirportData() {

    string airportFilePath = "airports.csv";
    vector<vector<string>> airportAttributeVector = ReadWriteFile::read(airportFilePath);
    for (vector<string> airportVector: airportAttributeVector) {
        Airport airportObject = CreateObjects::createAirportObject(airportVector);
        airportData.insert({airportObject.getAirportId(), airportObject});
    }
}

void MainHelper::instantiateAirlineData() {

    string airlineFileName = "airlines.csv";
    vector<vector<string>> airlineAttributeVector = ReadWriteFile::read(airlineFileName);
    for (vector<string> airlineVector: airlineAttributeVector) {
        Airline airlineObject = CreateObjects::createAirlineObject(airlineVector);
        airlineData.insert({airlineObject.getAirlineId(), airlineObject});
    }
}

void MainHelper::instantiateRouteData() {
    string routeFilePath = "routes.csv";
    vector<vector<string>> routeAttributeVector = ReadWriteFile::read(routeFilePath);
    for (vector<string> routeVector: routeAttributeVector) {
        Route routeObject = CreateObjects::createRouteObject(routeVector);
        if (routeObject.isValidRoute()) {
            if (airlineData.at(routeObject.getAirlineId()).getActiveStatus().compare("Y")) {
                if (containsKey(routeData, routeObject.getSourceAirportId())) {
                    vector<Route> value = {};
                    value.push_back(routeObject);
                    routeData.insert({routeObject.getSourceAirportId(), value});
                } else {
                    vector<Route> value = routeData.at(routeObject.getSourceAirportId());
                    value.push_back(routeObject);
                    routeData[routeObject.getSourceAirportId()] = value;
                }
            }
        }
    }
}


vector<int> MainHelper::getAirportByCityCountry(string city, string country) {
    vector<int> airportIdsVector;
    for (auto&& [key, value] : airportData) {
        if (value.getCity() == city && value.getCountry() == country) {
            airportIdsVector.push_back(value.getAirportId());
        }
    }
    return airportIdsVector;
}


double MainHelper::getDistance(int sourceAirportId, int destinationAirportId) {
    Airport sourceAirport = airportData.at(sourceAirportId);
    Airport destinationAirport = airportData.at(destinationAirportId);

    Distance distanceObject;
    double distance = distanceObject.haversine(sourceAirport.getLatitude(), sourceAirport.getLongitude(),
                                               destinationAirport.getLatitude(), destinationAirport.getLongitude());

    return distance;
}
