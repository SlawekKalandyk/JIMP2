//
// Created by slawek on 10.03.18.
//

#include "Polybius.h"
#include <string>
#include <iostream>

std::string PolybiusCrypt(std::string message) {
    std::string alphabet = "abcdefghiklmnopqrstuvwxyz";
    std::string crypted = "";

    int placeInTable = 0;

    for (int i = 0; i < message.size(); i++) {
        message[i] = tolower(message[i]);

        if (message[i] == 'j') {
            message[i] = 'i';
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
    std::string alphabet = "abcdefghiklmnopqrstuvwxyz";
    std::string decrypted = "";
    std::string alphabetTable[5][5]; // inna metoda niż szyfrowanie, nie wiedziałem jak ją przełożyć na deszyfrowanie
    int position1 = 0, position2 = 0;

    for (int i = 0; i < alphabet.size(); i++) {
        alphabetTable[i / 5][i % 5] = alphabet[i];
    }

    for (int i = 0; i < crypted.size(); i += 2) {
        position1 = atoi(crypted.substr(i, 1).c_str()); // std::stoi mi nie chciało działać, to użyłem atoi
        position2 = atoi(crypted.substr(i + 1, 1).c_str()); // choć w trochę dziwny sposób
        decrypted += alphabetTable[position1 - 1][position2 - 1];
    }

    return decrypted;
}
