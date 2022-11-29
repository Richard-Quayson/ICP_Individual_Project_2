
#ifndef ICP_INDIVIDUAL_PROJECT_C___CREATEOBJECTS_H
#define ICP_INDIVIDUAL_PROJECT_C___CREATEOBJECTS_H

#include "Airport.h"
#include "Airline.h"
#include "Route.h"
#include "ReadWriteFile.h"
#include <vector>
#include <string>


class CreateObjects {

public:
    /**
     * takes a String array representation of the attributes
     * of an airport object, creates and returns an Airport object
     *
     * @param airportVector String array containing the attribute info for an airport object
     * @return Airport object (instance)
     */
    static Airport createAirportObject(vector<string> airportVector);

    /**
    * prints the number of extreme cases in the airport CSV file and the results for later cleanup
    * (an extreme case is a case of extra comma(s) in any of the field and is identified by the
    * length of string array after splitting a row (on commas) in the airports.csv file.
    * a normal airport object is expected to have an array length of 14,
    * if more, then it contains extra commas and is regarded as extreme)
    *
    * (to test this,
    * uncomment the extremeCases array and return it in the readFile method of the readWriteFile class)
    *
    * this method resulted in the creation of the gracefullyHandleAirportObjectCreation
    */
    static void printExtremeAirportCases();

    /**
     * printExtremeAirportCases returned:
     * extreme cases in airport name (extra commas in the airport name)
     * airportID: 641, 657, 658, 664, 3256, 3340, 4345, 4351, 5582, 5583, 5589, 6898, 13714
     *
     * extreme cases in city (extra commas in the city)
     * airportID: 5562, 5674, 5675, 5881
     *
     * this method relies on the information above to handle the extra commas
     * if extreme case in airportName, add the next value after airportName to value at airportName index
     * if extreme case in city, add the next value after city to value at city index
     *
     * @param stringAirportVector a String array representation of an extreme case
     * @return newStringVector (the cleaned-up array of the extreme case)
     */
    static vector<string> gracefullyHandleAirportObjectCreation(vector<string> stringAirportVector);

    /**
     * takes a String array representation of the attributes
     * of an airline object, creates and returns an Airline object
     *
     * @param airlineVector a String array containing the attributes' info for an airline object
     * @return Airline object (instance)
     */
    static Airline createAirlineObject(vector<string> airlineVector);

    /**
     * takes a String array representation of the attributes
     * of a route object, creates and returns a route object
     *
     * @param routeVector String array containing the attributes' info for a route object
     * @return Route object (instance)
     */
    static Route createRouteObject(vector<string> routeVector);
};

#endif //ICP_INDIVIDUAL_PROJECT_C___CREATEOBJECTS_H
