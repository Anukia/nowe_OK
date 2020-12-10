#include "genetyczny.h"
#include "algorytm_zachlanny.h"
#include "DNA.h"
#include <vector>

using namespace std;

int genetyczny(int l_procesorow, int zadania, vector<int> lista)
{
	vector<DNA>* stare_pokolenie;
	vector<DNA>* nowe_pokolenie;
	DNA* obiekt_tmp = new DNA();
	zachlannie_1_genetic(l_procesorow, zadania, lista, obiekt_tmp->czasy, obiekt_tmp->rozwiazanie);
	return 0;
}