
/**
 * this file defines operations for the readWriteFile class
 * operations include a readFile and writeFile class
 * which read and write to a file respectively
 *
 * @author Richard Quayson
 */

#ifndef ICP_INDIVIDUAL_PROJECT_C___READWRITEFILE_H
#define ICP_INDIVIDUAL_PROJECT_C___READWRITEFILE_H

#include <iostream>
#include <vector>
using namespace std;

class ReadWriteFile {

public:
    static vector<vector<string>> read(string filename);

};

#endif //ICP_INDIVIDUAL_PROJECT_C___READWRITEFILE_H