//
// Created by Dmitrii Tarasov on 22/10/2023.
//

#ifndef CPP_IREFLECTOR_H
#define CPP_IREFLECTOR_H


class IReflector {
public:
    virtual ~IReflector() {}

    virtual int reflect(int input) const = 0;
};


#endif //CPP_IREFLECTOR_H
