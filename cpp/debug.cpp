#include <iostream>
#include <string>
#include <algorithm>

#include "Enigma.h"
#include "Commutator.h"
#include "Ring.h"
#include "log/ReflectorWithLog.h"
#include "log/RotorWithLog.h"

int main() {
    std::unique_ptr<IRotor> rotor3 = std::make_unique<RotorWithLog>(RotorWithLog("III", 12, 22));
    std::unique_ptr<IRotor> rotor2 = std::make_unique<RotorWithLog>(RotorWithLog("I", 2, 13));
    std::unique_ptr<IRotor> rotor1 = std::make_unique<RotorWithLog>(RotorWithLog("II", 1, 24));

    std::vector<std::unique_ptr<IRotor>> rotors;
    rotors.push_back(std::move(rotor3));
    rotors.push_back(std::move(rotor2));
    rotors.push_back(std::move(rotor1));

    Enigma enigmaMachine(
        std::move(rotors),
        std::make_unique<ReflectorWithLog>(ReflectorWithLog("UKW-A")),
        Commutator({
           "AM", "FI", "NV", "PS", "TU", "WZ"
        })
    );

    std::cout << "Enter message to encrypt (type '0' on its own line to stop): " << std::endl;


    std::string inputLine, encryptedMessage, decryptedMessage;
    while (inputLine != "0") {
        encryptedMessage.clear();
        inputLine.clear();
        decryptedMessage.clear();

        std::getline(std::cin, inputLine);

        if (inputLine == "1") {
            enigmaMachine.reset();
            std::cout << "Reset." << std::endl;
        } else {
            std::vector<int> indexes = Ring::transform(inputLine);
            std::vector<int> result;

            for (int index : indexes) {
                int value = enigmaMachine.encrypt(index);
                result.push_back(value);
            }

            encryptedMessage = Ring::transform(result);

            std::cout << "Encrypted: " << encryptedMessage << std::endl;
        }
    }

    return 0;
}
