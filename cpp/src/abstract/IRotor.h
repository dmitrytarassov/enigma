//
// Created by Dmitrii Tarasov on 22/10/2023.
//

#ifndef CPP_IROTOR_H
#define CPP_IROTOR_H


class IRotor {
public:
    virtual ~IRotor() {}

    virtual bool madeFullRotation() const = 0;

    virtual void rotate() {};

    virtual void resetTurnNext() {};

    virtual void reset() {};

    virtual int transform(const int input) const = 0;

    virtual int reverseTransform(int input) const = 0;
};


#endif //CPP_IROTOR_H
