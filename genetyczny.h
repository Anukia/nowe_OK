//Pomysl 1 implementacja 1, komentarz ogólny:
//dzia³amy na liœcie posortowanych zadañ (które potem mo¿naby przydzieliæ do procesorów)
//pokolenie startowe - 1 potomek z zach³annego (sortowanie malej¹ce) reszta random
//crossover -> bierzemy dwóch rodziców, a nastepnie tworzymy wektor z losowo wygenerowanymi 0 lub 1,
//		jeœli jest 0, bierzemy [i] proces od rodzica1, jeœli 1 - od rodzica2.
//		W przypadku gdy [i] zadanie zosta³o ju¿ przydzielone wczeœniej, zostawiamy nullptr w [i] indeksie rozwi¹zania.
//		Dopiero potem losowo przydzielamy w te miejsca (nullptr) pozosta³e, nieprzydzielone zadania.
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