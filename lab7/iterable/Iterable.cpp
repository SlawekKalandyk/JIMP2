//
// Created by slawek on 22.04.18.
//

#include "Iterable.h"

namespace utility {

    ZipperIterator::ZipperIterator(std::vector<int>::const_iterator left_begin,
                                   std::vector<std::string>::const_iterator right_begin,
                                   std::vector<int>::const_iterator left_end,
                                   std::vector<std::string>::const_iterator right_end) {
        left_ = left_begin;
        left_end_ = left_end;
        right_ = right_begin;
        right_end_ = right_end;
    }

    pair<int, string> ZipperIterator::Dereference() const {
        return std::make_pair(*left_, *right_);
    }

    IterableIterator &ZipperIterator::Next() {
        ++left_;
        ++right_;

        return *this;
    }

    bool ZipperIterator::NotEquals(const unique_ptr<IterableIterator> &other) const {
        return this != other.get();
    }

}