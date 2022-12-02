/**
 * Description:
 * this file defines operations needed for the main method
 * operations include, instantiating a hashMap for the
 * airport data, airline data, and route data
 * methods also include getAirportByCityCountry, getDistance
 *
 * @author Richard Quayson
 */

#ifndef ICP_INDIVIDUAL_PROJECT_C___MAINHELPER_H
#define ICP_INDIVIDUAL_PROJECT_C___MAINHELPER_H

#include "Airport.h"
#include "Airline.h"
#include "Route.h"
#include "Solution.h"
#include "ReadWriteFile.h"
#include "CreateObjects.h"
#include "Distance.h"
#include <vector>
#include <unordered_map>
using namespace std;

class MainHelper {
public:

    /**
     * Description:
     * unordered map to store information from airport file
     * key: airportId
     * value: Airport object
     */
    static unordered_map<int, Airport> airportData;

    /**
     * Description:
     * unordered map to store information from airline file
     * key: airlineCode
     * value: Airline object
     */
    static unordered_map<int, Airline> airlineData;

    /**
     * Description:
     * unordered map to store information from route file
     * key: sourceAirportId
     * value: vector of route objects with that sourceAirportId (vector<Route>)
     */
    static unordered_map<int, vector<Route>> routeData;

    /**
     * Description:
     * vector to store Solution objects (source: Solution.h)
     * stores all valid Solution path found for a given start and destination airports
     */
    static vector<Solution> validPaths;

    /**
     * Description:
     * this method takes a word and strip it of all white spaces
     *
     * @param word
     * @return string
     */
    static string trim(string& word);

    /**
     * Description:
     * this static method reads the airport file, create objects of them
     * and store the airport ID as key and the entire airport object
     * as the value in the airportData unordered_map
     */
    static void instantiateAirportData();

    /**
     * Description:
     * this static method reads the airline file, create objects of them
     * and store the airline ID as key and the entire airline object
     * as the value in the airlineData unordered_map
     */
    static void instantiateAirlineData();

    /**
     * Description:
     * this static method reads the airport file, create objects of them
     * and store them in the routeData unordered_map
     */
    static void instantiateRouteData();

    /**
     * Description:
     * returns a vector of airport Ids whose city and location
     * equals the city and location provided as arguments
     *
     * @param city the city the airport is in
     * @param country the country the airport is in
     * @return vector<int>
     */
    static vector<int> getAirportByCityCountry(const string& city, const string& country);

    /**
     * Description:
     * returns the distance between two airports
     * using the haversine formula implemented in the Distance class
     *
     * @param sourceAirportID the airport ID of the source
     * @param destinationAirportID the airport ID of the destination
     * @return double (distance in km)
     */
    static double getDistance(int sourceAirportId, int destinationAirportId);
};

#endif //ICP_INDIVIDUAL_PROJECT_C___MAINHELPER_H