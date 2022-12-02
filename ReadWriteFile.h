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

    /**
     * reads a given file and returns a vector<vector<string>>
     * with each vector<string> representing information on a line (row)
     * @param filename the name of the file to be read
     * @return vector<vector<string>>
     */
    static vector<vector<string>> read(const string& filename);

    /**
     * write to the given file the data provided
     * @param filename the name of the file to write into
     * @param data the data to be written to the file
     */
    static void write(const string& filename, const string& data);
};

#endif //ICP_INDIVIDUAL_PROJECT_C___READWRITEFILE_H