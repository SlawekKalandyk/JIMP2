//
// Created by slawek on 22.04.18.
//
#include "Iterable.h"
#include <iostream>

using namespace utility;
using ::std::cout;
using ::std::endl;

int main() {
    vector<int> vi = {1, 2, 3};
    vector<string> vs = {"a", "b", "c"};

    for (const auto &p : Product(vi, vs)) {
        cout << "a"<< endl;
    }

    return 0;
}
