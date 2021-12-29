#pragma once
#include "Zwierze.h"

class Zwierze;
class Zolw : public Zwierze
{
public:
	Zolw(int x, int y, int id);
	void rozmnazanie();
	void akcja();
	int kolizja(Organizm* atakujacy);
	~Zolw();
};