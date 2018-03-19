//
// Created by kalaslaw on 13.03.18.
//

#include "TinyUrl.h"
#include "TinyUrl.cpp"
#include <utility>
#include <string>
#include <array>
#include <memory>

using namespace tinyurl;

int main(){
    std::array<char, 6> arg;
    arg.at(0) = 'X';
    arg.at(1) = 'Y';
    arg.at(2) = 'Z';
    arg.at(3) = 'a';
    arg.at(4) = 'z';
    arg.at(5) = 'z';
    NextHash(&arg);

    return 0;
}