/**
 * Description:
 * this file implements the Uniform Cost Search method in the SearchAlgorithm.h file
 *
 * @author Richard Quayson
 */

#include "SearchAlgorithm.h"
#include "MainHelper.h"
#include <deque>
#include <unordered_set>
#include <algorithm>
#include <iostream>


void SearchAlgorithm::UniformCostSearch(AirRoutePlanning problem) {

    cout << "\nAbout to do Uniform Cost Search on problem!" << endl;

    // defining data structures to be use for the frontier and explored nodes
    deque<Node> frontier;
    unordered_set<int> explored;

    // create a node out of the start city and add it to the frontier
    Node *root = new Node(problem.getInitialState());
    frontier.push_back(*root);

    while (!frontier.empty()) {
        // pop the node on the front
        Node *node = new Node(frontier.front());
        frontier.pop_front();

        // perform a goal test
        if (problem.goalTest(node->getState())) {
            cout << "Found a solution: " << node->getState() << endl;
            Solution solution = node->solutionPath();
            MainHelper::validPaths.push_back(solution);
            return;
        }

        // if the node is not the goal, add its state to the explored set
        else {
            explored.insert(node->getState());
            cout << "Expanding node: " << node->getState() << endl;

            try {
                // generate the possible destination airport from the given source airport
                vector<Route> destinationAirports = problem.actions(node->getState());

                for (const Route& route: destinationAirports) {
                    try {
                        int newState = route.getDestinationAirportId();

                        /**
                         * compute the path cost of the child node computed as the sum of the
                         * parent's path cost and the distance between the parent and the child
                         */
                        double pathCost = node->getPathCost() + MainHelper::getDistance(node->getState(), newState);

                        // create the child node from the information
                        Node* child = new Node(newState, node, pathCost);

                        // create an iterator object for the frontier (deque structure)
                        auto iter = find(frontier.begin(), frontier.end(), *child);

                        /**
                         * if the child's state has not been explored already and the node
                         * is not on the frontier to be explored, add it to the frontier for later exploration
                         */
                        if (explored.find(newState) == explored.end() && iter == frontier.end()) {
                            frontier.push_back(*child);
                        }
                    } catch (exception& e) {
                        cout << e.what() << endl;
                    }
                }
            } catch (exception& e) {
                cout << e.what() << endl;
            }
        }
    }
    // if no route is found after exploring the search tree, exit the program
    cout << "No valid route exist!" << endl;
}