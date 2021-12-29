#include "Czlowiek.h"
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

Czlowiek::Czlowiek(int x, int y, int id)
{
	this->sila = 5;
	this->inicjatywa = 4;
	this->x = x;
	this->y = y;
	this->id = id;
	this->symbol = 'C';
	this->nazwa = "Czlowiek";
}

int Czlowiek::getMocTura()
{
	return moc_tura;
}

int Czlowiek::getAktywacjaMocy()
{
	return aktywacja_mocy;
}

int Czlowiek::getDezaktywacjaTura()
{
	return dezaktywacja_tura;
}

void Czlowiek::setMocTura(int moc_tura)
{
	this->moc_tura= moc_tura;
}

void Czlowiek::setAktywacjaMocy(int aktywacja_mocy)
{
	this->aktywacja_mocy= aktywacja_mocy;
}

void Czlowiek::setDezaktywacjaTura(int dezaktywacja_tura)
{
	this->dezaktywacja_tura= dezaktywacja_tura;
}


void Czlowiek::mocAktywna()
{
	int zniszczenie = 0;
	if (y > 0 && swiat->czyZajete(x, y - 1) == 1)
	{
		swiat->smiercOrganizmu_x_y(x, y - 1);
		swiat->dajInformacje(this->nazwa + " niszczy organizm obok dzieki CALOPALENIU " + '\n');
	}
	if (y < swiat->getWysokosc() - 1 && swiat->czyZajete(x, y + 1) == 1)
	{
		swiat->smiercOrganizmu_x_y(x, y + 1);
		swiat->dajInformacje(this->nazwa + " niszczy organizm obok dzieki CALOPALENIU " + '\n');
	}
	if (x > 0 && swiat->czyZajete(x - 1, y) == 1)
	{
		swiat->smiercOrganizmu_x_y(x - 1, y);
		swiat->dajInformacje(this->nazwa + " niszczy organizm obok dzieki CALOPALENIU " + '\n');
	}
	if (x < swiat->getSzerokosc() - 1 && swiat->czyZajete(x + 1, y) == 1)
	{
		swiat->smiercOrganizmu_x_y(x + 1, y);
		swiat->dajInformacje(this->nazwa + " niszczy organizm obok dzieki CALOPALENIU " + '\n');
	}
	moc_tura++;
	setMocTura(moc_tura);
	if (moc_tura == 5)
	{
		swiat->dajInformacje(this->nazwa + " czas jego umiejetnosci CALOPALENIA skonczyl sie " + '\n');
		moc_tura = 0;
		aktywacja_mocy = 0;
		setMocTura(moc_tura);
		setAktywacjaMocy(aktywacja_mocy);
	}
}

void Czlowiek::rozmnazanie()
{

}

void Czlowiek::akcja()
{
	this->poprzedni_x = x;
	this->poprzedni_y = y;
	int dzialanie = 5 - dezaktywacja_tura;
	int klawisz = 0;
	klawisz = _getch();
	klawisz = _getch();

	if (klawisz == KEY_UP)
	{
		if (y > 0)
		{
			this->y = y - 1;
			if (aktywacja_mocy == 1)
			{
				mocAktywna();
			}
		}
	}
	else if (klawisz == KEY_DOWN)
	{
		if (y < swiat->getWysokosc() - 1)
		{
			this->y = y + 1;
			if (aktywacja_mocy == 1)
			{
				mocAktywna();
			}
		}
	}
	else if (klawisz == KEY_LEFT)
	{
		if (x > 0)
		{
			this->x = x - 1;
			if (aktywacja_mocy == 1)
			{
				mocAktywna();
			}
		}
	}
	else if (klawisz == KEY_RIGHT)
	{
		if (x < swiat->getSzerokosc() - 1)
		{
			this->x = x + 1;
			if (aktywacja_mocy == 1)
			{
				mocAktywna();
			}
		}
	}
	else if (moc_tura == 0 && dezaktywacja_tura >= 5 && (klawisz == 'C' || klawisz == 'c'))
	{
		swiat->dajInformacje(this->nazwa + " uruchomil swoja umiejetnosc CALOPALENIE " + '\n');
		aktywacja_mocy = 1;
		dezaktywacja_tura = 0;
		setAktywacjaMocy(aktywacja_mocy);
		setDezaktywacjaTura(dezaktywacja_tura);
	}

	if (dzialanie > 0 && aktywacja_mocy == 0)
	{
		swiat->dajInformacje(this->nazwa + " jego umiejetnosc CALOPALENIE bedzie do aktywowania za " + (char)(dzialanie + 48) + " tur" + '\n');
	}
	else if (dzialanie == 0 && aktywacja_mocy == 0)
	{
		swiat->dajInformacje(this->nazwa + " jego umiejetnosc CALOPALENIE mozna aktywowac " + '\n');
	}

	if (aktywacja_mocy == 0)
	{
		dezaktywacja_tura++;
		setDezaktywacjaTura(dezaktywacja_tura);
	}
}

Czlowiek::~Czlowiek()
{

}
