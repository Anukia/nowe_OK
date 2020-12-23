#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "funkcje.h"
#include "algorytm_zachlanny.h"
#include "zadanie.h"
using namespace std;

void zachlannie_1_genetic(vector<int> lista, vector<zadanie*> &rozwiazanie)
{
    merge_sort(lista, 0, lista.size() - 1);
    for (int i = lista.size() - 1; i >= 0; i--) rozwiazanie.push_back(new zadanie(i, lista[i]));
}