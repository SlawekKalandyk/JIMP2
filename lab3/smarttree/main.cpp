//
// Created by slawek on 12.03.18.
//

#include "SmartTree.h"
#include "SmartTree.cpp"
#include <iostream>
#include <ostream>
#include <string>
#include <memory>

using namespace datastructures;

int main(){
    auto tree = RestoreTree("[99 [100 [1234 [none] [none]] [4321 [none] [none]]] "
                                    "[88 [897 [none] [none]] [761 [none] [none]]]]");

    return 0;
}