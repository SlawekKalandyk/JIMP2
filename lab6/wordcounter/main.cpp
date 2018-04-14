//
// Created by slawek on 09.04.18.
//

#include "WordCounter.h"
#include <iostream>

using ::std::cout;
using ::std::endl;

using namespace datastructures;

int main() {
    WordCounter counter{Word("a"), Word("p"), Word("a"), Word("a"), Word("hi"), Word("voltage")};
    //cout << counter["b"].GetCounts() <<" " <<counter["a"].GetCounts()<<endl;
    set<Word> expected {Word("a"),Word("hi"), Word("voltage"), Word("p")};
    for(auto i: counter.Words())
        cout<<i.GetWord()<<endl;
    if(expected == counter.Words())
        cout<<"HAHAHAHAHA"<<endl;
    return 0;
}