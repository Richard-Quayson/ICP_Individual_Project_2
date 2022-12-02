/**
 * Description:
 * this file defines operations for the Node class
 * operations include constructor and accessor methods,
 * operator == (equals method), and solutionPath method
 *
 * @author Richard Quayson
 */

#ifndef ICP_INDIVIDUAL_PROJECT_C___NODE_H
#define ICP_INDIVIDUAL_PROJECT_C___NODE_H

#include "Solution.h"
#include <iostream>
#include <string>
using namespace std;

class Node {
private:
    /**
     * instance variables
     */
    int state;
    Node* parent;
    double pathCost;

public:
    /**
     * Constructor:
     * Build and initialise the objects of the Node class
     *
     * @param state AirportID
     * @param parent node object of the calling object
     * @param action AirportID
     * @param path_cost distance between the state of the calling Node and this node's state
     */
    Node(int state, Node *parent, double path_cost);

    // overloaded constructor
    explicit Node(int state);

    /**
     * returns the state of this node object
     * @return this.state
     */
    int getState() const;

    /**
     * returns the parent node of this node object
     * @return this.parent
     */
    Node * getParent();

    /**
     * returns the path cost of this node object
     * @return this.pathCost
     */
    double getPathCost() const;

    /**
     * returns the string representation of a node class
     * @return string
     */
    string toString();

    /**
     * checks if two node objects are equal
     * returns true if the two nodes have the same state
     * @param other the node to compare calling node object with
     * @return boolean
     */
    bool operator== (const Node &other) const;

    /**
     * returns the Solution of a given node
     * a Solution consists of the state sequence from the
     * initial state to the goal state of a given problem
     * and the path cost (distance between start and destination in km)
     *
     * @return Solution object
     */
    Solution solutionPath();
};

#endif //ICP_INDIVIDUAL_PROJECT_C___NODE_H