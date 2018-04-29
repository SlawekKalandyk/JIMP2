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

    Enumerate::Enumerate(vector<string> vs) {
        vs_ = move(vs);

        for (int i = 1; i < vs_.size() + 1; i++)
            vi_.emplace_back(i);
    }

    Product::Product(vector<int> vi, vector<string> vs) {
        for (const auto &viIt : vi) {
            for (const auto &vsIt : vs) {
                vi_.emplace_back(viIt);
                vs_.emplace_back(vsIt);
            }
        }
    }

    GeneralIterator::GeneralIterator(std::vector<int>::const_iterator left_begin,
                                     std::vector<std::string>::const_iterator right_begin,
                                     std::vector<int>::const_iterator left_end,
                                     std::vector<std::string>::const_iterator right_end) {
        left_ = left_begin;
        left_end_ = left_end;
        right_ = right_begin;
        right_end_ = right_end;
    }

    pair<int, string> GeneralIterator::Dereference() const {
        return make_pair(*left_, *right_);
    }

    IterableIterator &GeneralIterator::Next() {
        if (left_ != left_end_ && right_ != right_end_) {
            ++left_;
            ++right_;
        }

        return *this;
    }

    bool GeneralIterator::NotEquals(const unique_ptr<IterableIterator> &other) const {
        return left_ != other->GetLeft() && right_ != other->GetRight();
    }

    unique_ptr<IterableIterator> GeneralIterable::ConstBegin() const {
        GeneralIterator g(vi_.begin(), vs_.begin(), vi_.end(), vs_.end());
        unique_ptr<IterableIterator> begin = make_unique<GeneralIterator>(g);

        return begin;
    }

    unique_ptr<IterableIterator> GeneralIterable::ConstEnd() const {
        GeneralIterator g(vi_.end(), vs_.end(), vi_.end(), vs_.end());
        unique_ptr<IterableIterator> end = make_unique<GeneralIterator>(g);

        return end;
    }
}