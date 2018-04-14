//
// Created by slawek on 09.04.18.
//

#include "WordCounter.h"
#include <iostream>

using namespace datastructures;

int main() {
    ifstream is("/home/slawek/Programming/Repositories/JIMP2/lab6/wordcounter/test.txt");
    WordCounter wc = WordCounter::FromInputStream(&is);

    int ilosc = wc["trzcinie"];
    cout << ilosc << endl;
    cout << wc;

    return 0;
}