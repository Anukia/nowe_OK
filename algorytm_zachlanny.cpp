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
        wektory[i].push_back(0);
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


void zachlannie_2(int& procesy, int& zadania, vector<int>& lista, vector<vector<int>>& rozwiazanie) {
    merge_sort(lista, 0, lista.size() - 1);
    vector<vector<int>> wektory;
    for (int i = 0; i < procesy; i++) {
        wektory[i].push_back(0);
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