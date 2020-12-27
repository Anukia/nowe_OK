#pragma once
#include <vector>
#include "zadanie.h"

using namespace std;

class DNA //reprezentacja 1 osobnika
{
public:
	DNA(vector<zadanie*> p_posort_zad, int liczba_procesorow);
	
	vector<zadanie*> posort_zad;
	int fitness;
    ~DNA();
	int find_fitness(int liczba_procesorow);	//przyporz¹dkowuje zadania do procesora i wyznacza dopasowanie (najd³u¿szy czas);
};
