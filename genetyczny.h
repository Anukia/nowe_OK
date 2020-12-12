//Pomysl 1 implementacja 1, komentarz og�lny:
//dzia�amy na li�cie posortowanych zada� (kt�re potem mo�naby przydzieli� do procesor�w)
//pokolenie startowe - 1 potomek z zach�annego (sortowanie malej�ce) reszta random
//crossover -> bierzemy dw�ch rodzic�w, a nastepnie tworzymy wektor z losowo wygenerowanymi 0 lub 1,
//		je�li jest 0, bierzemy [i] proces od rodzica1, je�li 1 - od rodzica2.
//		W przypadku gdy [i] zadanie zosta�o ju� przydzielone wcze�niej, zostawiamy nullptr w [i] indeksie rozwi�zania.
//		Dopiero potem losowo przydzielamy w te miejsca (nullptr) pozosta�e, nieprzydzielone zadania.
#pragma once
#include "zadanie.h"
#include "DNA.h"
#include <vector>

using namespace std;

void genetyczny(int procesy, int zadania, vector<int> lista);
void create_rnd(vector<zadanie*> lista_zadan, vector<zadanie*>& rozwiazanie);
void crossover(DNA* rodzic1, DNA* rodzic2, vector<zadanie*>&dziecko);
void kazdepokoleniemawlasnyczas(vector<DNA*> stare_pokolenie, vector<DNA*>& nowe_pokolenie, int liczba_procesorow);
DNA* najlepszywpokoleniu(vector<DNA*> pokolenie);