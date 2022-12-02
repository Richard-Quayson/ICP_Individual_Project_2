/**
 * Description:
 * this file defines operations for the Solution class
 * operations include constructor and accessor methods,
 * and a createSolutionString method to create summary string of the Solution
 *
 * @author Richard Quayson
 */

#ifndef ICP_INDIVIDUAL_PROJECT_C___SOLUTION_H
#define ICP_INDIVIDUAL_PROJECT_C___SOLUTION_H

#include <vector>
#include <iostream>
using namespace std;

class Solution {

private:
    // stores the sequence of states from the start airport to the destination airport
    vector<int> stateSequence;

    // stores the value of the path cost from the start airport to the destination airport
    double pathCost{};

public:
    // default constructor for the Solution class
    Solution();

    /**
     * Constructor:
     * Build and initialise the objects of the Solution class
     *
     * @param stateSequence the sequence of actions from the initial state to the goal state
     * @param pathCost the distance between the stateSequence
     */
    Solution(vector<int> stateSequence, double pathCost);

    /**
     * returns the state sequence of a given Solution object
     * @return this.stateSequence
     */
    vector<int> getStateSequence();

    /**
     * returns the path cost of a given Solution object
     * @return this.pathCost
     */
    double getPathCost() const;

    /**
     * Description:
     * this methods create the summary to be written to the output file
     * using the state sequence, the airportData and the routeData
     * @return String
     */
    string createSolutionString();
};

#endif //ICP_INDIVIDUAL_PROJECT_C___SOLUTION_H