

#include "Airport.h"

Airport::Airport(int airportId, string aiportName, string city, string country, string iataCode,
                 string icaoCode, double latitude, double longitude, double altitude, double timeZone,
                 string dst, string tz, string type, string sourceOfData) {
    this->airportId = airportId;
    this->airportName = airportName;
    this->city = city;
    this->country = country;
    this->iataCode = iataCode;
    this->icaoCode = icaoCode;
    this->latitude = latitude;
    this->longitude = longitude;
    this->altitude = altitude;
    this->timeZone = timeZone;
    this->dst = dst;
    this->tz = tz;
    this->type = type;
    this->sourceOfData = sourceOfData;
}

int Airport::getAirportId() {
    return airportId;
}

string Airport::getAirportName() {
    return airportName;
}

string Airport::getCity() {
    return city;
}

string Airport::getCountry() {
    return country;
}

string Airport::getIataCode() {
    return iataCode;
}

string Airport::getIcaoCode() {
    return icaoCode;
}

double Airport::getLatitude() {
    return latitude;
}

double Airport::getLongitude() {
    return longitude;
}

double Airport::getAltitude() {
    return altitude;
}

double Airport::getTimeZone() {
    return timeZone;
}

string Airport::getDST() {
    return dst;
}

string Airport::getTZ() {
    return tz;
}

string Airport::getType() {
    return type;
}

string Airport::getSourceOfData() {
    return sourceOfData;
}

string Airport::toString() {
    string airport = "Airport {";
    airport += "airportId = " + getAirportId();
    airport += ", airportName = " + getAirportName();
    airport += ", city = " + getCity();
    airport += ", country = " + getCountry();
    airport += ", IATACode = " + getIataCode();
    airport += ", ICAOCode = " + getIcaoCode();
    airport += ", latitude = " + to_string(getLatitude());
    airport += ", longitude = " + to_string(getLongitude());
    airport += ", altitude = " + to_string(getAltitude());
    airport += ", timezone = " + to_string(getTimeZone());
    airport += ", DST = " + getDST();
    airport += ", Tz = " + getTZ();
    airport += ", type = " + getType();
    airport += ", sourceOfData = " + getSourceOfData() + "}";

    cout << airport;
    return airport;
}