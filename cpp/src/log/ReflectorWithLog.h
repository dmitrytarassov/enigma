//
// Created by Dmitrii Tarasov on 22/10/2023.
//

#ifndef CPP_REFLECTORWITHLOG_H
#define CPP_REFLECTORWITHLOG_H

#include "iostream"

#include "../abstract/IReflector.h"
#include "../Reflector.h"
#include "../Ring.h"

class ReflectorWithLog : public IReflector {
private:
    Reflector reflector;

public:
    ReflectorWithLog(std::string type): reflector(Reflector::factory(type)) {}

    int reflect(int input) const override {
        int result = reflector.reflect(input);
        std::cout << "Reflector [" << reflector.type << "] input: " << std::to_string(input) << " (" << Ring::transform(input) << "), output: " << std::to_string(result) << " (" << Ring::transform(result) << ")" << std::endl;
        return result;
    }
};


#endif //CPP_REFLECTORWITHLOG_H
