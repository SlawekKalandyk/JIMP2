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

    WordCounter::WordCounter(const initializer_list<Word> &wordList) {
        for (auto i: wordList)
            ++(dict[i]);
    }

    int WordCounter::DistinctWords() {
        return (int) dict.size();
    }

    int WordCounter::TotalWords() {
        int sum = 0;

        for (auto i: dict)
            sum += i.second.GetCounts();

        return sum;
    }

    set<Word> WordCounter::Words() {
        set<Word> words;

        for (auto i: dict)
            words.emplace(i.first);

        return words;
    }

    Counts WordCounter::operator[](const string &word) const {
        if (dict.find(word) == dict.end())
            return Counts{0};
        else
            return dict.find(word)->second;
    }

    WordCounter WordCounter::FromInputStream(ifstream *is) {
        WordCounter counter;
        string str;
        size_t start, end;

        if (is->is_open()) {
            while (getline(*is, str)) {
                for (size_t i = 0; i < str.size(); ++i) {
                    start = i;

                    while ((str[i] > 64 && str[i] < 91) || (str[i] > 96 && str[i] < 123))
                        ++i;

                    end = i;

                    if (start != end) {
                        ++(counter.dict[str.substr(start, end - start)]);
                    }
                }
            }

            is->close();
        } else
            cout << "Unable to open file" << endl;

        return counter;
    }

    WordCounter::WordCounter(WordCounter &&counter) {
        swap(dict, counter.dict);
    }

    WordCounter &WordCounter::operator=(WordCounter &&counter) {
        if (this == &counter)
            return counter;

        dict.clear();

        swap(dict, counter.dict);
    }

    string Word::GetWord() const {
        return word_;
    }

    bool Word::operator==(const Word &w) const { // w/o this it doesn't work? the hell?
        return (word_ == w.word_);
    }

    bool Word::operator<(const Word &w) const { // like above
        int i = 0;

        while (i < word_.size() && i < w.word_.size()) {
            if (word_[i] != w.word_[i])
                return (word_[i] < w.word_[i]);

            ++i;
        }

        return (word_.size() < w.word_.size());
    }

    bool Word::operator>(const Word &w) const { // added bcs of the 2 above
        int i = 0;

        while (i < word_.size() && i < w.word_.size()) {
            if (word_[i] != w.word_[i])
                return (word_[i] > w.word_[i]);

            ++i;
        }

        return (word_.size() < w.word_.size());
    }
}
