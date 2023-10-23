//
// Created by Dmitrii Tarasov on 22/10/2023.
//

#ifndef CPP_ROTORWITHLOG_H
#define CPP_ROTORWITHLOG_H

#include "../abstract/IRotor.h"
#include "../Rotor.h"

class RotorWithLog : public IRotor {
private:
    Rotor rotor;

public:
    RotorWithLog(std::string type, const int position, const int ringRotation): rotor(Rotor::factory(type, position, ringRotation)) {}

    bool madeFullRotation() const override {
        return rotor.madeFullRotation();
    }

    void rotate() override {
        return rotor.rotate();
    }

    void reset() override {
        return rotor.reset();
    }

    int transform(const int input) const override {
        int result = rotor.transform(input);

        std::cout << "Rotor [" << rotor.type << "], position: " << std::to_string(rotor.position + 1) << ", input: " << std::to_string(input) << " (" << Ring::transform(input) << "), output: " << std::to_string(result) << " (" << Ring::transform(result) << ")" << std::endl;

        return result;
    }

    int reverseTransform(int input) const override {
        int result = rotor.reverseTransform(input);

        std::cout << "Rotor [" << rotor.type << "][back], position: " << std::to_string(rotor.position + 1) << ", input: " << std::to_string(input) << " (" << Ring::transform(input) << "), output: " << std::to_string(result) << " (" << Ring::transform(result) << ")" << std::endl;

        return result;
    }
};


#endif //CPP_ROTORWITHLOG_H
