//
// Created by slawek on 09.04.18.
//

#include "WordCounter.h"

namespace datastructures {

    bool Counts::operator<(const Counts &c) const {
        return (counts_ < c.GetCounts());
    }

    bool Counts::operator>(const Counts &c) const {
        return (counts_ > c.GetCounts());
    }

    bool Counts::operator==(const Counts &c) const {
        return (counts_ == c.GetCounts());
    }

    Counts &Counts::operator++() {
        ++counts_;
        return *this;
    }

    int Counts::GetCounts() const {
        return counts_;
    }

    WordCounter::WordCounter(initializer_list<Word> wordList) {
        vector<Word> v(wordList);
        int counter = 1;

        for (int i = 0; i < v.size(); ++i) {
            for (int j = i + 1; j < v.size(); ++j) {
                if (v.at(i) == v.at(j)) {
                    ++counter;
                    v.erase(v.begin() + j);
                    --j;
                }
            }

            dict.emplace(v.at(i), Counts(counter));
            counter = 1;
        }
        // /for (auto i : wordList) { odnośnie tej i innych, dziwnych:
        //    ++(dict[i]);            probowałem funkcjami mapy - nie wyszło
        //}                           więc zrobiłem to trochę w sposób brute-force
    }

    int WordCounter::DistinctWords() {
        return (int) dict.size();
    }

    int WordCounter::TotalWords() {
        int sum = 0;

        for (auto i: dict) {
            sum += i.second.GetCounts();
        }

        return sum;
    }

    set<Word> WordCounter::Words() {
        set<Word> words;

        for (auto i: dict)
            words.emplace(i.first);
        //for (auto &i: words)
        //    std::cout << i.GetWord() << std::endl;
        return words;
    }

    Counts WordCounter::operator[](const string &word) {
        for (auto i: dict) {
            if (i.first.GetWord() == word) {
                return i.second;
            }
        }

        return 0;
        //if (dict.find(word) == dict.end())
        //    return Counts{0};
        //else
        //    return dict.find(word)->second;
    }

    string Word::GetWord() const {
        return word_;
    }

    bool Word::operator==(const Word &w) const {
        return (word_ == w.word_);
    }

    bool Word::operator<(const Word &w) const {
        int i = 0;
        while(i < word_.size() && i < w.word_.size()) {
            if(word_[i] != w.word_[i]) {
                if(word_[i] < w.word_[i])
                    return true;
                else
                    return false;
            }

            ++i;
        }
    }
}
