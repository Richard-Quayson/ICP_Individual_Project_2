
#ifndef ICP_INDIVIDUAL_PROJECT_C___ROUTE_H
#define ICP_INDIVIDUAL_PROJECT_C___ROUTE_H

#include <iostream>
#include "Routable.h"
using namespace std;

class Route: public Routable {

    /*
        Instance variables
     */
private:
    string airlineCode;
    int airlineId;
    string sourceAirportCode;
    int sourceAirportId;
    string destinationAirportCode;
    int destinationAirportId;
    string codeShare;
    int stops;
    string equipment;

public:
    /**
     * Constructor:
     * Build and initialise the objects of the Route class
     *
     * @param airlineCode 2-letter IATACode or 3-letter ICAOCode of the airline
     * @param airlineID the unique openFlights identifier for the airline
     * @param sourceAirportCode 3-letter IATACode or 4-letter ICAOCode of the source airport
     * @param sourceAirportID the unique openFlights identifier for the source airport
     * @param destinationAirportCode 3-letter IATACode or 4-letter ICAOCode of the destination airport
     * @param destinationAirportID the unique openFlights identifier for the destination airport
     * @param codeShare "Y" if this flight is not operated by ICP_Individual_Project.Airline, but another carrier
     * @param stops the number of stops on this flight ("0" for direct flight)
     * @param equipment 3-letter codes for plane type(s) generally used on this flight
     */
    Route(string airlineCode, int airlineId, string sourceAirportCode, int sourceAirportId,
          string destinationAirportCode, int destinationAirportId, string codeShare, int stops, string equipment);

    /**
     * returns the airline's code
     * @return this.airlineCode
     */
    string getAirlineCode();

    /**
     * returns the airline's ID
     * @return
     */
    int getAirlineId();

    /**
     * returns the airport code of the source airport
     * @return this.sourceAirportCode
     */
    string getSourceAirportCode();

    /**
     * returns the airport ID of the source airport
     * @return this.sourceAirportID
     */
    int getSourceAirportId();

    /**
     * returns the airport code of the destination airport
     * @return this.destinationAirportCode
     */
    string getDestinationAirportCode();

    /**
     * returns the airport ID of the destination airport
     * @return this.destinationAirportID
     */
    int getDestinationAirportId();

    /**
     * returns the codeshare of a route object
     * @return codeShare
     */
    string getCodeShare();

    /**
     * returns the number of stops the airline will make before reaching the destination airport
     * @return this.stops
     */
    int getStops();

    /*
        returns the number of stops the airline will make before reaching the destination airport
        @return this.stops
     */
    string getEquipment();

    /*
        implements the isValidRoute method of the Routable interface
        and returns whether a given route is valid
        @return boolean
     */
    bool isValidRoute() override;

    /*
        returns the attributes of a given route
        @return string representation of all attributes of a route object
     */
    string toString();
};

#endif //ICP_INDIVIDUAL_PROJECT_C___ROUTE_H
