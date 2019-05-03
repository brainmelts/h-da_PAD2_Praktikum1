#include "MastermindDigits.h"
#include <array>

MastermindDigits::MastermindDigits() : MastermindDigits(0) {}

MastermindDigits::MastermindDigits(unsigned int playerDigits) {
    size = 4;
    digits = new unsigned int[4] {};

    for (unsigned int i = 0; i < 4; i++) {
        digits[i] = static_cast<unsigned int>(playerDigits % 10);
        playerDigits = playerDigits / 10;
    }
}

MastermindDigits::~MastermindDigits() {
    delete[] digits;
}

MastermindDigits::MastermindDigits(const MastermindDigits& d) :digits(new unsigned int[4]{}) {
    size = 4;

    for (unsigned int i = 0; i < 4; i++) digits[i] = d.digits[i];
}

// ---

void MastermindDigits::makeDigitsToGuess() {
    digits = new unsigned int[4];

    for (unsigned int i = 0; i < 4; ++i) digits[i] = 1 + (rand() % 6);
}

unsigned int MastermindDigits::locationRight(const MastermindDigits m) const {
    unsigned int right = 0;

    for (unsigned int i = 0; i < 4; i++) if (digits[i] == m.digits[i]) right++;

    return right;
}

unsigned int MastermindDigits::locationWrong(const MastermindDigits playerDigits) const {
    unsigned int* copyDigits = new unsigned int[4] {};

    for (unsigned int i = 0; i < 4; i++) copyDigits[i] = digits[i];

    for (unsigned int i = 0; i < 4; i++) {
        if (playerDigits.digits[i] == digits[i]) {
            copyDigits[i] = 0;
            playerDigits.digits[i] = 0;
        }
    }

    for (unsigned int i = 0; i < 4; i++) {
        unsigned int toCheck = playerDigits.digits[i];

        for (unsigned int j = i + 1; j < 4; j++) if (playerDigits.digits[j] == toCheck) playerDigits.digits[j] = 0;
    }

    unsigned int wrongPlaceDigits = 0;

    for (unsigned int i = 0; i < 4; i++) {
        for (unsigned int j = 0; j < 4; j++) {
            if (i != j) {
                if (playerDigits.digits[i] == copyDigits[j] && playerDigits.digits[i] != 0) {
                    wrongPlaceDigits++;
                }
            }
        }
    }

    return wrongPlaceDigits;
}

// ---

MastermindDigits::operator unsigned int() const {
    unsigned int number = 0, factor = 1;

    for (unsigned int i = 0; i < 4; i++) {
        number = number + digits[i] * factor;
        factor = factor * 10;
    }

    return number;
}

const MastermindDigits& MastermindDigits::operator=(const MastermindDigits& right) {
    if (&right != this) {
        if (size != right.size) {
            delete[] digits;
            size = right.size;
            digits = new unsigned int[size];
        }

        for (unsigned int i = 0; i < size; ++i) digits[i] = right.digits[i];
    }

    return *this;
}