/**
 * Description:
 * this file defines operations for the Airport class
 * operations include the constructor and accessor methods
 *
 * @author Paa Kwasi Kodua
 */

#ifndef ICP_INDIVIDUAL_PROJECT_C___AIRPORT_H
#define ICP_INDIVIDUAL_PROJECT_C___AIRPORT_H

#include <iostream>
#include <string>
using namespace std;

class Airport {

private:
    /**
     * Instance variables
    */
    int airportId;
    string airportName;
    string city;
    string country;
    string iataCode;
    string icaoCode;
    double latitude;
    double longitude;
    double altitude;
    double timeZone;
    string dst;
    string tz;
    string type;
    string sourceOfData;

public:
    /**
     * Constructor:
        Defines a method for building and initialising objects of the Airline class

        @param airportId the unique openFlights identifier for the airport
        @param airportName name of the airport
        @param city main city served by the airport
        @param country the country where the airport is located
        @param iataCode International Air Transport Association 3-letter code for the airport
        @param icaoCode International Civil Aviation Organization 4-letter code for tha airport
        @param latitude airport's latitude position in degrees
        @param longitude airport's longitude position in degrees
        @param altitude airport's altitude in feet
        @param timeZone hours offset from UTC
        @param dst Daylight Savings Time
        @param tz timeZone
        @param type the type of the airport
        @param sourceOfData source of this data
    */
    Airport(int airportId, string airportName, string city, string country, string iataCode,
            string icaoCode, double latitude, double longitude, double altitude, double timeZone,
            string dst, string tz, string type, string sourceOfData);


    /**
     * returns a string representation of the attributes of an Airport object
        @return attributes of the Airport object
     */
    string toString();

    /**
     * returns the airport's Id
        @return airportId
     */
    int getAirportId();

    /*
        returns the airport's name
        @return airportName
     */
    string getAirportName();

    /**
        returns the main city served by the airport
        @return city
     */
    string getCity();

    /**
        returns the country where the airport is located
        @return country
     */
    string getCountry();

    /**
        returns the International Air Transport Association code for the airport
        @return iataCode
     */
    string getIataCode();

    /**
        returns the International Civil Aviation Organization code for tha airport
        @return icaoCode
     */
    string getIcaoCode();

    /**
        returns the airport's latitude position in degrees
        @return latitude
     */
    double getLatitude() const;

    /**
        returns the airport's longitude position in degrees
        @return longitude
     */
    double getLongitude() const;

    /**
        returns the airport's altitude
        @return altitude
    */
    double getAltitude() const;

    /**
        returns the timeZone hours offset from UTC
        @return timeZone
    */
    double getTimeZone() const;

    /**
        returns the Daytime Savings Time of an Airport
        @return dst
    */
    string getDST();

    /**
        returns the airport's tz
        @return tz
    */
    string getTZ();

    /**
        returns the airport's type
        @return type
    */
    string getType();

    /**
        returns the source of the data
        @return sourceOfData
    */
    string getSourceOfData();
};

#endif //ICP_INDIVIDUAL_PROJECT_C___AIRPORT_H