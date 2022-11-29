
#include "CreateObjects.h"
#include <exception>

Airport CreateObjects::createAirportObject(vector<string> airportVector) {

    int airportId = 0;
    double latitude = 0.0;
    double longitude = 0.0;
    double altitude = 0.0;
    double timeZone = 0.0;

    try {
        airportId = stoi(airportVector[0]);
        latitude = stod(airportVector[6]);
        longitude = stod(airportVector[7]);
        altitude = stod(airportVector[8]);
        timeZone = stod(airportVector[9]);

    } catch (bad_cast& bc) {
        cerr << "NumberFormatException caught: " << bc.what();
        cerr << "Argument must be a number";
    } catch (exception& e) {
        cout << e.what();
    }

    string airportName = airportVector[1];
    string city = airportVector[2];
    string country = airportVector[3];
    string IATACode = airportVector[4];
    string ICAOCode = airportVector[5];
    string DST = airportVector[10];
    string Tz = airportVector[11];
    string type = airportVector[12];
    string sourceOfData = airportVector[13];

    return {airportId, airportName, city, country,
            IATACode, ICAOCode, latitude, longitude,
            altitude, timeZone, DST, Tz, type, sourceOfData};
}



void CreateObjects::printExtremeAirportCases() {
    vector<vector<string>> results = ReadWriteFile::read("ICP_Individual_Project/src/airports.csv");
    cout << "Number of Extreme cases: " << results.size();
    for (const vector<string>& resultVector: results) {
        for (const string& attribute: resultVector) {
            cout << attribute << " ";
        }
        cout << "\n";
    }
}


vector<string> CreateObjects::gracefullyHandleAirportObjectCreation(vector<string> stringAirportVector) {

    vector<string> newStringVector;

    if (stringAirportVector[0] == "5562" || stringAirportVector[0] == "5674" ||
    stringAirportVector[0] == "5675" || stringAirportVector[0] == "5881") {

        string airportID = stringAirportVector[0];
        string airportName = stringAirportVector[1];
        string city = stringAirportVector[2] + stringAirportVector[3];
        string country = stringAirportVector[4];
        string IATACode = stringAirportVector[5];
        string ICAOCode = stringAirportVector[6];
        string latitude = stringAirportVector[7];
        string longitude = stringAirportVector[8];
        string altitude = stringAirportVector[9];
        string timeZone = stringAirportVector[10];
        string DST = stringAirportVector[11];
        string Tz = stringAirportVector[12];
        string type = stringAirportVector[13];
        string sourceOfData = stringAirportVector[14];

        newStringVector = {airportID, airportName, city, country, IATACode, ICAOCode,
                           latitude, longitude, altitude, timeZone, DST, Tz, type, sourceOfData};
        } else {
        string airportID = stringAirportVector[0];
        string airportName = stringAirportVector[1] + stringAirportVector[2];
        string city = stringAirportVector[3];
        string country = stringAirportVector[4];
        string IATACode = stringAirportVector[5];
        string ICAOCode = stringAirportVector[6];
        string latitude = stringAirportVector[7];
        string longitude = stringAirportVector[8];
        string altitude = stringAirportVector[9];
        string timeZone = stringAirportVector[10];
        string DST = stringAirportVector[11];
        string Tz = stringAirportVector[12];
        string type = stringAirportVector[13];
        string sourceOfData = stringAirportVector[14];

        newStringVector = {airportID, airportName, city, country, IATACode, ICAOCode,
                           latitude, longitude, altitude, timeZone, DST, Tz, type, sourceOfData};
    }

    return newStringVector;
}


Airline CreateObjects::createAirlineObject(vector<string> airlineVector) {
    int airlineId = 0;
    try {
        airlineId = stoi(airlineVector[0]);
    } catch (bad_cast& bc) {
        cout << "NumberFormatException caught: " << bc.what() << endl;
        cout << "Argument must be an int." << endl;
    } catch (exception& e) {
        cout << e.what();
    }

    string airlineName = airlineVector[1];
    string alias = airlineVector[2];
    string IATACode = airlineVector[3];
    string ICAOCode = airlineVector[4];
    string callSign = airlineVector[5];
    string country = airlineVector[6];
    string activeStatus = airlineVector[7];

    return {airlineId, airlineName, alias, IATACode,
            ICAOCode, callSign, country, activeStatus};
}


Route CreateObjects::createRouteObject(vector<string> routeVector) {

    int airlineID = 0;
    int sourceAirportID = 0;
    int destinationAirportID = 0;
    int stops = 0;

    try {
        airlineID = stoi(routeVector[1]);
        sourceAirportID = stoi(routeVector[3]);
        destinationAirportID = stoi(routeVector[5]);
        stops = stoi(routeVector[7]);
    } catch (bad_cast& bc) {
        cout << "NumberFormatException caught: " << bc.what() << endl;
        cout << "Argument must be an int." << endl;
    } catch (range_error& re) {
        cout << "Index out of bounds exception caught: " << re.what() << endl;
    } catch (exception& e) {
        cout << e.what();
    }

    string airlineCode = routeVector[0];
    string sourceAirportCode = routeVector[2];
    string destinationAirportCode = routeVector[4];
    string codeShare = routeVector[6];
    string equipment = routeVector[routeVector.size() - 1];

    return {airlineCode, airlineID, sourceAirportCode, sourceAirportID,
            destinationAirportCode, destinationAirportID, codeShare, stops, equipment};
}