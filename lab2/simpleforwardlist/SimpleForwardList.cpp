//
// Created by slawek on 11.03.18.
//

#include "SimpleForwardList.h"

ForwardList *CreateNode(int value) {
    ForwardList *node = new ForwardList;
    node->value = value;
    return node;
}

void DestroyList(ForwardList *list) {
    ForwardList *node = list;
    while (node != nullptr) {
        ForwardList *tmp = node;
        node = node->next;
        delete tmp;
    }
}

ForwardList *PushFront(ForwardList *list, int value) {
    if (list == nullptr) {
        return 0;
    }
    ForwardList *new_node = new ForwardList;
    new_node->next = list;
    new_node->value = value;

    return new_node;
}

void Append(ForwardList *list, ForwardList *tail) {
    ForwardList *node = list;
    if (list != nullptr) {
        while (node->next != nullptr) {
            node = node->next;
        }
        node->next = tail;
    }
}