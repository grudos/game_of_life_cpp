#pragma once
#include <string>
#include "Swiat.h"
using namespace std;

class Swiat;
class Organizm
{
protected:
	int sila;
	int inicjatywa;
	int x;
	int y;
	int poprzedni_x;
	int poprzedni_y;
	int id;
	string nazwa;
	char symbol;
	Swiat* swiat;
public:
	Organizm();
	void setX(int x);
	void setY(int y);
	void setSwiat(Swiat* swiat);
	void setOrganizmSila(int sila);
	void setOrganizmInicjatywa(int inicjatywa);
	void setOrganizmPoprzedniX(int poprzedni_x);
	void setOrganizmPoprzedniY(int poprzedni_y);
	void setOrganizmSymbol(char symbol);
	void setOrganizmNazwa(string nazwa);
	int getX();
	int getY();
	int getID();
	int getPoprzedniX();
	int getPoprzedniY();
	char getSymbol();
	string getNazwa();
	int getInicjatywa();
	int getOrganizmSila();
	virtual void rozmnazanie() = 0;
	virtual void akcja() = 0;
	virtual int kolizja(Organizm* atakujacy);
	virtual ~Organizm();
};