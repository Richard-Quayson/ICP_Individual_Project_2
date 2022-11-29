
#include "MainHelper.h"
#include "AirRoutePlanning.h"
#include "SearchAlgorithm.h"

using namespace std;

int main() {

    MainHelper helper;

    helper.instantiateAirportData();
    helper.instantiateAirlineData();
    helper.instantiateRouteData();

    vector<Solution> validPaths;
    vector<int> sourceAirportIds = helper.getAirportByCityCountry("Accra", "Ghana");
    vector<int> destinationAirportIds = helper.getAirportByCityCountry("Winnipeg", "Canada");

    for (int sourceAirportId: sourceAirportIds) {
        for (int destinationAirportId: destinationAirportIds) {
            AirRoutePlanning airRouteProblem = AirRoutePlanning(
                    sourceAirportId, destinationAirportId, MainHelper::routeData);
            Solution validPath = SearchAlgorithm::UniformCostSearch(airRouteProblem);

            if (&validPath != nullptr) {
                validPaths.push_back(validPath);
            }
        }
    }

	return 0;
}