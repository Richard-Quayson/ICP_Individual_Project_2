/**
 * Description:
 * this file implements the uniform cost search algorithm
 *
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

    /**
     * Description:
     * this static method partially implements the Uniform Cost Search algorithm
     * @param problem problem object with start and destination airports
     */
    static void UniformCostSearch(AirRoutePlanning problem);
};

#endif //ICP_INDIVIDUAL_PROJECT_C___SEARCHALGORITHM_H
