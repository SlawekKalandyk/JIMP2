//
// Created by slawek on 22.04.18.
//

#ifndef JIMP_EXERCISES_ITERABLE_H
#define JIMP_EXERCISES_ITERABLE_H

#include <string>
#include <vector>
#include <memory>
#include <utility>

using ::std::string;
using ::std::pair;
using ::std::unique_ptr;
using ::std::vector;
using ::std::initializer_list;

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
        explicit ZipperIterator(std::vector<int>::const_iterator left_begin,
                                std::vector<std::string>::const_iterator right_begin,
                                std::vector<int>::const_iterator left_end,
                                std::vector<std::string>::const_iterator right_end);

        pair<int, string> Dereference() const override;

        IterableIterator &Next() override;

        bool NotEquals(const unique_ptr<IterableIterator> &other) const override;

    private:
        vector<int>::const_iterator left_, left_end_;
        vector<string>::const_iterator right_, right_end_;
    };

    class IterableIteratorWrapper {
    public:
        IterableIteratorWrapper(unique_ptr<IterableIterator> iterator);

        bool operator!=(const IterableIteratorWrapper &other);

        pair<int, string> operator*();

        IterableIteratorWrapper &operator++();

    private:
        unique_ptr<IterableIterator> iterator_;
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
