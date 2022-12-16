/**
 * Description:
 * this file implements methods defined in the AirRoutePlanning.h file
 *
 * @author Richard Quayson
 */

#include "AirRoutePlanning.h"
#include "Route.h"
using namespace std;

AirRoutePlanning::AirRoutePlanning(int initState, int goalState, unordered_map<int, vector<Route>> routeData){
    this->initialState = (int)initState;
    this->goalState = (int)goalState;
    this->routeData = routeData;
}

int AirRoutePlanning::getInitialState() const {
    return initialState;
}

int AirRoutePlanning::getGoalState() const {
    return goalState;
}

unordered_map<int, vector<Route>> AirRoutePlanning::getMap() {
    return routeData;
}

bool AirRoutePlanning::goalTest(int state) const {
    return (goalState == state);
}

vector<Route> AirRoutePlanning::actions(int state) {
    return routeData.at(state);
}

string AirRoutePlanning::toString() const {
    string airRoutePlanning = "AirplaneRoutePlanning {";
    airRoutePlanning += "initialState=" + to_string(getInitialState());
    airRoutePlanning += ", goalState=" + to_string(getGoalState());

    return airRoutePlanning;
}