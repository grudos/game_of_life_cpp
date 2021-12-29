#pragma once
#include "Organizm.h"

class Organizm;
class Roslina : public Organizm
{
public:
	void akcja() = 0;
	virtual void rozmnazanie() = 0;
	virtual int kolizja(Organizm* atakujacy);
	virtual ~Roslina();
};