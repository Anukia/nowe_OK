#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "funkcje.h"
using namespace std;

void recznie_dane(int& procesy, int& zadania, vector<int>& wektor) {
    string wartosci;
    do {
        cout << "Wprowadz liczbe procesow: "; getline(cin, wartosci); cout << endl;
        if (!(isNumeric(wartosci)) or wartosci == "") {
            cout << "To nie jest liczba. Sprobuj jeszcze raz." << endl;
        }
    } while (!(isNumeric(wartosci)) or wartosci == "");
    procesy = stoi(wartosci);
    do {
        cout << "Wprowadz liczbe zadan: "; getline(cin, wartosci); cout << endl;
        if (!(isNumeric(wartosci)) or wartosci == "") {
            cout << "To nie jest liczba. Sprobuj jeszcze raz." << endl;
        }
    } while (!(isNumeric(wartosci)) or wartosci == "");
    zadania = stoi(wartosci);
    for (int i = 0; i < zadania; i++) {
        do {
            cout << "Wprowadz " << i + 1 << " zadanie: "; getline(cin, wartosci); cout << endl;
            if (!(isNumeric(wartosci)) or wartosci == "") {
                cout << "To nie jest liczba. Sprobuj jeszcze raz." << endl;
            }
        } while (!(isNumeric(wartosci)) or wartosci == "");
        wektor.push_back(stoi(wartosci));
    }
}

void dane_z_pliku(int& procesy, int& zadania, vector<int>& wektor) {
    fstream plik;
    string nazwa_pliku;
    do {
        cout << "Wprowadz sciezke do pliku: "; getline(cin, nazwa_pliku); cout << endl;
        plik.open(nazwa_pliku, ios::in);
        if (plik.good() == false) {
            cout << "Nie istnieje taki plik, sprobuj jeszcze raz." << endl;
        }
    } while (plik.good() == false);
    plik >> procesy;
    plik >> zadania;
    int dane;
    for (int i = 0; i < zadania; i++) {
        plik >> dane;
        wektor.push_back(dane);
    }
}