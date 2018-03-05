//
// Created by slawek on 05.03.18.
//

#include "DoubleBasePalindromes.h"
#include <cstdint>
#include <sstream>
#include <string>
#include <iostream>

uint64_t DoubleBasePalindromes(int max_value_exclusive) {
    uint64_t sum = 0;
    std::string tmp;
    std::string str;
    std::ostringstream converter;

    for (int i = 0; i < max_value_exclusive; i++) {
        tmp = DecimalToBinary(i);
        converter << i;
        str = converter.str();

        if (IsPalindrome(str) && IsPalindrome(tmp)) {
            sum += i;
        }

        converter.str("");
    }

    return sum;
}

std::string DecimalToBinary(int dec) {
    std::string bin;

    while (dec > 0) {
        if(dec % 2){
            bin.insert(0, "1");
        }
        else{
            bin.insert(0, "0");
        }
        dec /= 2;
    }

    return bin;
}

bool IsPalindrome(std::string str) {
    for (int i = 0; i < str.size() / 2; i++) {
        if (str[i] != str[str.size() - 1 - i]) {
            return 0;
        }
    }

    return 1;
}
