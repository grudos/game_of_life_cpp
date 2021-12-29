#pragma once
#include "Roslina.h"

class Roslina;
class Guarana : public Roslina
{
public:
	Guarana(int x, int y, int id);
	void rozmnazanie();
	void akcja();
	int kolizja(Organizm* atakujacy);
	~Guarana();
};