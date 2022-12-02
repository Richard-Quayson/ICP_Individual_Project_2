/**
 * Description:
 * this is the main driver class for the entire program
 * perform function calls to solve a given AirRoutePlanning problem
 *
 * @author Richard Quayson
 */

#include "MainHelper.h"
#include "AirRoutePlanning.h"
#include "SearchAlgorithm.h"

using namespace std;

int main() {

    // instantiate the data
    cout << "Instantiating AirportData" << endl;
    MainHelper::instantiateAirportData();
    cout << "Instantiating AirlineData" << endl;
    MainHelper::instantiateAirlineData();
    cout << "Instantiating RouteData" << endl;
    MainHelper::instantiateRouteData();

    // read the user input file
    string inputFilename = "accra-winnipeg.txt";
    vector<vector<string>> problemData = ReadWriteFile::read(inputFilename);

    // get the source city and country
    vector<string> sourceCityCountry = problemData[0];
    string sourceCity = MainHelper::trim(sourceCityCountry[0]);
    string sourceCountry = MainHelper::trim(sourceCityCountry[1]);
    vector<int> sourceAirportIds = MainHelper::getAirportByCityCountry(sourceCity, sourceCountry);

    // get the destination city and country
    vector<string> destinationCityCountry = problemData[1];
    string destinationCity = MainHelper::trim(destinationCityCountry[0]);
    string destinationCountry = MainHelper::trim(destinationCityCountry[1]);
    vector<int> destinationAirportIds = MainHelper::getAirportByCityCountry(destinationCity, destinationCountry);

    // search for all possible paths between source and destination airports
    for (int sourceAirportId: sourceAirportIds) {
        for (int destinationAirportId: destinationAirportIds) {
            AirRoutePlanning airRouteProblem = AirRoutePlanning(
                    sourceAirportId, destinationAirportId, MainHelper::routeData);
            SearchAlgorithm::UniformCostSearch(airRouteProblem);
        }
    }

    /**
     * Solution variable to store optimal path
     * Criteria: (Solution object with the lowest path cost)
     */

    Solution optimalPath;

    if (MainHelper::validPaths.size() == 1) {
        optimalPath = MainHelper::validPaths[0];
    }

    for (const Solution& validPath : MainHelper::validPaths) {
        if (validPath.getPathCost() < optimalPath.getPathCost()) {
            optimalPath = validPath;
        }
    }

    string outputFilename = R"(C:\Users\richard.quayson\OneDrive - Ashesi University\Desktop\ICP_Individual_Project_C++\accra-winnipeg-output.txt)";
    string data = optimalPath.createSolutionString();
    ReadWriteFile::write(outputFilename, data);

    cout << "Processing Complete!" << endl;

    /**
     * uncomment to test extremeCases
     */

//    CreateObjects::printExtremeAirportCases();

	return 0;
}