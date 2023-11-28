cmake_minimum_required(VERSION 3.26)
project(cpp)

set(CMAKE_CXX_STANDARD 20)

set(COMMON_SOURCES
        src/Rotor.cpp
        src/Enigma.cpp
        src/Reflector.cpp
        src/Commutator.cpp
        src/Ring.cpp
        src/log/ReflectorWithLog.cpp
        src/abstract/IReflector.cpp
        src/abstract/IRotor.cpp
        src/log/RotorWithLog.cpp
)

add_executable(main main.cpp ${COMMON_SOURCES})
add_executable(debug debug.cpp ${COMMON_SOURCES})
