//
// Created by slawek on 01.06.18.
//

#ifndef JIMP_EXERCISES_SEQUENTIALGENERATOR_H
#define JIMP_EXERCISES_SEQUENTIALGENERATOR_H

template<typename T, typename U>
class SequentialIdGenerator {
public:
    SequentialIdGenerator();

    SequentialIdGenerator(U simpleType);

    T NextValue();

private:
    // T arg1_;
    U arg2_;
};

template<typename T, typename U>
SequentialIdGenerator<T, U>::SequentialIdGenerator() {
    arg2_ = U();
}

template<typename T, typename U>
SequentialIdGenerator<T, U>::SequentialIdGenerator(U simpleType) {
    arg2_ = simpleType;
}


template<typename T, typename U>
T SequentialIdGenerator<T, U>::NextValue() {
    T temp(arg2_);
    ++arg2_;
    return temp;
}

#endif //JIMP_EXERCISES_SEQUENTIALGENERATOR_H
