cmake_minimum_required(VERSION 3.20)
project(hw3_new)

set(CMAKE_CXX_STANDARD 11)

add_executable(hw3_new main.cpp
        SimObject.cpp SimObject.h
        Warehouse.cpp Warehouse.h
        Controller.cpp Controller.h
        Model.cpp Model.h
        Validation.cpp Validation.h
        Vehicle.cpp Vehicle.h
        Truck.cpp Truck.h
        Time.h
        Functions.cpp Functions.h)
