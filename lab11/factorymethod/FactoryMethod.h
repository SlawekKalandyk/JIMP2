//
// Created by slawek on 24.05.18.
//

#ifndef JIMP_EXERCISES_FACTORYMETHOD_H
#define JIMP_EXERCISES_FACTORYMETHOD_H

#include <string>

namespace factoryMethod {

    template<typename T>
    T Create() {
        return T();
    }

    class MyType {
    public:
        MyType() {};

        std::string SayHello() { return "hello"; };
    };
}

#endif //JIMP_EXERCISES_FACTORYMETHOD_H
