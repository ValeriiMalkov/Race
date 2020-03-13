cmake_minimum_required(VERSION 3.10)
project(race)

set(CMAKE_CXX_STANDARD 11)


add_executable(race main.cpp
                    Race.cpp
                    Auto.cpp
                    Autobahn.cpp
                    Line.cpp
                    Barrier.cpp
                    Road.cpp
                    Dashboard.cpp
                    Decor.cpp
                    Sensor.cpp
                    SpeedSensor.cpp
                    DistanceSensor.cpp
                    TimeSensor.cpp)
