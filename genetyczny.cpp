#include "genetyczny.h"
#include "algorytm_zachlanny.h"
#include "DNA.h"
#include "zadanie.h"
#include <vector>

using namespace std;

int genetyczny(int liczba_procesorow, int liczba_zadan, vector<int> lista)
{
	vector<DNA*> stare_pokolenie;
	vector<DNA*> nowe_pokolenie;
	vector<zadanie*> lista_zadan;
	for (int i = 0; i < lista.size(); i++) lista_zadan.push_back(new zadanie(i, lista[i]));

	

	return 0;
}