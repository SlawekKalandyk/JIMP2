//
// Created by slawek on 05.03.2018.
//

#include "ReverseString.h"
#include <string>
#include <iostream>

std::string reverse(std::string str) {
    size_t size = str.size();

    if(size <= 1){
        return str;
    }
    else{
        return reverse(str.substr(1)) + str[0];
    }
}