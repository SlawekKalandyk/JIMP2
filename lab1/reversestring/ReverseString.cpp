//
// Created by slawek on 05.03.2018.
//

#include "ReverseString.h"
#include <string>

std::string reverse(std::string str) {
    std::string result;
    size_t size = str.size();

    if(size <= 1){
        return str;
    }
    else{
        str.erase(0,1);
        reverse(str);
        result.push_back(str[0]);
        return result;
    }
}