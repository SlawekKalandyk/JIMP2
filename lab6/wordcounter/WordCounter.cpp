//
// Created by slawek on 09.04.18.
//

#include "WordCounter.h"

namespace datastructures {

    bool Counts::operator<(const Counts &c) {
        if (counts_ < c.GetCounts())
            return true;
        else
            return false;
    }

    bool Counts::operator>(const Counts &c) {
        if (counts_ > c.GetCounts())
            return true;
        else
            return false;
    }

    bool Counts::operator==(const Counts &c) {
        if (counts_ == c.GetCounts())
            return true;
        else
            return false;
    }

    Counts &Counts::operator++() {
        ++counts_;
        return *this;
    }

    int Counts::GetCounts() const {
        return counts_;
    }

    WordCounter::WordCounter(initializer_list<Word> wordList) {
        for(auto it = wordList.begin(); it != wordList.end(); ++it) {
            if(dict.find(*it) == dict.end())
                dict.emplace(Word(*it), Counts(1));
            else {
                ++(dict.find(Word(*it))->second);
            }
        }
    }

    int WordCounter::DistinctWords() {
        return dict.size();
    }

    int WordCounter::TotalWords() {
        int sum = 0;

        for (auto it = dict.begin(); it != dict.end(); ++it) {
            sum += it->second.GetCounts();
        }

        return sum;
    }

    set<string> WordCounter::Words() {
        set<string> words;

        for (auto it = dict.begin(); it != dict.end(); ++it) {
            words.emplace(it->first.GetWord());
            ++(it->second);
        }

        return words;
    }

    Counts WordCounter::operator[](string word) {
        if(dict.find(word) == dict.end())
            return Counts(0);
        else
            return dict.find(word)->second;
    }

    string Word::GetWord() const {
        return word_;
    }
}
