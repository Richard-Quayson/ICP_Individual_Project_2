

#ifndef ICP_INDIVIDUAL_PROJECT_C___AIRLINE_H
#define ICP_INDIVIDUAL_PROJECT_C___AIRLINE_H

#include <iostream>
using namespace std;

class Airline {

private:
    /*
        Instance variables
    */
    int airlineId;
    string airlineName;
    string alias;
    string iataCode;
    string icaoCode;
    string callSign;
    string country;
    string activeStatus;

public:
    /*
        Constructor:
        Defines a method for building and initialising objects of the Airline class

        @param airlineID the unique openFlights identifier for the airline
        @param airlineName the name of the airline
        @param alias the alias of the airline
        @param IATACode 2-letter IATACode for the airline
        @param ICAOCode 3-letter ICAOCode for the airline
        @param callSign the airline call sign
        @param country the country where the airport is located
        @param activeStatus "Y" if the airline is or has until recently been operational, "N" if defunct
    */
    Airline(int airlineId, string airlineName, string alias, string iataCode,
            string icaoCode, string callSign, string country, string activeStatus);


    /*
        returns the airlineId of an Airline object
        @return airlineId
    */
    int getAirlineId();


    /*
        returns the name of the airline
        @return airlineName
     */
    string getAirlineName();


    /*
        returns the alias of an airline
        @return alias
    */
    string getAlias();


    /*
        returns the IATACode of the airline
        @return IataCode
     */
    string getIataCode();


    /*
        returns the ICAOCode of the airline
        @return IcaoCode
     */
    string getIcaoCode();


    /*
        returns the callSign value of an airline object
        @return callSign
    */
    string getCallSign();


    /*
        returns the name of the country where the airline is operational
        @return country
     */
    string getCountry();


    /*
        returns whether the airline has been operational recently, Y/N
        @return activeStatus
     */
    string getActiveStatus();

    /*
        returns the attributes of a given airline object
        @return the string representation of all the attributes of an airline object
    */
    string toString();
};


#endif //ICP_INDIVIDUAL_PROJECT_C___AIRLINE_H
