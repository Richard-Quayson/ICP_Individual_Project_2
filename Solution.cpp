
#include "Solution.h"
#include <utility>

Solution::Solution() {}

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