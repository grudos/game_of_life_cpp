#include "Zwierze.h"

void Zwierze::akcja()
{
	this->poprzedni_x = x;
	this->poprzedni_y = y;
	int ruch;
	ruch = rand() % 4;
	if (ruch == 0 && y > 0)
	{
		this->y = y - 1;
	}
	else if (ruch == 1 && x > 0)
	{
		this->x = x - 1;
	}
	else if (ruch == 2 && x < swiat->getSzerokosc() - 1)
	{
		this->x = x + 1;
	}
	else if (ruch == 3 && y < swiat->getWysokosc() - 1)
	{
		this->y = y + 1;
	}
}

int Zwierze::kolizja(Organizm* atakujacy)
{
	if (atakujacy->getSymbol() == this->symbol)
	{
		atakujacy->setY(atakujacy->getPoprzedniY());
		atakujacy->setX(atakujacy->getPoprzedniX());
		return 1;
	}
	else
	{
		Organizm::kolizja(atakujacy);
		return 0;
	}
}

Zwierze::~Zwierze()
{

}