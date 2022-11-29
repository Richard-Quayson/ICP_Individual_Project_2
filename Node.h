/**
 * this file defines operations for the Node class
 * operations include constructor and accessor methods,
 * compareTo, equals, and solutionPath methods
 *
 * @author Richard Quayson
 */

#ifndef ICP_INDIVIDUAL_PROJECT_C___NODE_H
#define ICP_INDIVIDUAL_PROJECT_C___NODE_H

#include "Solution.h"
#include <iostream>
#include <string>
using namespace std;


template<typename Base, typename T>
inline bool instanceof(const T *ptr) {
    return dynamic_cast<const Base*>(ptr) != nullptr;
}

/**
 * the node class extends Comparable to enable the sorting of Node objects
 */
class Node {

private:
    /**
     * instance variables
     */
    int state{};
    Node* parent;
    double pathCost{};

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
    Node(int state, Node parent, double path_cost);

// overloaded constructor
    Node(int state);

    Node (void);

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
 * @return string representation of the f
 */
    string toString();

/**
 * checks if two node objects are equal
 * returns true if the two nodes have the same state
 * @param o the node to compare calling node object with
 * @return boolean
 */
    bool operator== (Node &other) const;


/**
 * returns the Solution of a given node
 * a Solution consists of the state sequence from the
 * initial state to the goal state of a given problem
 * @return Solution
 */
    Solution solutionPath();

///**
// * returns an int based on whether a node has a greater, equal or lower
// * past cost than the node it is being compared with
// * @param node the node to compare calling node object with
// * @return int (1,-1,0)
// */
//    int compareTo(Node node) {
//        return Double.compare(this.getPathCost(), node.getPathCost());
//    }

    bool equals(Node *n);
};


#endif //ICP_INDIVIDUAL_PROJECT_C___NODE_H