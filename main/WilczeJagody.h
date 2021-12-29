#pragma once
#include "Roslina.h"

class Roslina;
class WilczeJagody : public Roslina
{
public:
	WilczeJagody(int x, int y, int id);
	void rozmnazanie();
	void akcja();
	int kolizja(Organizm* atakujacy);
	~WilczeJagody();
};