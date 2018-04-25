//
// Created by slawek on 22.04.18.
//
#include "Iterable.h"
#include <iostream>

using namespace utility;
using ::std::cout;
using ::std::endl;

int main() {
    vector<int> vi {4, 77, -91};
    vector<string> vs {"4", "9991", "adfskld"};

    auto it = ZipperIterator(vi.begin(),vs.begin(), vi.end(), vs.end());

    std::unique_ptr<IterableIterator> next_it = std::make_unique<ZipperIterator>(vi.begin()+1,vs.begin()+1, vi.end(), vs.end());

    return 0;
}
