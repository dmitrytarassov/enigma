//
// Created by Dmitrii Tarasov on 16/10/2023.
//

#ifndef CPP_LOG_H
#define CPP_LOG_H

#include "iostream"
#include "Rotor.h"

class Log {


public:
    static void log(std::string name, std::string type, char in, char out, bool isForward) {
        std::cout << name << " " << type << ": " << in << (isForward ? " -> " : " <- ") << out << std::endl;
    }
};


#endif //CPP_LOG_H
