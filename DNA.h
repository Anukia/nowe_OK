#pragma once
#include <vector>
#include "zadanie.h"

using namespace std;

class DNA //reprezentacja 1 osobnika
{
public:
	DNA(vector<zadanie*> p_posort_zad, int liczba_procesorow);
	~DNA();
	
	vector<zadanie*> posort_zad;
	int fitness;
	
	int find_fitness(int liczba_procesorow);	//przyporz�dkowuje zadania do procesora i wyznacza dopasowanie (najd�u�szy czas);
};