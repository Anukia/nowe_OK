#include "genetyczny.h"
#include "algorytm_zachlanny.h"
#include "DNA.h"
#include <vector>

using namespace std;

int genetyczny(int l_procesorow, int zadania, vector<int> lista)
{
	vector<DNA*> stare_pokolenie;
	vector<DNA*> nowe_pokolenie;
	
	vector<int> czasy_tmp, rozwiazanie_tmp;
	zachlannie_1_genetic(l_procesorow, zadania, lista, czasy_tmp, rozwiazanie_tmp);
	stare_pokolenie.push_back(new DNA(czasy_tmp, rozwiazanie_tmp));
	czasy_tmp.clear(); rozwiazanie_tmp.clear();
	zachlannie_2_genetic(l_procesorow, zadania, lista, czasy_tmp, rozwiazanie_tmp);
	stare_pokolenie.push_back(new DNA(czasy_tmp, rozwiazanie_tmp));


	return 0;
}