#pragma once
#include <vector>
#include <string>
#include "zadanie.h"

using namespace std;

bool isNumeric(string str);
void merge(vector<int>& table, int left, int middle, int right);
void merge_sort(vector<int>& table, int left, int right);
void malejaco(vector <zadanie*> lista, vector<zadanie*>& rozwiazanie);
void zapisz(int& liczba_procesow, int& liczba_zadan, vector<int>& lista_zadan);
