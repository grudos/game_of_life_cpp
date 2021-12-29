#include "Mlecz.h"
#define LICZBA_PROB 3

Mlecz::Mlecz(int x, int y, int id)
{
	this->sila = 0;
	this->x = x;
	this->y = y;
	this->id = id;
	this->symbol = 'm';
	this->nazwa = "Mlecz";
}

void Mlecz::akcja()
{
	for (int i = 0; i < LICZBA_PROB; i++)
	{
		int zasadzenie;
		zasadzenie = rand() % 30;
		if (zasadzenie == 0)
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
					swiat->stworzOrganizm(new Mlecz(x, y - 1, swiat->getID_swiata()));
					swiat->dajInformacje(this->nazwa + " rozmnozyl/a sie " + '\n');
					break;
				}
				else if (opcja == 1 && y < swiat->getWysokosc() - 1 && swiat->czyZajete(x, y + 1) == 0)
				{
					swiat->stworzOrganizm(new Mlecz(x, y + 1, swiat->getID_swiata()));
					swiat->dajInformacje(this->nazwa + " rozmnozyl/a sie " + '\n');
					break;
				}
				else if (opcja == 2 && x > 0 && swiat->czyZajete(x - 1, y) == 0)
				{
					swiat->stworzOrganizm(new Mlecz(x - 1, y, swiat->getID_swiata()));
					swiat->dajInformacje(this->nazwa + " rozmnozyl/a sie " + '\n');
					break;
				}
				else if (opcja == 3 && x < swiat->getSzerokosc() - 1 && swiat->czyZajete(x + 1, y) == 0)
				{
					swiat->stworzOrganizm(new Mlecz(x + 1, y, swiat->getID_swiata()));
					swiat->dajInformacje(this->nazwa + " rozmnozyl/a sie " + '\n');
					break;
				}
			}
		}
	}
}

void Mlecz::rozmnazanie()
{

}

Mlecz::~Mlecz()
{

}