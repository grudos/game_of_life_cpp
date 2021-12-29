#pragma once
#include "Zwierze.h"

class Zwierze;
class Antylopa : public Zwierze
{
public:
	Antylopa(int x, int y, int id);
	void rozmnazanie();
	void akcja();
	int kolizja(Organizm* atakujacy);
	~Antylopa();
};