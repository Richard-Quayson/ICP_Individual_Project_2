
#include "Route.h"

Route::Route(string airlineCode, int airlineId, string sourceAirportCode, int sourceAirportId,
             string destinationAirportCode, int destinationAirportId, string codeShare, int stops, string equipment) {
    this->airlineCode = airlineCode;
    this->airlineId = airlineId;
    this->sourceAirportCode = sourceAirportCode;
    this->sourceAirportId = sourceAirportId;
    this->destinationAirportCode = destinationAirportCode;
    this->destinationAirportId = destinationAirportId;
    this->codeShare = codeShare;
    this->stops = stops;
    this->equipment = equipment;
}

/**
 * returns the airline's code
 * @return this.airlineCode
 */
string Route::getAirlineCode() {
    return airlineCode;
}

/**
 * returns the airline's ID
 * @return
 */
int Route::getAirlineId() {
    return airlineId;
}

/**
 * returns the airport code of the source airport
 * @return this.sourceAirportCode
 */
string Route::getSourceAirportCode() {
    return sourceAirportCode;
}

/**
 * returns the airport ID of the source airport
 * @return this.sourceAirportID
 */
int Route::getSourceAirportId() {
    return sourceAirportId;
}

/**
 * returns the airport code of the destination airport
 * @return this.destinationAirportCode
 */
string Route::getDestinationAirportCode() {
    return destinationAirportCode;
}

/**
 * returns the airport ID of the destination airport
 * @return this.destinationAirportID
 */
int Route::getDestinationAirportId() {
    return destinationAirportId;
}

/**
 * returns the codeshare of a route object
 * @return codeShare
 */
string Route::getCodeShare() {
    return codeShare;
}

/**
 * returns the number of stops the airline will make before reaching the destination airport
 * @return this.stops
 */
int Route::getStops() {
    return stops;
}

/*
    returns the number of stops the airline will make before reaching the destination airport
    @return this.stops
 */
string Route::getEquipment() {
    return equipment;
}

/*
    implements the isValidRoute method of the Routable interface
    and returns whether a given route is valid
    @return boolean
 */
bool Route::isValidRoute() {
    if (getSourceAirportId() != 0 && getDestinationAirportId() != 0)
        return true;
    return false;
}

/*
    returns the attributes of a given route
    @return string representation of all attributes of a route object
 */
string Route::toString() {
    string route = "Route {";
    route += "airlineCode = " + getAirlineCode();
    route += ", airlineId = " + getAirlineId();
    route += ", sourceAirportCode = " + getSourceAirportCode();
    route += ", sourceAirportID = " + getSourceAirportId();
    route += ", destinationAirportCode = " + getDestinationAirportCode();
    route += ", destinationAirportID = " + getDestinationAirportId();
    route += ", codeShare = " + getCodeShare();
    route += ", stops = " + getStops();
    route += ", equipment = " + getEquipment() + "}";

    return route;
}