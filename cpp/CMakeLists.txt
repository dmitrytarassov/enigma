cmake_minimum_required(VERSION 3.26)
project(cpp)

set(CMAKE_CXX_STANDARD 20)

set(COMMON_SOURCES
    Rotor.cpp
    Enigma.cpp
    Reflector.cpp
    Commutator.cpp
    Log.cpp
    Ring.cpp
    log/ReflectorWithLog.cpp
    abstract/IReflector.cpp
    abstract/IRotor.cpp
    log/RotorWithLog.cpp
)

add_executable(cpp main.cpp ${COMMON_SOURCES})
add_executable(debug debug.cpp ${COMMON_SOURCES})
