#pragma once
#include "Zwierze.h"

class Zwierze;
class Lis : public Zwierze
{
public:
	Lis(int x, int y, int id);
	void rozmnazanie();
	void akcja();
	~Lis();
};