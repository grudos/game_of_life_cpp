#pragma once
#include "Roslina.h"

class Roslina;
class Trawa : public Roslina
{
public:
	Trawa(int x, int y, int id);
	void rozmnazanie();
	void akcja();
	~Trawa();
};