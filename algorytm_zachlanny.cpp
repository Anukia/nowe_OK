#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "funkcje.h"
using namespace std;

void zachlannie_1(int& procesy, int& zadania, vector<int>& lista, vector<vector<int>>& rozwiazanie) {
    merge_sort(lista, 0, lista.size() - 1);
    vector<vector<int>> wektory;
    for (int i = 0; i < procesy; i++) {
        vector<int> tmp;
        tmp.push_back(0);
        wektory.push_back(tmp);
    }
    for (int i = 0; i < lista.size(); i++) {
        int indeks = 0, min_wartosc = wektory[0][0];
        for (int j = 0; j < procesy; j++) {
            if (min_wartosc > wektory[j][0]) {
                indeks = j; min_wartosc = wektory[j][0];
            }
        }
        wektory[indeks].push_back(lista[i]);
        wektory[indeks][0] += lista[i];
    }

    for (int i = 0; i < procesy; i++)
        rozwiazanie.push_back(wektory[i]);
}

void zachlannie_1_genetic(int l_procesorow, int zadania, vector<int> lista, vector<int>& czasy, vector<int>& rozwiazanie)
{
    merge_sort(lista, 0, lista.size() - 1);
    for (int i = 0; i < l_procesorow; i++) czasy.push_back(0);

    int min_czas = 99999999999; int procesor = 0;
    for (int i = 0; i < lista.size(); i++)
    {
        for (int j = 0; j<l_procesorow; j++) 
            if (min_czas > czasy[j])
            {
                min_czas = czasy[j];
                procesor = j;
            }
        rozwiazanie.push_back(procesor);
        czasy[procesor] += lista[i];
        min_czas = czasy[procesor];
    }
    cout << "rozwiazanie:" << endl;
    for (auto i : rozwiazanie) cout << i << endl;
    cout << "czasy" << endl;
    for (auto i : czasy) cout << i << endl;
}


void zachlannie_2(int& procesy, int& zadania, vector<int>& lista, vector<vector<int>>& rozwiazanie) {
    merge_sort(lista, 0, lista.size() - 1);
    vector<vector<int>> wektory;
    for (int i = 0; i < procesy; i++) {
        vector<int> tmp;
        tmp.push_back(0);
        wektory.push_back(tmp);
    }
    for (int i = lista.size() - 1; i >= 0; i--) {
        int indeks = 0, min_wartosc = wektory[0][0];
        for (int j = 0; j < procesy; j++) {
            if (min_wartosc > wektory[j][0]) {
                indeks = j; min_wartosc = wektory[j][0];
            }
        }
        wektory[indeks].push_back(lista[i]);
        wektory[indeks][0] += lista[i];
    }

    for (int i = 0; i < procesy; i++)
        rozwiazanie.push_back(wektory[i]);
}

void zachlannie_2_genetic(int l_procesorow, int zadania, vector<int> lista, vector<int>& czasy, vector<int>& rozwiazanie)
{
    merge_sort(lista, 0, lista.size() - 1);
    for (int i = 0; i < l_procesorow; i++) czasy[i] = 0;

    int min_czas = 99999999999; int procesor = 0;
    for (int i = lista.size() - 1; i >= 0; i--)
    {
        for (int j = 0; j < l_procesorow; j++)
            if (min_czas > czasy[j])
            {
                min_czas = czasy[j];
                procesor = j;
            }
        rozwiazanie.push_back(procesor);
        czasy[procesor] += lista[i];
        min_czas = czasy[procesor];
    }
    cout << "rozwiazanie:" << endl;
    for (auto i : rozwiazanie) cout << i << endl;
    cout << "czasy" << endl;
    for (auto i : czasy) cout << i << endl;
}