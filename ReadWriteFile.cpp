
#include "ReadWriteFile.h"
#include <fstream>
#include <string>
#include <sstream>
using namespace std;


vector<string> split(const string&, char delimeter) {
    vector<string> lineVector;
    string column;
    istringstream lineStream;

    while (getline(lineStream, column, delimeter)) {
        lineVector.push_back((column));
    }

    return lineVector;
}


//void strip(std::string& str) {
//    if (str.length() == 0) {
//        return;
//    }
//
//    auto start_it = str.begin();
//    auto end_it = str.rbegin();
//    while (std::isspace(*start_it)) {
//        ++start_it;
//        if (start_it == str.end()) break;
//    }
//    while (std::isspace(*end_it)) {
//        ++end_it;
//        if (end_it == str.rend()) break;
//    }
//    int start_pos = start_it - str.begin();
//    int end_pos = end_it.base() - str.begin();
//    str = start_pos <= end_pos ? std::string(start_it, end_it.base()) : "";
//}


vector<vector<string>> ReadWriteFile::read(string filename) {
    vector<vector<string>> stringVector;
    vector<string> rows;
    string line;

    fstream file(filename, ios::in);
    if (file.fail()) {
        cout << "Could not open the file";
    }

    if (file.is_open()) {
        while (getline(file, line)) {
            rows.clear();
            istringstream str(line);
//            cout << line << endl;
//
//            for (char st : line) {
//                cout << st;
//            }
            /*while (getline(str, word, ","))
                row.push_back(word);*/
            stringVector.push_back(rows);

            for (const string& row : rows) {
                stringVector.push_back(split(row, ','));
            }
        }
    }
    file.close();
    return stringVector;
}