//
// Created by slawek on 11.03.18.
//

#include "SimpleForwardList.h"
#include "SimpleForwardList.cpp"
#include <iostream>

using namespace std;

int main(){
    ForwardList *node = CreateNode(27);
    ForwardList *new_node = PushFront(node, 2137);
    cout << node->value << " "<< new_node->value<< " " << new_node->next->value << " "<< endl;

    return 0;
}