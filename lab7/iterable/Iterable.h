//
// Created by slawek on 22.04.18.
//

#ifndef JIMP_EXERCISES_ITERABLE_H
#define JIMP_EXERCISES_ITERABLE_H

#include <string>
#include <vector>
#include <memory>

using ::std::string;
using ::std::pair;
using ::std::unique_ptr;

namespace utility {

    class IterableIterator {
    public:
        ~IterableIterator() = default;

        virtual std::pair<int, std::string> Dereference() const =0;

        virtual IterableIterator &Next() =0;

        virtual bool NotEquals(const unique_ptr<IterableIterator> &other) const =0;
    };

    class ZipperIterator : public IterableIterator {
    public:
        explicit ZipperIterator(std::vector<int>::const_iterator left,
                                std::vector<std::string>::const_iterator right,
                                std::vector<int>::const_iterator left_end,
                                std::vector<std::string>::const_iterator right_end);

        pair<int, string> Dereference() const override;

        IterableIterator &Next() override;


    };

    class Enumerate {
    public:

    };

    class Product {

    };

    class Zipper {

    };

}

#endif //JIMP_EXERCISES_ITERABLE_H
