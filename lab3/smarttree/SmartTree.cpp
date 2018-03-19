//
// Created by slawek on 12.03.18.
//

#include "SmartTree.h"
#include <iostream>
#include <ostream>
#include <string>
#include <memory>

namespace datastructures {

    std::unique_ptr<SmartTree> CreateLeaf(int value) {
        std::unique_ptr<SmartTree> leaf = std::make_unique<SmartTree>();
        leaf->value = value;
        return leaf;
    }

    std::unique_ptr<SmartTree>
    InsertLeftChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> left_subtree) {
        tree->left = move(left_subtree);
        return tree;
    }

    std::unique_ptr<SmartTree>
    InsertRightChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> right_subtree) {
        tree->right = move(right_subtree);
        return tree;
    }

    void PrintTreeInOrder(const std::unique_ptr<SmartTree> &unique_ptr, std::ostream *out) {
        if (unique_ptr != nullptr) {
            PrintTreeInOrder(unique_ptr->left, out);
            *out << unique_ptr->value << ", ";
            PrintTreeInOrder(unique_ptr->right, out);
        }
    }

    std::string DumpTree(const std::unique_ptr<SmartTree> &tree) {
        std::string output;

        if (tree != nullptr) {
            output += "[" + std::to_string(tree->value);
            output += " ";
            output += DumpTree(tree->left);
            output += " ";
            output += DumpTree(tree->right);
            output += "]";

            return output;
        } else {
            output += "[none]";

            return output;
        }
    }

    std::unique_ptr<SmartTree> RestoreTree(const std::string &tree) {
        std::unique_ptr<SmartTree> output = std::make_unique<SmartTree>();
        std::string str_value;
        std::string right_tree, left_tree;

        int i = 1;
        while (tree[i] != ' ' && tree[i] != ']') {
            if (tree[i] != '[') {
                str_value += tree[i];
            }
            i++;
        }

        if (str_value == "none") {
            return nullptr;
        } else {
            output->value = std::stoi(str_value);
        }

        int startbrackets = 1;
        int j = i + 1;
        while (j < tree.size()) {
            if (tree[j] == '[') {
                startbrackets++;
            }
            if (tree[j] == ']') {
                startbrackets--;
            }
            if (startbrackets == 1) {
                left_tree = tree.substr(i + 1, j - (i + 1) + 1);
                break;
            }
            j++;
        }

        right_tree = tree.substr(j + 2, tree.size() - (j + 2));

        output->left = RestoreTree(left_tree);
        output->right = RestoreTree(right_tree);

        return output;
    }

}