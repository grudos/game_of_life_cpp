#include "Zolw.h"
#define ODPARCIE 5

Zolw::Zolw(int x, int y, int id)
{
	this->sila = 2;
	this->inicjatywa = 1;
	this->x = x;
	this->y = y;
	this->id = id;
	this->symbol = 'Z';
	this->nazwa = "Zolw";
}

void Zolw::rozmnazanie()
{
	swiat->setID_swiata(id + 1);
	int opcja = 0;
	while (1)
	{
		opcja = rand() % 4;
		if ((swiat->czyZajete(x, y - 1) == 1) && (swiat->czyZajete(x, y + 1) == 1) && (swiat->czyZajete(x - 1, y) == 1) && (swiat->czyZajete(x + 1, y) == 1))
		{
			break;
		}
		else if (y == 0 && x > 0 && x < swiat->getSzerokosc() - 1 && (swiat->czyZajete(x, y + 1) == 1) && (swiat->czyZajete(x - 1, y) == 1) && (swiat->czyZajete(x + 1, y) == 1))
		{
			break;
		}
		else if (y == swiat->getWysokosc() - 1 && x > 0 && x < swiat->getSzerokosc() - 1 && (swiat->czyZajete(x, y - 1) == 1) && (swiat->czyZajete(x - 1, y) == 1) && (swiat->czyZajete(x + 1, y) == 1))
		{
			break;
		}
		else if (x == 0 && y > 0 && y < swiat->getWysokosc() - 1 && (swiat->czyZajete(x, y - 1) == 1) && (swiat->czyZajete(x, y + 1) == 1) && (swiat->czyZajete(x + 1, y) == 1))
		{
			break;
		}
		else if (x == swiat->getSzerokosc() - 1 && y > 0 && y < swiat->getWysokosc() - 1 && (swiat->czyZajete(x, y - 1) == 1) && (swiat->czyZajete(x, y + 1) == 1) && (swiat->czyZajete(x - 1, y) == 1))
		{
			break;
		}
		else if (y == 0 && x == 0 && (swiat->czyZajete(x, y + 1) == 1) && (swiat->czyZajete(x + 1, y) == 1))
		{
			break;
		}
		else if (y == swiat->getWysokosc() - 1 && x == 0 && (swiat->czyZajete(x, y - 1) == 1) && (swiat->czyZajete(x + 1, y) == 1))
		{
			break;
		}
		else if (y == 0 && x == swiat->getSzerokosc() - 1 && (swiat->czyZajete(x, y + 1) == 1) && (swiat->czyZajete(x - 1, y) == 1))
		{
			break;
		}
		else if (y == swiat->getWysokosc() - 1 && x == swiat->getSzerokosc() - 1 && (swiat->czyZajete(x, y - 1) == 1) && (swiat->czyZajete(x - 1, y) == 1))
		{
			break;
		}
		else if (opcja == 0 && y > 0 && swiat->czyZajete(x, y - 1) == 0)
		{
			swiat->stworzOrganizm(new Zolw(x, y - 1, swiat->getID_swiata()));
			swiat->dajInformacje(this->nazwa + " rozmnozyl/a sie " + '\n');
			break;
		}
		else if (opcja == 1 && y < swiat->getWysokosc() - 1 && swiat->czyZajete(x, y + 1) == 0)
		{
			swiat->stworzOrganizm(new Zolw(x, y + 1, swiat->getID_swiata()));
			swiat->dajInformacje(this->nazwa + " rozmnozyl/a sie " + '\n');
			break;
		}
		else if (opcja == 2 && x > 0 && swiat->czyZajete(x - 1, y) == 0)
		{
			swiat->stworzOrganizm(new Zolw(x - 1, y, swiat->getID_swiata()));
			swiat->dajInformacje(this->nazwa + " rozmnozyl/a sie " + '\n');
			break;
		}
		else if (opcja == 3 && x < swiat->getSzerokosc() - 1 && swiat->czyZajete(x + 1, y) == 0)
		{
			swiat->stworzOrganizm(new Zolw(x + 1, y, swiat->getID_swiata()));
			swiat->dajInformacje(this->nazwa + " rozmnozyl/a sie " + '\n');
			break;
		}
	}
}

void Zolw::akcja()
{
	int ruch2 = rand() % 4;
	if (ruch2 == 0)
	{
		Zwierze::akcja();
	}
}

int Zolw::kolizja(Organizm* atakujacy)
{
	if (atakujacy->getNazwa() == this->nazwa)
	{
		atakujacy->setY(atakujacy->getPoprzedniY());
		atakujacy->setX(atakujacy->getPoprzedniX());
		return 1;
	}
	else if (atakujacy->getOrganizmSila() < ODPARCIE)
	{
		swiat->dajInformacje(this->nazwa + " odbil atak od " + atakujacy->getNazwa()+'\n');
		atakujacy->setY(atakujacy->getPoprzedniY());
		atakujacy->setX(atakujacy->getPoprzedniX());
		return 0;
	}
	else
	{
		swiat->smiercOrganizmu(this->id);
		swiat->dajInformacje(this->nazwa + " zostal/a zniszczony/na przez " + atakujacy->getNazwa() + '\n');
		return 0;
	}
}

Zolw::~Zolw()
{

}