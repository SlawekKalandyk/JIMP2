//
// Created by slawek on 24.04.18.
//

#include "Pesel.h"

namespace academia {

    Pesel::Pesel(const string &pesel) {

    }

    InvalidPeselChecksum::InvalidPeselChecksum(const string &pesel) {

    }

    InvalidPeselLength::InvalidPeselLength(const string &pesel) {
        if(pesel.size() != 11)
            throw std::invalid_argument("Wrong length");
    }

    InvalidPeselCharacter::InvalidPeselCharacter(const string &pesel) {
        regex characterCheck();
    }
}
/*
 1 i 2 : 00 - 99
 3 i 4 : 01 - 12
 5 i 6 : 01 - 31 zależnie od miesiąca ?
 7, 8, 9, 10 - numer serii, 10 zależnie od płci parzysta/nieparzysta
 11 - cyfra kontrolna

 tylko cyfry
 */