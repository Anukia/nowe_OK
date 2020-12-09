#pragma once
#include <vector>
#include <string>

using namespace std;

bool isNumeric(string str);
void merge(vector<int>& table, int left, int middle, int right);
void merge_sort(vector<int>& table, int left, int right);