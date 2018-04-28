//
// Created by slawek on 22.04.18.
//

#include "Iterable.h"

namespace utility {

    vector<int>::const_iterator IterableIterator::GetLeft() const {
        return left_;
    }

    vector<string>::const_iterator IterableIterator::GetRight() const {
        return right_;
    }

    IterableIteratorWrapper::IterableIteratorWrapper(unique_ptr<IterableIterator> iterator) {
        iterator_ = move(iterator);
    }

    bool IterableIteratorWrapper::operator!=(const IterableIteratorWrapper &other) {
        return iterator_->NotEquals(other.iterator_);
    }

    pair<int, string> IterableIteratorWrapper::operator*() const {
        return iterator_->Dereference();
    }

    IterableIteratorWrapper &IterableIteratorWrapper::operator++() {
        iterator_->Next();

        return *this;
    }

    IterableIteratorWrapper Iterable::cbegin() const {
        return IterableIteratorWrapper(ConstBegin());
    }

    IterableIteratorWrapper Iterable::cend() const {
        return IterableIteratorWrapper(ConstEnd());
    }

    IterableIteratorWrapper Iterable::begin() const {
        return cbegin();
    }

    IterableIteratorWrapper Iterable::end() const {
        return cend();
    }

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
        return make_pair(*left_, *right_);
    }

    IterableIterator &ZipperIterator::Next() {
        if (left_ != left_end_ && right_ != right_end_) {
            ++left_;
            ++right_;
        }

        return *this;
    }

    bool ZipperIterator::NotEquals(const unique_ptr<IterableIterator> &other) const {
        return left_ != other->GetLeft() && right_ != other->GetRight();
    }

    Zipper::Zipper(vector<int> vi, vector<string> vs) {
        vs_ = move(vs);
        vi_ = move(vi);

        if (vs_.size() < vi_.size()) {
            string tmp = vs_[vs_.size() - 1];

            while (vs_.size() < vi_.size())
                vs_.emplace_back(tmp);
        } else if (vs_.size() > vi_.size()) {
            int tmp = vi_[vi_.size() - 1];

            while (vs_.size() > vi_.size())
                vi_.emplace_back(tmp);
        }
    }

    unique_ptr<IterableIterator> Zipper::ConstBegin() const {
        ZipperIterator z(vi_.begin(), vs_.begin(), vi_.end(), vs_.end());
        unique_ptr<IterableIterator> begin = make_unique<ZipperIterator>(z);

        return begin;
    }

    unique_ptr<IterableIterator> Zipper::ConstEnd() const {
        ZipperIterator z(vi_.end(), vs_.end(), vi_.end(), vs_.end());
        unique_ptr<IterableIterator> end = make_unique<ZipperIterator>(z);

        return end;
    }

    EnumerateIterator::EnumerateIterator(std::vector<int>::const_iterator left_begin,
                                         std::vector<std::string>::const_iterator right_begin,
                                         std::vector<int>::const_iterator left_end,
                                         std::vector<std::string>::const_iterator right_end) {
        left_ = left_begin;
        left_end_ = left_end;
        right_ = right_begin;
        right_end_ = right_end;
    }

    pair<int, string> EnumerateIterator::Dereference() const {
        return make_pair(*left_, *right_);
    }

    IterableIterator &EnumerateIterator::Next() {
        if (left_ != left_end_ && right_ != right_end_) {
            ++left_;
            ++right_;
        }

        return *this;
    }

    bool EnumerateIterator::NotEquals(const unique_ptr<IterableIterator> &other) const {
        return left_ != other->GetLeft() && right_ != other->GetRight();
    }

    Enumerate::Enumerate(vector<string> vs) {
        vs_ = move(vs);

        for (int i = 1; i < vs_.size() + 1; i++)
            vi_.emplace_back(i);
    }

    unique_ptr<IterableIterator> Enumerate::ConstBegin() const {
        EnumerateIterator e(vi_.begin(), vs_.begin(), vi_.end(), vs_.end());
        unique_ptr<IterableIterator> begin = make_unique<EnumerateIterator>(e);

        return begin;
    }

    unique_ptr<IterableIterator> Enumerate::ConstEnd() const {
        EnumerateIterator e(vi_.end(), vs_.end(), vi_.end(), vs_.end());
        unique_ptr<IterableIterator> end = make_unique<EnumerateIterator>(e);

        return end;
    }

    ProductIterator::ProductIterator(std::vector<int>::const_iterator left_begin,
                                     std::vector<std::string>::const_iterator right_begin,
                                     std::vector<int>::const_iterator left_end,
                                     std::vector<std::string>::const_iterator right_end) {
        left_ = left_begin;
        left_end_ = left_end;
        right_ = right_begin;
        right_end_ = right_end;
    }

    pair<int, string> ProductIterator::Dereference() const {
        return make_pair(*left_, *right_);
    }

    IterableIterator &ProductIterator::Next() {
        if (left_ != left_end_ && right_ != right_end_) {
            ++left_;
            ++right_;
        }

        return *this;
    }

    bool ProductIterator::NotEquals(const unique_ptr<IterableIterator> &other) const {
        return left_ != other->GetLeft() && right_ != other->GetRight();
    }

    Product::Product(vector<int> vi, vector<string> vs) {
        for (const auto &viIt : vi) {
            for (const auto &vsIt : vs) {
                vi_.emplace_back(viIt);
                vs_.emplace_back(vsIt);
            }
        }
    }

    unique_ptr<IterableIterator> Product::ConstBegin() const {
        ProductIterator p(vi_.begin(), vs_.begin(), vi_.end(), vs_.end());
        unique_ptr<IterableIterator> begin = make_unique<ProductIterator>(p);

        return begin;
    }

    unique_ptr<IterableIterator> Product::ConstEnd() const {
        ProductIterator p(vi_.end(), vs_.end(), vi_.end(), vs_.end());
        unique_ptr<IterableIterator> end = make_unique<ProductIterator>(p);

        return end;
    }

}