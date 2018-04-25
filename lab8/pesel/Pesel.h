//
// Created by slawek on 24.04.18.
//

#ifndef JIMP_EXERCISES_PESEL_H
#define JIMP_EXERCISES_PESEL_H

#include <string>
#include <stdexcept>
#include <regex>

using ::std::string;
using ::std::regex;

namespace academia {

    class Pesel {
    public:
        Pesel(const string &pesel);
        //void validatePesel(const char *pesel);

    private:
        string pesel_;
    };

    class InvalidPeselChecksum {
    public:
        InvalidPeselChecksum(const string &pesel);
    private:

    };

    class InvalidPeselLength {
    public:
        InvalidPeselLength(const string &pesel);
    private:

    };

    class InvalidPeselCharacter {
    public:
        InvalidPeselCharacter(const string &pesel);
    private:

    };

    class AcademiaDataValidationError {
    public:

    private:

    };
}

#endif //JIMP_EXERCISES_PESEL_H
