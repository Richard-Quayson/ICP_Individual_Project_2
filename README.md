# ICP_Project_2: AirRouteFinder
This project uses the uniform cost search algorithm to find the shortest route between 
airports from a source airport to a destination airport. The optimality criteria for the
uniform cost search algorithm is the distance between airports, computed using the [Haversine
formula.](https://en.wikipedia.org/wiki/Haversine_formula)

## Usage
To run the program, create a new txt file in the cmake-build-debug folder, with the source and
destination cities and countries. For example:
```
London, United Kingdom
Madrid, Spain
```

Afterwards, change the input filename in the main.cpp file to the name of the new file created
and provide a new output filename.
```C++

// assuming the filename is "london-madrid.txt"
// change inputFilename to the new filename
string inputFilename = "london-madrid.txt";
vector<vector<string>> problemData = ReadWriteFile::read(inputFilename);

// provide a new output filename
string outputFilename = R"(C:\Users\richard.quayson\OneDrive - Ashesi University\Desktop\ICP_Individual_Project_C++\london-madrid-output.txt)";
string data = optimalPath.createSolutionString();
ReadWriteFile::write(outputFilename, data);
```

Afterwards, build and run the program. After "Processing complete!" is printed to the console,
the output file will be available in the main project folder.

## Program Overview:
For an overview on the project, review the project reflection files in the cmake-build-debug folder
where explanations on the flow of the program is given and decision decisions are discussed. 
