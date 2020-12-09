#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
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