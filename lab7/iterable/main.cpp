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

    Zipper z(vi, vs);
    unique_ptr<IterableIterator> it = z.ConstBegin();
    return it->NotEquals(z.ConstEnd());
//    for(unique_ptr<IterableIterator> it = z.ConstBegin(); it->NotEquals(z.ConstEnd());)//it->Next())
//        pair<int, string> current = it->Dereference();

    return 0;
}
