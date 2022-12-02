/**
 * Description:
 * this file implements methods defined in the ReadWriteFile.h file
 *
 * @author Richard Quayson
 */

#include "ReadWriteFile.h"
#include "CreateObjects.h"
#include <fstream>
#include <string>
#include <sstream>
using namespace std;


vector<vector<string>> ReadWriteFile::read(const string& filename) {
    vector<vector<string>> stringVector;
//    vector<vector<string>> extremeCases;
    vector<string> row;
    string line, word, temp;

    fstream file;
    file.open(filename,ios::in);

    if (file.fail()) {
        cout << "Could not open the file " << filename << endl;
    }

    // split on a newline character
    while (getline(file,line)) {
        row.clear();
        stringstream s(line);

        // split on a comma
        while(getline(s, word, ',')){
            row.push_back(word);
        }
        /*
            this if condition applies for the airports.csv file,
            where we check for extra commas in the various columns
            if there are extra commas, gracefully handle it
         */
        if (row.size() > 14) {
//            extremeCases.push_back(row);
            vector<string> newRow = CreateObjects::gracefullyHandleAirportObjectCreation(row);
            stringVector.push_back(newRow);
        } else {
            stringVector.push_back(row);
        }
    }
    file.close();
    return stringVector;
//    return extremeCases;
}

void ReadWriteFile::write(const string& filename, const string& data) {
    ofstream outputFile(filename);

    if (outputFile.fail()) {
        cout << "Could not open " << filename << " for writing!" << endl;
    }
    outputFile << data;

    outputFile.close();
}