#pragma once
#include <vector>

using namespace std;

class DNA //reprezentacja 1 osobnika
{
public:
	DNA();
	~DNA();
	vector<int> czasy;
	vector<int> rozwiazanie;
	int fitness;

private:

};