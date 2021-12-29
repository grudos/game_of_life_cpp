#pragma once
#include "Zwierze.h"

class Organizm;
class Zwierze;
class Czlowiek : public Zwierze
{
protected:
	int moc_tura=0;
	int aktywacja_mocy = 0;
	int dezaktywacja_tura = 5;
public:
	Czlowiek(int x, int y, int id);

	int getMocTura();
	int getAktywacjaMocy();
	int getDezaktywacjaTura();
	void setMocTura(int moc_tura);
	void setAktywacjaMocy(int aktywacja_mocy);
	void setDezaktywacjaTura(int dezaktywacja_tura);
	void mocAktywna();
	void rozmnazanie();
	void akcja();
	~Czlowiek();
};