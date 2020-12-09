#include <iostream>
#include <string>
#include <vector>
#include "generator.h"
#include "plik_i_recznie.h"
#include "funkcje.h"
#include "algorytm_zachlanny.h"
using namespace std;

int main()
{
    vector<int> lista_zadan;
    vector<vector<int>> optymalne_rozwiazanie; // tylko wykorzystywane podczas generowania instancji.
    vector<vector<int>> zachlanne_rozwiazanie;
    string wybor;
    int liczba_procesow = 0;
    int liczba_zadan = 0;
    bool pokaz_optymalne_rozwiazanie = false;
    cout << "1 = Generator." << endl;
    cout << "2 = Wprowadz dane recznie." << endl;
    cout << "3 = Pobierz dane z pliku." << endl;
    cout << "4 = Wyjdz z programu." << endl;
    do {
        cout << "Wybierz: "; getline(cin, wybor); cout << endl;
        if (wybor == "1") {
            generator(liczba_procesow, liczba_zadan, lista_zadan, optymalne_rozwiazanie);
            pokaz_optymalne_rozwiazanie = true;
        }
        else if (wybor == "2") {
            recznie_dane(liczba_procesow, liczba_zadan, lista_zadan);
        }
        else if (wybor == "3") {
            dane_z_pliku(liczba_procesow, liczba_zadan, lista_zadan);
            /*
            cout << liczba_procesow << endl << liczba_zadan << endl;
            for(int i = 0; i < lista_zadan.size(); i ++){
                cout << lista_zadan[i] << endl;
            }
            */
        }
        else if (wybor == "4") {
            return 0;
        }
        else {
            cout << "Nie istnieje taka opcja." << endl;
        }
    } while (wybor != "1" and wybor != "2" and wybor != "3");
    cout << "1 = Algorytm zachlanny wykorzystywujac sortowanie rosnaco." << endl;
    cout << "2 = Algorytm zachlanny wykorzystywujac sortowanie malejaco." << endl;
    cout << "3 = Wyjdz z programu." << endl;
    do {
        cout << "Wybierz: "; getline(cin, wybor); cout << endl;
        if (wybor == "1") {
            zachlannie_1(liczba_procesow, liczba_zadan, lista_zadan, zachlanne_rozwiazanie);
        }
        else if (wybor == "2") {
            zachlannie_2(liczba_procesow, liczba_zadan, lista_zadan, zachlanne_rozwiazanie);
        }
        else if (wybor == "3") {
            return 0;
        }
        else {
            cout << "Nie istnieje taka opcja." << endl;
        }
    } while (wybor != "1" and wybor != "2");

    cout << "Zachlanne rozwiazanie:" << endl;
    if (liczba_procesow < liczba_zadan) {
        int max_wynik = 0;
        for (int i = 0; i < zachlanne_rozwiazanie.size(); i++) {
            cout << i + 1 << ". ";
            for (int j = 1; j < zachlanne_rozwiazanie[i].size(); j++) {
                cout << zachlanne_rozwiazanie[i][j] << " ";
            }
            if (zachlanne_rozwiazanie[i][0] > max_wynik) {
                max_wynik = zachlanne_rozwiazanie[i][0];
            }
            cout << endl << "Suma: " << zachlanne_rozwiazanie[i][0] << endl;
        }
        cout << "Najwiekszy wynik to: " << max_wynik << endl;
    }
    else {
        int max_wynik = 0;
        for (int i = 0; i < liczba_zadan; i++) {
            cout << i + 1 << ". ";
            for (int j = 1; j < zachlanne_rozwiazanie[i].size(); j++) {
                cout << zachlanne_rozwiazanie[i][j] << " ";
            }
            if (zachlanne_rozwiazanie[i][0] > max_wynik) {
                max_wynik = zachlanne_rozwiazanie[i][0];
            }
            cout << endl << "Suma: " << zachlanne_rozwiazanie[i][0] << endl;
        }
        cout << "Najwiekszy wynik to: " << max_wynik << endl;
    }

    if (pokaz_optymalne_rozwiazanie) {
        cout << endl << "Optymalne rozwiazanie:" << endl;
        int max_wynik = 0;
        for (int i = 0; i < optymalne_rozwiazanie.size(); i++) {
            int suma = 0;
            cout << i + 1 << ". ";
            for (int j = 0; j < optymalne_rozwiazanie[i].size(); j++) {
                cout << optymalne_rozwiazanie[i][j] << " ";
                suma += optymalne_rozwiazanie[i][j];
            }
            if (suma > max_wynik) {
                max_wynik = suma;
            }
            cout << endl << "Suma: " << suma << endl;
        }
        cout << "Najwiekszy wynik to: " << max_wynik << endl;
    }

    return 0;
}