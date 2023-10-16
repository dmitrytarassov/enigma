#include <iostream>
#include <string>
#include <algorithm>
#include "Enigma.h"
#include "Rotor.h"
#include "Reflector.h"
#include "Commutator.h"

int main() {
    Enigma enigmaMachine(
        {
            Rotor::factory("III", 1),
            Rotor::factory("I", 13),
            Rotor::factory("II", 24)
        },
        Reflector::factory("UKW-A"),
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
            for (char toEncrypt : inputLine) {
                char encrypted = enigmaMachine.encrypt(std::toupper(static_cast<unsigned char>(toEncrypt)));
                encryptedMessage += encrypted;
            }

            std::cout << "Encrypted: " << encryptedMessage << std::endl;
        }
    }

    return 0;
}
