//
// Created by slawek on 12.03.18.
//

#include "SmartTree.h"
#include <ostream>
#include <string>
#include <memory>

using namespace datastructures;

std::unique_ptr<SmartTree> CreateLeaf(int value) {
    std::unique_ptr<SmartTree> leaf;
    leaf->value = value;
    return leaf;
}

std::unique_ptr<SmartTree> InsertLeftChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> left_subtree) {

}

std::unique_ptr<SmartTree> InsertRightChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> right_subtree) {

}

void PrintTreeInOrder(const std::unique_ptr<SmartTree> &unique_ptr, std::ostream *out) {

}

std::string DumpTree(const std::unique_ptr<SmartTree> &tree) {

}

std::unique_ptr<SmartTree> RestoreTree(const std::string &tree) {

}
