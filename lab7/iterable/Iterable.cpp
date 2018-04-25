//
// Created by slawek on 22.04.18.
//

#include "Iterable.h"

namespace utility {

    ZipperIterator::ZipperIterator(std::vector<int>::const_iterator left,
                                   std::vector<std::string>::const_iterator right,
                                   std::vector<int>::const_iterator left_end,
                                   std::vector<std::string>::const_iterator right_end) {

    }

    pair<int, string> ZipperIterator::Dereference() const {

    }

    IterableIterator &ZipperIterator::Next() {

    }

}