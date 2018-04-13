//
// Created by slawek on 09.04.18.
//

#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H

#include <string>
#include <fstream>
#include <map>
#include <set>

using ::std::string;
using ::std::ifstream;
using ::std::initializer_list;
using ::std::map;
using ::std::set;

namespace datastructures {
    class Word {
    public:
        Word(const string &word) : word_(word) {};

        string GetWord() const;

    private:
        string word_;
    };

    class Counts {
    public:
        Counts() : counts_(0) {};

        Counts(int counts) : counts_(counts) {};

        bool operator<(const Counts &c);

        bool operator>(const Counts &c);

        bool operator==(const Counts &c);

        Counts &operator++();

        int GetCounts() const;

    private:
        int counts_;
    };

    class WordCounter {
    public:
        WordCounter() {};

        WordCounter(initializer_list<Word> wordList);

        Counts operator[](string word);

        int DistinctWords();

        int TotalWords();

        set<string> Words();

    private:
        map<Word, Counts> dict;
    };
}


#endif //JIMP_EXERCISES_WORDCOUNTER_H
