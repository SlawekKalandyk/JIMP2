//
// Created by slawek on 09.04.18.
//

#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <set>
#include <iostream>
#include <algorithm>
#include <utility>

using ::std::string;
using ::std::cout;
using ::std::endl;
using ::std::istream;
using ::std::ifstream;
using ::std::initializer_list;
using ::std::map;
using ::std::set;
using ::std::pair;
using ::std::sort;
using ::std::move;

namespace datastructures {
    class Word {
    public:
        Word() {};

        Word(const string &word) : word_(word) {};

        bool operator<(const Word &w) const;

        bool operator>(const Word &w) const;

        bool operator==(const Word &w) const;

        string GetWord() const;

    private:
        string word_;
    };

    class Counts {
    public:
        Counts() {};

        Counts(const int &counts) : counts_(counts) {};

        bool operator<(const Counts &c) const;

        bool operator>(const Counts &c) const;

        bool operator==(const Counts &c) const;

        Counts &operator++();

        operator int() const { return counts_; }

        int GetCounts() const;

    private:
        int counts_ = 0;
    };

    class WordCounter {
    public:
        WordCounter() {};

        WordCounter(const initializer_list<Word> &wordList);

        WordCounter(WordCounter &&counter); // move constructor

        WordCounter &operator=(WordCounter &&counter); // move operator

        ~WordCounter() { dict.clear(); }

        Counts operator[](const string &word) const;

        static WordCounter FromInputStream(ifstream *is);

        int DistinctWords();

        int TotalWords();

        set<Word> Words();

    private:
        map<Word, Counts> dict;
    };
}


#endif //JIMP_EXERCISES_WORDCOUNTER_H
