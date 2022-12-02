/**
 * Description:
 * this method implement methods defined in the MainHelper.h
 *
 * @author Richard Quayson
 */

#include "MainHelper.h"

unordered_map<int, Airport> MainHelper::airportData;
unordered_map<int, Airline> MainHelper::airlineData;
unordered_map<int, vector<Route>> MainHelper::routeData;
vector<Solution> MainHelper::validPaths;

string MainHelper::trim(std::string& str) {
    str.erase(str.find_last_not_of(' ') + 1);         // suffixing spaces
    str.erase(0, str.find_first_not_of(' '));      // prefixing spaces
    return str;
}

void MainHelper::instantiateAirportData() {

    string airportFilePath = "airports.csv";
    vector<vector<string>> airportAttributeVector = ReadWriteFile::read(airportFilePath);
    for (const vector<string>& airportVector: airportAttributeVector) {
        Airport airportObject = CreateObjects::createAirportObject(airportVector);
        airportData.insert({airportObject.getAirportId(), airportObject});
    }
}

void MainHelper::instantiateAirlineData() {

    string airlineFileName = "airlines.csv";
    vector<vector<string>> airlineAttributeVector = ReadWriteFile::read(airlineFileName);
    for (const vector<string>& airlineVector: airlineAttributeVector) {
        Airline airlineObject = CreateObjects::createAirlineObject(airlineVector);
        airlineData.insert({airlineObject.getAirlineId(), airlineObject});
    }
}

/**
 * Logic:
 * it checks if the route is valid (source: Routable.h)
 * checks if the airline for that route object is active
 * checks if the key (source Airport ID) already exists
 * if it exists, get the current value and add the route object to it
 * else, create a new arraylist for the values and add the route object to it
 * and put the value into the map with the source Airport ID as key
 */
void MainHelper::instantiateRouteData() {
    string routeFilePath = "routes.csv";
    vector<vector<string>> routeAttributeVector = ReadWriteFile::read(routeFilePath);
    for (const vector<string>& routeVector: routeAttributeVector) {
        Route routeObject = CreateObjects::createRouteObject(routeVector);
        if (routeObject.isValidRoute()) {
            if (airlineData.at(routeObject.getAirlineId()).getActiveStatus() == "Y") {
                if (routeData.find(routeObject.getSourceAirportId()) == routeData.end()) {
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

vector<int> MainHelper::getAirportByCityCountry(const string& city, const string& country) {
    vector<int> airportIdsVector;
    for (pair<int, Airport> element : airportData) {
        if (element.second.getCity() == city && element.second.getCountry() == country) {
            airportIdsVector.push_back(element.first);
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