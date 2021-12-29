#include "Organizm.h"

Organizm::Organizm()
{
	this->sila = NULL;
	this->inicjatywa = NULL;
	this->x = NULL;
	this->y = NULL;
	this->poprzedni_x = NULL;
	this->poprzedni_y = NULL;
	this->id = NULL;
	this->symbol = NULL;
	this->nazwa = "";
}

void Organizm::setX(int x)
{
	this->x = x;
}
void Organizm::setY(int y)
{
	this->y = y;
}

void Organizm::setSwiat(Swiat* swiat)
{
	this->swiat = swiat;
}

void Organizm::setOrganizmSila(int sila)
{
	this->sila = sila;
}

void Organizm::setOrganizmInicjatywa(int inicjatywa)
{
	this->inicjatywa = inicjatywa;
}

void Organizm::setOrganizmPoprzedniX(int poprzedni_x)
{
	this->poprzedni_x = poprzedni_x;
}

void Organizm::setOrganizmPoprzedniY(int poprzedni_y)
{
	this->poprzedni_y = poprzedni_y;
}

void Organizm::setOrganizmSymbol(char symbol)
{
	this->symbol = symbol;
}

void Organizm::setOrganizmNazwa(string nazwa)
{
	this->nazwa = nazwa;
}

int Organizm::getX()
{
	return x;
}

int Organizm::getY()
{
	return y;
}

int Organizm::getPoprzedniX()
{
	return poprzedni_x;
}
int Organizm::getPoprzedniY()
{
	return poprzedni_y;
}

int Organizm::getID()
{
	return id;
}

string Organizm::getNazwa()
{
	return nazwa;
}

int Organizm::getInicjatywa()
{
	return inicjatywa;
}

int Organizm::getOrganizmSila()
{
	return sila;
}

char Organizm::getSymbol()
{
	return symbol;
}

int Organizm::kolizja(Organizm* atakujacy)
{
	if (atakujacy->getOrganizmSila() > this->sila)
	{
		swiat->dajInformacje(this->nazwa + " zostal/a zniszczony/na przez " + atakujacy->getNazwa() + '\n');
		swiat->smiercOrganizmu(this->id);
		return -2;
	}
	else if (atakujacy->getOrganizmSila() < this->sila)
	{
		swiat->dajInformacje(atakujacy->getNazwa() + " zostal/a zniszczony/na przez " + this->nazwa + '\n');
		swiat->smiercOrganizmu(atakujacy->getID());
		return -1;
	}
	else if (atakujacy->getID() < this->id)
	{
		swiat->dajInformacje(this->nazwa + " zostal/a zniszczony/na przez " + atakujacy->getNazwa() + '\n');
		swiat->smiercOrganizmu(this->id);
		return -1;
	}
	else
	{
		swiat->dajInformacje(atakujacy->getNazwa() + " zostal/a zniszczony/na przez " + this->nazwa + '\n');
		swiat->smiercOrganizmu(atakujacy->getID());
		return -2;
	}
	return 0;
}

Organizm::~Organizm()
{

}
