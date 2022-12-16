/**
 * Description:
 * this file implement methods defined in the Route.h file
 *
 * @author Paa Kwasi Kodua
 */
#include "Route.h"

Route::Route(string airlineCode, int airlineId, string sourceAirportCode, int sourceAirportId,
             string destinationAirportCode, int destinationAirportId, string codeShare, int stops,
             string equipment) {
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

string Route::getAirlineCode() {
    return airlineCode;
}

int Route::getAirlineId() const {
    return airlineId;
}

string Route::getSourceAirportCode() {
    return sourceAirportCode;
}

int Route::getSourceAirportId() const {
    return sourceAirportId;
}

string Route::getDestinationAirportCode() {
    return destinationAirportCode;
}

int Route::getDestinationAirportId() const {
    return destinationAirportId;
}

string Route::getCodeShare() {
    return codeShare;
}

int Route::getStops() const {
    return stops;
}

string Route::getEquipment() {
    return equipment;
}

bool Route::isValidRoute() {
    if (getSourceAirportId() != 0 && getDestinationAirportId() != 0)
        return true;
    return false;
}

string Route::toString() {
    string route = "Route {";
    route += "airlineCode = " + getAirlineCode();
    route += ", airlineId = " + to_string(getAirlineId());
    route += ", sourceAirportCode = " + getSourceAirportCode();
    route += ", sourceAirportID = " + to_string(getSourceAirportId());
    route += ", destinationAirportCode = " + getDestinationAirportCode();
    route += ", destinationAirportID = " + to_string(getDestinationAirportId());
    route += ", codeShare = " + getCodeShare();
    route += ", stops = " + to_string(getStops());
    route += ", equipment = " + getEquipment() + "}";

    return route;
}