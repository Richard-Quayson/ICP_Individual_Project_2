/**
 * Description:
 * this file defines operations for the AirplaneRoutePlanning class
 * operations include goalTest and actions
 *
 * @author Richard Quayson
 */

#ifndef ICP_INDIVIDUAL_PROJECT_C___AIRROUTEPROBLEM_H
#define ICP_INDIVIDUAL_PROJECT_C___AIRROUTEPROBLEM_H

#include "Route.h"
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

/**
 * this class provides a definition for the constructor, the goalTest and actions method
 */

class AirRoutePlanning{
private:
    /**
     * instance variables
     */
    int initialState;
    int goalState;
    unordered_map<int, vector<Route>> routeData;

public:
    /**
     * Constructor:
     * Build and initialise the objects of this abstract class
     *
     * @param initState (the initial state of the flight, represented by the sourceAirportId)
     * @param goalState (the destination state of the fight, represented by the destinationAirportId)
     * @param routeData (the data on airports routes)
     */

    AirRoutePlanning(int initState, int goalState, unordered_map<int, vector<Route>> routeData);

    /**
     * returns the initial state of the AirRoutePlanning problem
     * @return initialState
     */
    int getInitialState() const;

    /**
     * returns the goal states of the AirRoutePlanning problem
     * @return goalState
     */
    int getGoalState() const;

    /**
     * returns the routeData to be used for the search for the AirRoutePlanning problem
     * @return routeData
     */
    unordered_map<int, vector<Route>> getMap();

    /**
     * checks whether a given state is the goal state
     * @param state current state (airport) the airplane is
     * @return boolean
     */
    bool goalTest(int state) const;

    /**
     * returns the route objects of the possible destination airports
     * the airplane can go from a given state
     *
     * @param state current state (airport) the airplane is
     * @return vector<Route>
     */
    vector<Route> actions(int state);

    /**
     * returns a string representation of a given AirRoutePlanning problem
     * @return String
     */
    string toString() const;
};

#endif //ICP_INDIVIDUAL_PROJECT_C___AIRROUTEPROBLEM_H