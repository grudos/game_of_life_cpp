#pragma once
#include "Roslina.h"

class Roslina;
class Mlecz : public Roslina
{
public:
	Mlecz(int x, int y, int id);
	void rozmnazanie();
	void akcja();
	~Mlecz();
};