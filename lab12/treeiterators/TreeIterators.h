//
// Created by slawek on 29.05.18.
//

#ifndef JIMP_EXERCISES_TREEITERATORS_H
#define JIMP_EXERCISES_TREEITERATORS_H

#include <memory>
#include <vector>

using ::std::unique_ptr;
using ::std::vector;
using ::std::make_unique;


namespace tree {

    template<typename T>
    class Tree {
    public:
        Tree();

        Tree(T t);

        void Insert(const T &t);

        bool Find(const T &t);

        size_t Depth();

        size_t Size();

        T Value();

        Tree Root();

    private:
        unique_ptr<Tree> parent_;
        unique_ptr<Tree> leftTree_;
        unique_ptr<Tree> rightTree_;
        T value_;
        size_t size_;
    };

    template<typename T>
    class InOrder {
    public:

    };

    template<typename T>
    class InOrderTreeIterator {
    public:

    };

    template<typename T>
    class InOrderTreeView {
    public:

    };

    template<typename T>
    Tree<T>::Tree() {
        size_ = 0;
    }

    template<typename T>
    Tree<T>::Tree(T t) {
        value_ = t;
        size_ = 1;
        parent_ = nullptr;
        leftTree_ = nullptr;
        rightTree_ = nullptr;
    }

    template<typename T>
    void Tree<T>::Insert(const T &t) {
        ++size_;
        if (t < value_) {
            if (leftTree_ == nullptr) {
                leftTree_ = make_unique<Tree>(Tree(t));
                leftTree_->parent_ = make_unique<Tree>(this);
            } else
                leftTree_->Insert(t);
        } else if (rightTree_ == nullptr) {
            rightTree_ = make_unique<Tree>(Tree(t));
            leftTree_->parent_= make_unique<Tree>(this);
        } else
            rightTree_->Insert(t);
    }

    template<typename T>
    bool Tree<T>::Find(const T &t) {
        if (this == nullptr)
            return false;
        if (t == value_)
            return true;
        else if (t < value_) {
            return leftTree_->Find(t);
        } else
            return rightTree_->Find(t);
    }

    template<typename T>
    size_t Tree<T>::Depth() {
        if(this == nullptr)
            return 0;
        else {
            size_t leftTreeDepth = leftTree_->Depth();
            size_t rightTreeDepth = rightTree_->Depth();

            if(leftTreeDepth < rightTreeDepth)
                return rightTreeDepth + 1;
            else
                return leftTreeDepth + 1;
        }
    }

    template<typename T>
    size_t Tree<T>::Size() {
        return size_;
    }

    template<typename T>
    T Tree<T>::Value() {
        return value_;
    }

    template<typename T>
    Tree Tree<T>::Root() {
        if(parent_ == nullptr)
            return this;
        else
            return parent_->Root();
    }

}


#endif //JIMP_EXERCISES_TREEITERATORS_H
