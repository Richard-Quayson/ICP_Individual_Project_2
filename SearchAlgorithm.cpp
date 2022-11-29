

#include "SearchAlgorithm.h"
#include "MainHelper.h"
#include <queue>
#include <unordered_set>


bool containsValue(priority_queue<Node> frontier, Node &node) {
    priority_queue<Node> cFrontier = frontier;
    bool isPresent = false;
    while (!cFrontier.empty()) {
        Node n = cFrontier.top();
        if (n == node) isPresent = true;
        cFrontier.pop();
    }
    return isPresent;
}

Solution SearchAlgorithm::UniformCostSearch(AirRoutePlanning problem) {
    MainHelper helper;
    Solution solution;

    cout << "\nAbout to do Uniform Cost Search on problem: ";

    priority_queue<Node> frontier;
    unordered_set<int> explored;

    Node initNode = Node(problem.getInitialState());
    frontier.push(initNode);

    while (!frontier.empty()) {
        Node node = frontier.top();
        frontier.pop();

        if (problem.goalTest(node.getState())) {
            cout << "Found a solution " << node.getState();
            solution = node.solutionPath();
            return solution;
        } else {
            explored.insert(node.getState());
            cout << "Expanding node: " << node.getState();

            try {
                vector<Route> neighbours = problem.actions(node.getState());

                for (Route route: neighbours) {
                    try {
                        int newState = route.getDestinationAirportId();
                        double pathCost = node.getPathCost() + helper.getDistance(node.getState(), newState);
                        Node child = Node(newState, node, pathCost);
                        if (explored.count(child.getState()) && containsValue(frontier, child)) {
                            frontier.push(child);
                        } else if (containsValue(frontier, child)) {
                            // update the node
                        }
                    } catch (exception& e) {
                        cout << "Exception caught: " << e.what();
                    }
                }
            } catch (exception& e) {
                cout << "Exception caught: " << e.what();
            }
        }
    }
    cout << "No valid route exist!";
    return solution;
}