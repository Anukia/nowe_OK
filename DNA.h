#pragma once
#include <vector>

using namespace std;

class DNA //reprezentacja 1 osobnika
{
public:
	DNA(vector<int> p_czasy, vector<int> p_rozwiazanie);
	~DNA();
	vector<int> czasy;
	vector<int> rozwiazanie;
	int fitness = 0;

private:
	void find_fitness();
};