//
// Created by slawek on 05.03.18.
//

#include "Palindrome.h"
#include <string>
#include <iostream>

bool is_palindrome(std::string str) {
    for (int i = 0; i < str.size() / 2; i++) {
        if (str[i] != str[str.size() - 1 - i]) {
            return 0;
        }
    }

    return 1;
}
