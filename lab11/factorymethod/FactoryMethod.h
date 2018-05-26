//
// Created by slawek on 24.05.18.
//

#ifndef JIMP_EXERCISES_FACTORYMETHOD_H
#define JIMP_EXERCISES_FACTORYMETHOD_H

#include <string>

namespace factoryMethod {

    template<typename T>
    class Create {
    public:
        Create() { a = new T(); };

        ~Create() { delete a; }

        operator T() const { return *a; };
    private:
        T *a;
    };

    class MyType {
    public:
        MyType() {};

        std::string SayHello() { return "hello"; };
    };
};


#endif //JIMP_EXERCISES_FACTORYMETHOD_H
