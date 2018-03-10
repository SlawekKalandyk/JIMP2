//
// Created by slawek on 10.03.18.
//

#include "Polybius.h"
#include <string>
#include <math.h>

std::string PolybiusCrypt(std::string message) {
    std::string alphabet = "ABCDEFGHIKLMNOPQRSTUVWXYZ";
    std::string crypted = "";

    int placeInTable = 0;

    for (int i = 0; i < message.size(); i++) {
        message[i] = toupper(message[i]);

        if (message[i] == 'J') {
            message[i] = 'I';
        }

        for (int j = 0; j < alphabet.size(); j++) {
            if (message[i] == alphabet[j]) {
                placeInTable = (j / 5 + 1) * 10 + (j % 5 + 1);
                crypted += std::to_string(placeInTable);
            }
        }
    }

    return crypted;
}

std::string PolybiusDecrypt(std::string crypted) {

}
