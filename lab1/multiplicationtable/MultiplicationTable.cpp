//
// Created by slawek on 05.03.18.
//

#include "MultiplicationTable.h"
#include <iostream>

void MultiplicationTable(int tab[][10]) {
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            tab[i - 1][j - 1] = i * j;
        }
    }
}

void PrintTable(int tab[][10]){
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            std::cout << tab[i][j] << " ";
        }

        std::cout << std::endl;
    }
}