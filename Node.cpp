/**
 * Description:
 * this file implements methods defined in the Node.h file
 *
 * @author Richard Quayson
 */

#include "Node.h"

Node::Node(int state, Node *parent, double path_cost) {
    this->state = state;
    this->parent = parent;
    this->pathCost = path_cost;
}

Node::Node(int state) {
    this->state = state;
    this->parent = nullptr;
    this->pathCost = 0.0;
}

int Node::getState() const {
    return state;
}

Node * Node::getParent() {
    return parent;
}

double Node::getPathCost() const {
    return pathCost;
}

string Node::toString() {
    string node;
    if (this->parent != nullptr) {
        node = "Node {";
        node += "state=" + to_string(state);
        node += ", parent=" + to_string(parent->getState());
        node += ", path_cost=" + to_string(pathCost) + "}";
    } else {
        node = "Node { state=" + to_string(state) + "}";
    }

    return node;
}

bool Node::operator== (const Node &other) const {
    return this->state == other.state;
}

Solution Node::solutionPath() {
    vector<int> stateSequence;
    double totalPathCost = this->getPathCost();
    Node *node = this;

    while (node != nullptr) {
        stateSequence.insert(stateSequence.begin(), node->getState());
        node = node->getParent();
    }

    return {stateSequence, totalPathCost};
}

 ICP_INDIVIDUAL_PROJECT_C___NODE_H