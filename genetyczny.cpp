// pooptymalizowac ewentulanie + zrobic usuwanie obiektow + pobawic sie z mutacjami

#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "genetyczny.h"
#include "algorytm_zachlanny.h"
#include "DNA.h"
#include "funkcje.h"
#include <chrono>

using namespace std;
//----------------------------------------------------------------------------------------------

void create_rnd(vector<zadanie*> lista_zadan, vector<zadanie*>& rozwiazanie)
{
	vector <zadanie*> pozostale;
	for (auto i : lista_zadan) pozostale.push_back(i);

	do
    {
		int random = rand()%pozostale.size();
		rozwiazanie.push_back(pozostale[random]);
		pozostale.erase(pozostale.begin()+random);
	} while (pozostale.size()!=0);
}

void crossover(DNA* rodzic1, DNA* rodzic2, vector<zadanie*>&dziecko)
{
	vector<int> ktory;	//0 - bierzemy od rodzic 1, 2;
	vector<int> puste;
	vector<zadanie*> pozostale;
	vector<zadanie*> rozwiazanie;
	int l_zadan = rodzic1->posort_zad.size();
	vector<int>wdziecku(l_zadan, 0);
    if (rand() % 100 == 1) create_rnd(rodzic1->posort_zad, dziecko);
    else{
        for (int i = 0; i < l_zadan; i++)
        {
            dziecko.push_back(nullptr);
            ktory.push_back(rand() % 2);
            if (ktory[i] == 1)
            {
                if (!wdziecku[rodzic2->posort_zad[i]->nr])
                {
                    dziecko[i] = rodzic2->posort_zad[i];
                    wdziecku[rodzic2->posort_zad[i]->nr] = 1;
                }
                else puste.push_back(i);
            }
            else
            {
                if (!wdziecku[rodzic1->posort_zad[i]->nr])
                {
                    dziecko[i] = rodzic1->posort_zad[i];
                    wdziecku[rodzic1->posort_zad[i]->nr] = 1;
                }
                else puste.push_back(i);
            }

        }

        for (int i = 0; i < l_zadan; i++)
            if (wdziecku[rodzic1->posort_zad[i]->nr] == 0) pozostale.push_back(rodzic1->posort_zad[i]);
        if (pozostale.size()) malejaco(pozostale, rozwiazanie);
        for (int i = 0; i < rozwiazanie.size(); i++) dziecko[puste[i]] = rozwiazanie[i];
    }
}

DNA* najlepszywpokoleniu(vector<DNA*> pokolenie)
{
    if (pokolenie.size() == 0) return nullptr;
    int min = 99999999;
	DNA* best = pokolenie[0];
	for (int i = 0; i < pokolenie.size(); i ++)
	{
		if ((pokolenie[i]->fitness) < min)
		{
			best = pokolenie[i];
			min = best->fitness;
		}
	}
	return best;
}

void kazdepokoleniemawlasnyczas(vector<DNA*> stare_pokolenie, vector<DNA*>& nowe_pokolenie, int liczba_procesorow) //spróbuj przeczytaæ nie œpiewaj¹c challenge
{
	vector<zadanie*> lista_dla_dziecka;
	DNA* najlepszystary = najlepszywpokoleniu(stare_pokolenie);
	DNA* dziecko;
	for (int i = 0; i < stare_pokolenie.size(); i++)
	{
        if (stare_pokolenie[i] == najlepszystary) lista_dla_dziecka = najlepszystary->posort_zad;
        else crossover(najlepszystary, stare_pokolenie[i], lista_dla_dziecka);
        dziecko = new DNA(lista_dla_dziecka, liczba_procesorow);
		nowe_pokolenie.push_back(dziecko);
		lista_dla_dziecka.clear();
	}
}

void przepisaniepokolen(vector<DNA*>& stare_pokolenie, vector<DNA*> nowe_pokolenie)
{
    for (int i = 0; i < stare_pokolenie.size(); i++) stare_pokolenie[i] = nowe_pokolenie[i];
}

void genetyczny(int liczba_procesorow, int liczba_zadan, vector<int> lista, int liczba_w_pokoleniu)
{
	srand(time(nullptr));
	vector<DNA*> stare_pokolenie;
	vector<DNA*> nowe_pokolenie;
	vector<zadanie*> lista_zadan;
    zachlannie_1_genetic(lista, lista_zadan);
    stare_pokolenie.push_back(new DNA(lista_zadan, liczba_procesorow));
	vector<zadanie*> rand_tmp;
    for (int i = 0; i < liczba_w_pokoleniu - 1; i++)
	{
		create_rnd(lista_zadan, rand_tmp);
		stare_pokolenie.push_back(new DNA(rand_tmp, liczba_procesorow));
		rand_tmp.clear();
	}
    int wynik_nowe_pokolenie, wynik_stare_pokolenie = najlepszywpokoleniu(stare_pokolenie)->find_fitness(liczba_procesorow);
    auto start = chrono::high_resolution_clock::now();
    cout << "Pokolenie 0: " << wynik_stare_pokolenie << endl;
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<float> duration = end - start;
    int i = 1;
    while (duration.count() < 10.0f){
        kazdepokoleniemawlasnyczas(stare_pokolenie, nowe_pokolenie, liczba_procesorow);
        wynik_nowe_pokolenie = najlepszywpokoleniu(nowe_pokolenie)->fitness;
        if (wynik_nowe_pokolenie < wynik_stare_pokolenie){
        cout << "Pokolenie " << i + 1 << ": " << wynik_nowe_pokolenie <<", w czasie: " <<duration.count() << "s\n";
        }
        wynik_stare_pokolenie = wynik_nowe_pokolenie;
        przepisaniepokolen(stare_pokolenie, nowe_pokolenie);
        nowe_pokolenie.clear();
        end = chrono::high_resolution_clock::now();
        duration = end - start;
        i++;
    }
    cout <<"\nLiczba pokolen: " << i <<"\n";
    cout <<"Czas trwania algorytmu: " << duration.count() << "s\n";
    cout << "Najlepszy wynik: " << najlepszywpokoleniu(stare_pokolenie)->fitness << endl;
}
