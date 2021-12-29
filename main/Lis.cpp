#include "Lis.h"

Lis::Lis(int x, int y, int id)
{
	this->sila = 3;
	this->inicjatywa = 7;
	this->x = x;
	this->y = y;
	this->id = id;
	this->symbol = 'L';
	this->nazwa = "Lis";
}

void Lis::rozmnazanie()
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
			swiat->stworzOrganizm(new Lis(x, y - 1, swiat->getID_swiata()));
			swiat->dajInformacje(this->nazwa + " rozmnozyl/a sie " + '\n');
			break;
		}
		else if (opcja == 1 && y < swiat->getWysokosc() - 1 && swiat->czyZajete(x, y + 1) == 0)
		{
			swiat->stworzOrganizm(new Lis(x, y + 1, swiat->getID_swiata()));
			swiat->dajInformacje(this->nazwa + " rozmnozyl/a sie " + '\n');
			break;
		}
		else if (opcja == 2 && x > 0 && swiat->czyZajete(x - 1, y) == 0)
		{
			swiat->stworzOrganizm(new Lis(x - 1, y, swiat->getID_swiata()));
			swiat->dajInformacje(this->nazwa + " rozmnozyl/a sie " + '\n');
			break;
		}
		else if (opcja == 3 && x < swiat->getSzerokosc() - 1 && swiat->czyZajete(x + 1, y) == 0)
		{
			swiat->stworzOrganizm(new Lis(x + 1, y, swiat->getID_swiata()));
			swiat->dajInformacje(this->nazwa + " rozmnozyl/a sie " + '\n');
			break;
		}
	}
}

void Lis::akcja()
{
	if ((swiat->czyZajete(x, y - 1) == 1) && (swiat->czyZajete(x, y + 1) == 1) && (swiat->czyZajete(x - 1, y) == 1) && (swiat->czyZajete(x + 1, y) == 1))  
	{
		return;
	}
	int opcja = 0;
	while (1)
	{
		this->poprzedni_x = x;
		this->poprzedni_y = y;
		opcja = rand() % 4;
		if (opcja == 0 && y > 0 && (swiat->czyZajete(x, y - 1) == 0 || (swiat->czyZajete(x, y - 1) == 1 && sila >= swiat->getSila(x, y - 1))))
		{
			this->y = y - 1;
			break;
		}
		else if (opcja == 1 && y < swiat->getWysokosc() - 1 && (swiat->czyZajete(x, y + 1) == 0 || (swiat->czyZajete(x, y + 1) == 1 && sila >= swiat->getSila(x, y + 1))))
		{
			this->y = y + 1;
			break;
		}
		else if (opcja == 2 && x > 0 && (swiat->czyZajete(x - 1, y) == 0 || (swiat->czyZajete(x - 1, y) == 1 && sila >= swiat->getSila(x - 1, y))))
		{
			this->x = x - 1;
			break;
		}
		else if (opcja == 3 && x < swiat->getSzerokosc() - 1 && (swiat->czyZajete(x + 1, y) == 0 || (swiat->czyZajete(x + 1, y) == 1 && sila >= swiat->getSila(x + 1, y))))
		{
			this->x = x + 1;
			break;
		}
	}
}

Lis::~Lis()
{

}