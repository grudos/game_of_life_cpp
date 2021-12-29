#pragma once
#include "Roslina.h"

class Roslina;
class BarszczSosnowskiego : public Roslina
{
public:
	BarszczSosnowskiego(int x, int y,int id);
	void rozmnazanie();
	void akcja();
	int kolizja(Organizm* atakujacy);
	~BarszczSosnowskiego();
};