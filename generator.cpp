#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include "funkcje.h"
using namespace std;

void za_duzo(int& suma, vector<int>& wektor) {
    int ile_zadan = wektor.size();
    int ktory_proces = 0;
    while (suma != 0) {
        if (wektor[ktory_proces % ile_zadan] > 1) {
            wektor[ktory_proces % ile_zadan]--;
            suma++;
        }
        ktory_proces++;
    }
}

void za_malo(int& suma, vector<int>& wektor) {
    int ile_zadan = wektor.size();
    int ktory_proces = 0;
    while (suma != 0) {
        if (wektor[ktory_proces % ile_zadan] < 99) {
            wektor[ktory_proces % ile_zadan]++;
            suma--;
        }
        ktory_proces++;
    }
}

void generator(int& procesy, int& zadania, vector<int>& wektor, vector<vector<int>>& rozwiazanie) {
    string wartosci;
    int min_dlugosc = 1, max_dlugosc = 99;
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

    srand(time(0));
    int losowe_wartosci;
    if (procesy >= zadania) {
        vector<int> temp;
        for (int i = 0; i < zadania; i++) {
            losowe_wartosci = min_dlugosc + rand() % (max_dlugosc - min_dlugosc + 1);
            wektor.push_back(losowe_wartosci);
            temp.push_back(losowe_wartosci);
            rozwiazanie.push_back(temp);
            temp.pop_back();
        }
    }
    else {
        int srednia_zadan_na_proces = zadania / procesy;
        int reszta_zadan_na_proces = zadania % procesy;
        int srednia_czasu_na_proces = ((max_dlugosc + min_dlugosc) / 2) * (zadania / procesy);
        for (int i = 0; i < procesy; i++) {
            int suma = srednia_czasu_na_proces;
            int dodatkowe_zadanie = 0;
            if (reszta_zadan_na_proces > 0) {
                dodatkowe_zadanie = 1;
                reszta_zadan_na_proces--;
            }
            vector<int> helper;
            for (int j = 0 - dodatkowe_zadanie; j < srednia_zadan_na_proces; j++) {
                losowe_wartosci = min_dlugosc + rand() % (max_dlugosc - min_dlugosc + 1);
                helper.push_back(losowe_wartosci);
                suma = suma - losowe_wartosci;
            }
            if (suma > 0) {
                za_malo(suma, helper);
            }
            else if (suma < 0) {
                za_duzo(suma, helper);
            }
            rozwiazanie.push_back(helper);
            for (int j = 0; j < helper.size(); j++) {
                wektor.push_back(helper[j]);
            }
        }
    }
}
