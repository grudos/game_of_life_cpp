#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include <conio.h>
#include <stdio.h>
#include "Organizm.h"
using namespace std;

class Organizm;
class Swiat
{
private:
	int szerokosc;
	int wysokosc;
	int zapis;
	int ID_swiata;
	string informacje[10];
	int linie_informacje = 0;
	vector<vector<char>> plansza;
	vector<Organizm*> organizmy;
public:
	Swiat(int szerokosc, int wysokosc);
	void setZapis(int zapis);
	int getSzerokosc();
	int getWysokosc();
	int getZapis();
	int getID_swiata();
	void setID_swiata(int ID_swiata);
	void dajInformacje(string tekst);
	void wypiszInformacje(string informacje);
	int getSila(int x, int y);
	void smiercOrganizmu(int id);
	void smiercOrganizmu_x_y(int x, int y);
	void smiercOrganizmuBarszcz(int x, int y);
	void stworzOrganizm(Organizm* nowy);
	void stworzOrganizmPlik(char symbol, int sila, int inicjatywa, int x, int y, int poprzedni_x, int poprzedni_y, int id);
	void stworzCzlowiekPlik(char symbol, int sila, int inicjatywa, int x, int y, int poprzedni_x, int poprzedni_y, int id, int moc_tura, int aktywacja_mocy, int dezaktywacja_tura);
	void stworzOrganizmy();
	int czyZajete(int x, int y);
	void wykonajTure();
	void stworzSwiat();
	void rysujSwiat();
	~Swiat();
};

int dlaInicjatywy(Organizm* organizm_1, Organizm* organizm_2);