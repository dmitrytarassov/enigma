//
// Created by Dmitrii Tarasov on 23/10/2023.
//

#include <iostream>
#include <string>
#include <algorithm>

#include "Enigma.h"
#include "Commutator.h"
#include "Reflector.h"
#include "Rotor.h"
#include <fstream>
#include <chrono>

int main() {
    std::unique_ptr<IRotor> rotor3 = std::make_unique<Rotor>(Rotor::factory("III", 12, 22));
    std::unique_ptr<IRotor> rotor2 = std::make_unique<Rotor>(Rotor::factory("I", 2, 13));
    std::unique_ptr<IRotor> rotor1 = std::make_unique<Rotor>(Rotor::factory("II", 1, 24));

    std::vector<std::unique_ptr<IRotor>> rotors;
    rotors.push_back(std::move(rotor3));
    rotors.push_back(std::move(rotor2));
    rotors.push_back(std::move(rotor1));

    Enigma enigmaMachine(
            std::move(rotors),
            std::make_unique<Reflector>(Reflector::factory("UKW-A")),
            Commutator({
                "AM", "FI", "NV", "PS", "TU", "WZ"
           })
    );

    std::ifstream file("../lorem.txt");

    if (!file) {  // Check if the file was opened successfully
        std::cerr << "Unable to open the file." << std::endl;
        return 1;  // Return with an error code
    }

    std::string inputLine, decryptedMessage;
    std::getline(file, inputLine);

    file.close();

    auto start = std::chrono::high_resolution_clock::now();

    std::string encryptedMessage = enigmaMachine.encryptMessage(inputLine);

    auto stop = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    std::cout << duration.count() << std::endl;

    return 0;
}
