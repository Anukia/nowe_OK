#include "DNA.h"

void DNA::find_fitness()
{
	for (auto i : czasy)
		if (i > fitness)
			fitness = i;
}

DNA::DNA(vector<int> p_czasy, vector<int> p_rozwiazanie)
{
	for (auto i : p_czasy) czasy.push_back(i);
	for (auto i : p_rozwiazanie) rozwiazanie.push_back(i);
	find_fitness();
}

DNA::~DNA()
{
}