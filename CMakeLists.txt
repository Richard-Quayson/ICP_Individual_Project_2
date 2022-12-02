cmake_minimum_required(VERSION 3.23)
project(ICP_Individual_Project_C__)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        ICP_Individual_Project_C__ main.cpp
        Airline.cpp Airline.h
        Airport.cpp Airport.h
        Route.cpp Route.h
        Routable.cpp Routable.h
        ReadWriteFile.cpp ReadWriteFile.h
        CreateObjects.cpp CreateObjects.h
        MainHelper.cpp MainHelper.h
        Distance.cpp Distance.h
        AirRoutePlanning.cpp AirRoutePlanning.h
        Node.cpp Node.h
        Solution.cpp Solution.h
        SearchAlgorithm.cpp SearchAlgorithm.h
)