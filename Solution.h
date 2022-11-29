
#ifndef ICP_INDIVIDUAL_PROJECT_C___SOLUTION_H
#define ICP_INDIVIDUAL_PROJECT_C___SOLUTION_H

#include <vector>
using namespace std;

class Solution {
private:
    vector<int> stateSequence;
    double pathCost;

public:
    Solution();
    Solution(vector<int> stateSequence, double pathCost);

    vector<int> getStateSequence();
    double getPathCost() const;
};


#endif //ICP_INDIVIDUAL_PROJECT_C___SOLUTION_H
