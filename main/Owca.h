#pragma once
#include "Zwierze.h"

class Zwierze;
class Owca : public Zwierze
{
public:
	Owca(int x, int y, int id);
	void rozmnazanie();
	~Owca();
};