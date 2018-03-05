//
// Created by slawek on 05.03.18.
//

#include "Palindrome.h"
#include "Palindrome.cpp"
#include <string>
#include <iostream>

int main() {
    int a;
    std::string input;
    std::cout << "1.Sprawdź palindrom\n2.Wyjście z programu\n";
    std::cin >> a;

    switch (a) {
        case 1:
            std::cout << "Wprowadź tekst" << std::endl;
            std::cin >> input;
            if(is_palindrome(input) == 0){
                std::cout << "Tekst nie jest palindromem\n";
            }
            else{
                std::cout << "Tekst jest palindromem\n";
            }
        case 2:
            return 0;
    }

    return 0;
}