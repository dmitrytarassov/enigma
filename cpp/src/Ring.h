//
// Created by Dmitrii Tarasov on 22/10/2023.
//

#ifndef CPP_RING_H
#define CPP_RING_H

#include "iostream"

class Ring {
public:
    inline static const std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    static int transform(const char letter) {
        return Ring::alphabet.find(std::toupper(letter));
    }

    static std::vector<int> transform(const std::string inputLine) {
        std::vector<int> result;

        for (char letter : inputLine) {
            result.push_back(transform(letter));
        }

        return result;
    }

    static char transform(int index) {
        return alphabet[index];
    }

    static std::string transform(const std::vector<int> indexes) {
        std::string result;

        for (int index : indexes) {
            result += transform(index);
        }

        return result;
    }

    static std::vector<std::vector<int>> transform(const std::vector<std::string> data) {
        std::vector<std::vector<int>> result;

        for (std::string pair : data) {
            int a = transform(pair[0]);
            int b = transform(pair[1]);

            result.push_back({ a, b });
        }

        return result;
    }
};


#endif //CPP_RING_H
