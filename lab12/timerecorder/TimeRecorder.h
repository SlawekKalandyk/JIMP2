//
// Created by slawek on 26.05.18.
//

#ifndef JIMP_EXERCISES_TIMERECORDER_H
#define JIMP_EXERCISES_TIMERECORDER_H

#include <string>
#include <unordered_map>
#include <chrono>

using ::std::pair;
using ::std::make_pair;

namespace profiling {

    template<typename T>
    auto TimeRecorder(T obj) {
        auto before = std::chrono::high_resolution_clock::now();
        auto temp = obj();
        auto after = std::chrono::high_resolution_clock::now();

        auto toMiliSec = std::chrono::duration_cast<std::chrono::duration<double>>
                                  (after - before).count() * 1000;

        return make_pair(temp, toMiliSec);
    };
}


#endif //JIMP_EXERCISES_TIMERECORDER_H
