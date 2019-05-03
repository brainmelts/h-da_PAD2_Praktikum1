// Titel: Mastermind Spiel
// Autor: Suayb Yurdakul
// Datum: 2019-04-23

#include<iostream>
#include<ctime>
using namespace std;

#include"MastermindDigits.h"

int main() {
    srand(time(nullptr));

    unsigned int mode = 0, counter = 0, computerNumber = 7777, myNumber = 7777;
    bool validDigit = 0;

    MastermindDigits computerDigits;

    while (mode != 1 && mode != 2) {
        cout << "Testen (1) oder Spielen(2): ";
        cin >> mode;
        cout << endl;
    }

    if (mode == 1) {
        while (!validDigit) {
            cout << "Testzahl eingeben: ";
            cin >> computerNumber;

            if (
                ((  computerNumber / 1000)              < 7) &&
                ((( computerNumber % 1000) / 100)       < 7) &&
                ((((computerNumber % 1000) % 100) / 10) < 7) &&
                ((((computerNumber % 1000) % 100) % 10) < 7)
                ) validDigit = 1;

            if (!validDigit) cout << "Testzahl ist ungültig.\n";
        }

        validDigit = 0;
        computerDigits = computerNumber;
    } else {
        computerDigits.makeDigitsToGuess();
    }

    while (computerDigits != myNumber) {
        while (!validDigit) {
            counter++;

            cout << counter << ". Zahl eingeben: ";
            cin >> myNumber;

            if (
                ((  myNumber / 1000)              < 7) &&
                ((( myNumber % 1000) / 100)       < 7) &&
                ((((myNumber % 1000) % 100) / 10) < 7) &&
                ((((myNumber % 1000) % 100) % 10) < 7)
                ) validDigit = 1;

            if (!validDigit) {
                cout << "Zahl ist ungültig.\n";
                counter--;
            }
        }

        cout << computerDigits.locationRight(myNumber) << " an der richtigen Stelle\nsonst " << computerDigits.locationWrong(myNumber) << " richtig.\n" << endl;

        validDigit = 0;
    }

    cout << "Gewonnen!" << endl;
    return 0;
}
