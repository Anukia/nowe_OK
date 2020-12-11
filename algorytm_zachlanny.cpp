#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "funkcje.h"
using namespace std;

void zachlannie_1_genetic(vector<int> lista, vector<int>& rozwiazanie)
{
    merge_sort(lista, 0, lista.size() - 1);
}