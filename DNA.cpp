#include "DNA.h"
#include <iostream>

using namespace std;

DNA::DNA(vector<zadanie*> p_posort_zad, int liczba_procesorow)
{
	for (int i = 0; i < p_posort_zad.size(); i++) posort_zad.push_back(p_posort_zad[i]);
	find_fitness(liczba_procesorow);
}

int DNA::find_fitness(int liczba_procesorow)
{
	int min_czas = 999999999999;
	int procesor = 0;
	vector<zadanie*>lista_zadan = posort_zad;
	vector<int> czasy(liczba_procesorow, 0);
	for (int i = 0; i < lista_zadan.size(); i++)
	{
		for (int j = 0; j < liczba_procesorow; j++)
		{
			if (min_czas > czasy[j])
			{
				procesor = j;
				min_czas = czasy[j];
			}
		}
		czasy[procesor] += lista_zadan[i]->czas;
		min_czas = czasy[procesor];
	}
	int max = 0;
	for (auto i : czasy)
	{
		if (max < i) max = i;
	}
	fitness = max;
	return fitness;
}