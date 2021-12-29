#pragma once
#include "Zwierze.h"

class Zwierze;
class Wilk : public Zwierze
{
public:
	Wilk(int x, int y, int id);
	void rozmnazanie();
	~Wilk();
};