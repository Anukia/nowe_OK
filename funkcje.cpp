#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "zadanie.h"
using namespace std;

bool isNumeric(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (isdigit(str[i]) == false)
            return false;
    }
    return true;
}

void merge(vector<int>& table, int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;
    int* L = new int[n1];
    int* R = new int[n2];

    for (i = 0; i < n1; i++)
    {
        L[i] = table[left + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = table[middle + 1 + j];
    }

    i = 0, j = 0, k = 0;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            table[left + k] = L[i];
            i++;
        }
        else
        {
            table[left + k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        table[left + k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        table[left + k] = R[j];
        j++;
        k++;
    }
    delete[] L;
    delete[] R;
}

void merge_sort(vector<int>& table, int left, int right) {
    int middle;
    if (left < right)
    {
        middle = left + (right - left) / 2;
        merge_sort(table, left, middle);
        merge_sort(table, middle + 1, right);
        merge(table, left, middle, right);
    }
}

void malejaco(vector <zadanie*> lista, vector<zadanie*> &rozwiazanie)
{
    zadanie* tmp;
    for (auto i : lista) rozwiazanie.push_back(i);
    for (int i = 0; i < lista.size()-1; i++)
    {
        for(int j=i+1; j<lista.size(); j++)
            if (rozwiazanie[j]->czas > rozwiazanie[i]->czas)
            {
                tmp = rozwiazanie[i];
                rozwiazanie[i] = rozwiazanie[j];
                rozwiazanie[j] = tmp;
            }
    }
}

void zapisz(int& liczba_procesow, int& liczba_zadan, vector<int>& lista_zadan){
    fstream plik;
    string nazwa_pliku;
    cout << "Podaj sciezke do pliku: "; getline(cin, nazwa_pliku); cout << endl;
    plik.open(nazwa_pliku, ios::out);
    plik << liczba_procesow << "\n" << liczba_zadan << "\n";
    for(auto i : lista_zadan) plik << i << "\n";
    cout << "Utworzono plik\n\n";

}
