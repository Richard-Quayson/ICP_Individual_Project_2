/**
 * Description:
 * this class implements the methods defined in the Airline.h file
 *
 * @author Paa Kwasi Kodua
 */

#include "Airline.h"


Airline::Airline(int airlineId, string airlineName, string alias, string iataCode,
                 string icaoCode, string callSign, string country, string activeStatus) {
    this->airlineId = airlineId;
    this->airlineName = airlineName;
    this->alias = alias;
    this->iataCode = iataCode;
    this->icaoCode = icaoCode;
    this->callSign = callSign;
    this->country = country;
    this->activeStatus = activeStatus;
}

int Airline::getAirlineId() const {
    return airlineId;
}

string Airline::getAirlineName() {
    return airlineName;
}

string Airline::getAlias() {
    return alias;
}

string Airline::getIataCode() {
    return iataCode;
}

string Airline::getIcaoCode() {
    return icaoCode;
}

string Airline::getCallSign() {
    return callSign;
}

string Airline::getCountry() {
    return country;
}

string Airline::getActiveStatus() {
    return activeStatus;
}

string Airline::toString() {
    string airline = "Airline {";
    airline += ", airlineId = " + to_string(getAirlineId());
    airline += ", alias = " + getAlias();
    airline += ", iataCode = " + getIataCode();
    airline += ", icaoCode = " + getIcaoCode();
    airline += ", callSign = " + getCallSign();
    airline += ", country = " + getCountry();
    airline += ", activeStatus = " + getActiveStatus() + "}";

    return airline;
}