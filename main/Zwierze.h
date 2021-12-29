#pragma once
#include "Organizm.h"

class Organizm;
class Zwierze : public Organizm
{
public:
	void akcja();
	virtual void rozmnazanie() = 0;
	virtual int kolizja(Organizm* atakujacy);
	virtual ~Zwierze();
};