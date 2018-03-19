//
// Created by kalaslaw on 13.03.18.
//

#include "TinyUrl.h"
#include <utility>
#include <string>
#include <array>
#include <memory>
#include <iostream>

namespace tinyurl {

    std::unique_ptr<TinyUrlCodec> Init() {

    }

    void NextHash(std::array<char, 6> *state) {
        int size = state->size();

        if (state->back() == '9') {
            state->back() = 'A';
        } else if (state->back() == 'Z') {
            state->back() = 'a';
        } else if (state->back() == 'z') {
            int i = size - 1;

            while (state->at(i) == 'z') {
                state->at(i) = '0';
                i--;
            }

            if (state->at(i) == '9') {
                state->at(i) = 'A';
            } else if (state->at(i) == 'Z') {
                state->at(i) = 'a';
            } else {
                state->at(i) = char(int(state->at(i)) + 1);
            }
        } else {
            state->back() = char(int(state->back()) + 1);
        }
    }

    std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec) {

    }

    std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash) {

    }

}