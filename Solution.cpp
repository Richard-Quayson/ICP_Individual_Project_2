/**
 * Description:
 * this file implements methods defined in the Solution.h file
 *
 * @author Richard Quayson
 */

#include "Solution.h"
#include "Route.h"
#include "MainHelper.h"

Solution::Solution() = default;

Solution::Solution(vector<int> stateSequence, double pathCost) {
    this->stateSequence = std::move(stateSequence);
    this->pathCost = pathCost;
}

vector<int> Solution::getStateSequence() {
    return stateSequence;
}

double Solution::getPathCost() const {
    return pathCost;
}

string Solution::toString() {
    string solution = "Solution { Action Sequence: ";
    for (int state: stateSequence) {
        solution += to_string(state) + ", ";
    }
    solution += "Path cost: " + to_string(pathCost) + " }";

    return solution;
}

/**
 * Logic:
 * loops through the state sequence of a given Solution object
 * and retrieves the possible routes for the given state
 * checks if a particular route has the same destination airport as the next state in the stateSequence
 * if true, creates a string of the airlineCode, sourceAirportCode, destinationAirportCode
 * for all states in the sequence and total flights, total additional stops,
 * total distance and the optimality criteria
 */
string Solution::createSolutionString() {
    string solutionString;
    vector<int> actionSequence = this->getStateSequence();
    int count = 0;
    int totalStops = 0;
    for (int airportId: actionSequence) {
        for (Route route: MainHelper::routeData.at(airportId)) {
            if (count < (actionSequence.size() -1)) {
                if (route.getDestinationAirportId() == actionSequence[count + 1]) {
                    solutionString += to_string(count+1) + ". " + route.getAirlineCode() + " from " +
                            MainHelper::airportData.at(route.getSourceAirportId()).getIataCode() + " to " +
                            MainHelper::airportData.at(route.getDestinationAirportId()).getIataCode() + " " +
                            to_string(route.getStops()) + " stops.\n";
                    count ++;
                    totalStops += route.getStops();
                }
            }
        }
    }

    solutionString += "\nTotal flights: " + to_string(actionSequence.size() - 1);
    solutionString += "\nTotal additional stops: " + to_string(totalStops);
    solutionString += "\nTotal distance: " + to_string(this->getPathCost()) + " km";
    solutionString += "\nOptimality criteria: distance covered by route";

    return solutionString;
}