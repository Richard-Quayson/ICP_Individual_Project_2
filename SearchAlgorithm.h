/**
 * this file implements the uniform cost search algorithm
 * @author Richard Quayson
 */

#ifndef ICP_INDIVIDUAL_PROJECT_C___SEARCHALGORITHM_H
#define ICP_INDIVIDUAL_PROJECT_C___SEARCHALGORITHM_H

#include "AirRoutePlanning.h"
#include "Node.h"
#include "MainHelper.h"
#include "Solution.h"

class SearchAlgorithm {

public:
    static Solution UniformCostSearch(AirRoutePlanning problem);
};

#endif //ICP_INDIVIDUAL_PROJECT_C___SEARCHALGORITHM_H
