//
// Created by slawek on 09.04.18.
//

#include "WordCounter.h"
#include <iostream>

using namespace datastructures;

int main() {
    ifstream is("test.txt"); //can't open file
    WordCounter wc = WordCounter::FromInputStream(&is);

    int ilosc = wc["chrzaszcz"];
    cout<<ilosc<<endl;

    return 0;
}