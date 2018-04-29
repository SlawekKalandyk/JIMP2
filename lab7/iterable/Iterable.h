//
// Created by slawek on 22.04.18.
//

#ifndef JIMP_EXERCISES_ITERABLE_H
#define JIMP_EXERCISES_ITERABLE_H

#include <string>
#include <vector>
#include <memory>
#include <utility>
#include <iostream>

using ::std::string;
using ::std::pair;
using ::std::unique_ptr;
using ::std::vector;
using ::std::initializer_list;
using ::std::make_unique;
using ::std::cout;
using ::std::endl;
using ::std::make_pair;

namespace utility {

    class IterableIterator {
    public:
        ~IterableIterator() = default;

        virtual std::pair<int, std::string> Dereference() const =0;

        virtual IterableIterator &Next() =0;

        virtual bool NotEquals(const unique_ptr<IterableIterator> &other) const =0;

        vector<int>::const_iterator GetLeft() const;

        vector<string>::const_iterator GetRight() const;

        vector<int>::const_iterator left_, left_end_;

        vector<string>::const_iterator right_, right_end_;
    };

    class GeneralIterator : public IterableIterator {
    public:
        explicit GeneralIterator(std::vector<int>::const_iterator left_begin,
                                 std::vector<std::string>::const_iterator right_begin,
                                 std::vector<int>::const_iterator left_end,
                                 std::vector<std::string>::const_iterator right_end);

        pair<int, string> Dereference() const override;

        IterableIterator &Next() override;

        bool NotEquals(const unique_ptr<IterableIterator> &other) const override;
    };

    class ZipperIterator : public GeneralIterator {
    public:
        explicit ZipperIterator(std::vector<int>::const_iterator left_begin,
                                std::vector<std::string>::const_iterator right_begin,
                                std::vector<int>::const_iterator left_end,
                                std::vector<std::string>::const_iterator right_end)
                : GeneralIterator(left_begin, right_begin, left_end, right_end) {};;

    };

    class EnumerateIterator : public GeneralIterator {
    public:
        explicit EnumerateIterator(std::vector<int>::const_iterator left_begin,
                                   std::vector<std::string>::const_iterator right_begin,
                                   std::vector<int>::const_iterator left_end,
                                   std::vector<std::string>::const_iterator right_end)
                : GeneralIterator(left_begin, right_begin, left_end, right_end) {};;
    };

    class ProductIterator : public GeneralIterator {
    public:
        explicit ProductIterator(std::vector<int>::const_iterator left_begin,
                                 std::vector<std::string>::const_iterator right_begin,
                                 std::vector<int>::const_iterator left_end,
                                 std::vector<std::string>::const_iterator right_end)
                : GeneralIterator(left_begin, right_begin, left_end, right_end) {};
    };

    class IterableIteratorWrapper {
    public:
        IterableIteratorWrapper(unique_ptr<IterableIterator> iterator);

        bool operator!=(const IterableIteratorWrapper &other);

        pair<int, string> operator*() const;

        IterableIteratorWrapper &operator++();

    private:
        unique_ptr<IterableIterator> iterator_;
    };

    class Iterable {
    public:
        virtual unique_ptr<IterableIterator> ConstBegin() const =0;

        virtual unique_ptr<IterableIterator> ConstEnd() const =0;

        IterableIteratorWrapper cbegin() const;

        IterableIteratorWrapper cend() const;

        IterableIteratorWrapper begin() const;

        IterableIteratorWrapper end() const;
    };

    class GeneralIterable : public Iterable {
    public:
        unique_ptr<IterableIterator> ConstBegin() const override;

        unique_ptr<IterableIterator> ConstEnd() const override;

        vector<string> vs_;

        vector<int> vi_;
    };

    class Enumerate : public GeneralIterable {
    public:
        Enumerate(vector<string> vs);
    };

    class Product : public GeneralIterable {
    public:
        Product(vector<int> vi, vector<string> vs);
    };

    class Zipper : public GeneralIterable {
    public:
        Zipper(vector<int> vi, vector<string> vs);
    };

}

#endif //JIMP_EXERCISES_ITERABLE_H
