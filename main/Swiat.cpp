#include "Swiat.h"
#include "Wilk.h"
#include "Owca.h"
#include "Lis.h"
#include "Zolw.h"
#include "Antylopa.h"
#include "Trawa.h"
#include "Wilk.h"
#include "Mlecz.h"
#include "Guarana.h"
#include "WilczeJagody.h"
#include "BarszczSosnowskiego.h"
#include "Czlowiek.h"


Swiat::Swiat(int szerokosc, int wysokosc) :szerokosc(szerokosc), wysokosc(wysokosc)
{
	plansza.resize(wysokosc);
	for (int i = 0; i < wysokosc; i++)
	{
		plansza[i].resize(szerokosc);
	}
}

void Swiat::setZapis(int zapis)
{
	this->zapis = zapis;
}

int Swiat::getSzerokosc()
{
	return this->szerokosc;
}

int Swiat::getWysokosc()
{
	return this->wysokosc;
}

int Swiat::getZapis()
{
	return this->zapis;
}

int Swiat::getID_swiata()
{
	return this->ID_swiata;
}

void Swiat::setID_swiata(int ID_swiata)
{
	this->ID_swiata = ID_swiata;
}

void Swiat::dajInformacje(string tekst)
{
	linie_informacje++;
	if (linie_informacje <= 10)
	{
		informacje[linie_informacje-1] = tekst;
	}
	else
	{
		for (int i = 1; i < 10; i++)
		{
			informacje[i-1] = informacje[i];
		}
		linie_informacje=10;
		informacje[linie_informacje - 1] = tekst;
	}
}

void Swiat::wypiszInformacje(string informacje)
{
	cout << informacje;
}

int Swiat::getSila(int x, int y)
{
	for (int i = 0; i < organizmy.size(); ++i)
	{
		if (x == organizmy[i]->getX() && y == organizmy[i]->getY())
		{
			return organizmy[i]->getOrganizmSila();
		}
	}
	return -1;
}

void Swiat::smiercOrganizmu(int id)
{
	for (int i = 0; i < organizmy.size(); ++i)
	{
		if (organizmy[i]->getID() == id)
		{
			organizmy.erase(organizmy.begin() + i);
			break;
		}
	}
}

void Swiat::smiercOrganizmu_x_y(int x, int y)
{
	for (int i = 0; i < organizmy.size(); ++i)
	{
		if (organizmy[i]->getX() == x && organizmy[i]->getY() == y)
		{
			organizmy.erase(organizmy.begin() + i);
			break;
		}
	}
}

void Swiat::smiercOrganizmuBarszcz(int x, int y)
{
	for (int i = 0; i < organizmy.size(); ++i)
	{
		if (organizmy[i]->getX() == x && organizmy[i]->getY() == y && organizmy[i]->getSymbol() != 'b' && organizmy[i]->getSymbol() != 'g' && organizmy[i]->getSymbol() != 'm' && organizmy[i]->getSymbol() != 't' && organizmy[i]->getSymbol() != 'j')
		{
			dajInformacje("Barszcz Sosnowskiego niszczy organizm obok \n");
			organizmy.erase(organizmy.begin() + i);
			break;
		}
	}
}

void Swiat::stworzOrganizm(Organizm* nowy)
{
	this->ID_swiata = nowy->getID();
	this->ID_swiata++;
	organizmy.push_back(nowy);
	organizmy.back()->setSwiat(this);
}


void Swiat::stworzOrganizmPlik(char symbol, int sila, int inicjatywa, int x, int y, int poprzedni_x, int poprzedni_y, int id)
{
	if (symbol == 'A')
	{
		organizmy.push_back(new Antylopa(x, y, id));
		organizmy.back()->setSwiat(this);
		organizmy.back()->setOrganizmNazwa("Antylopa");
	}
	else if (symbol == 'b')
	{
		organizmy.push_back(new BarszczSosnowskiego(x, y, id));
		organizmy.back()->setSwiat(this);
		organizmy.back()->setOrganizmNazwa("BarszczSosnowskiego");
	}
	else if (symbol == 'g')
	{
		organizmy.push_back(new Guarana(x, y, id));
		organizmy.back()->setSwiat(this);
		organizmy.back()->setOrganizmNazwa("Guarana");
	}
	else if (symbol == 'L')
	{
		organizmy.push_back(new Lis(x, y, id));
		organizmy.back()->setSwiat(this);
		organizmy.back()->setOrganizmNazwa("Lis");
	}
	else if (symbol == 'm')
	{
		organizmy.push_back(new Mlecz(x, y, id));
		organizmy.back()->setSwiat(this);
		organizmy.back()->setOrganizmNazwa("Mlecz");
	}
	else if (symbol == 'O')
	{
		organizmy.push_back(new Owca(x, y, id));
		organizmy.back()->setSwiat(this);
		organizmy.back()->setOrganizmNazwa("Owca");
	}
	else if (symbol == 't')
	{
		organizmy.push_back(new Trawa(x, y, id));
		organizmy.back()->setSwiat(this);
		organizmy.back()->setOrganizmNazwa("Trawa");
	}
	else if (symbol == 'j')
	{
		organizmy.push_back(new WilczeJagody(x, y, id));
		organizmy.back()->setSwiat(this);
		organizmy.back()->setOrganizmNazwa("WilczeJagody");
	}
	else if (symbol == 'W')
	{
		organizmy.push_back(new Wilk(x, y, id));
		organizmy.back()->setSwiat(this);
		organizmy.back()->setOrganizmNazwa("Wilk");
	}
	else if (symbol == 'Z')
	{
		organizmy.push_back(new Zolw(x, y, id));
		organizmy.back()->setSwiat(this);
		organizmy.back()->setOrganizmNazwa("Zolw");
	}

	organizmy.back()->setOrganizmSila(sila);
	organizmy.back()->setOrganizmInicjatywa(inicjatywa);
	organizmy.back()->setOrganizmPoprzedniX(poprzedni_x);
	organizmy.back()->setOrganizmPoprzedniY(poprzedni_y);
	organizmy.back()->setOrganizmSymbol(symbol);
}

void Swiat::stworzCzlowiekPlik(char symbol, int sila, int inicjatywa, int x, int y, int poprzedni_x, int poprzedni_y, int id, int moc_tura, int aktywacja_mocy, int dezaktywacja_tura)
{
	Czlowiek* c=new Czlowiek(x, y, id);
	c->setSwiat(this);
	c->setOrganizmNazwa("Czlowiek");
	c->setOrganizmSila(sila);
	c->setOrganizmInicjatywa(inicjatywa);
	c->setOrganizmPoprzedniX(poprzedni_x);
	c->setOrganizmPoprzedniY(poprzedni_y);
	c->setOrganizmSymbol(symbol);
	c->setMocTura(moc_tura);
	c->setAktywacjaMocy(aktywacja_mocy);
	c->setDezaktywacjaTura(dezaktywacja_tura);
	organizmy.push_back(c);
}

int Swiat::czyZajete(int x, int y)
{
	for (int i = 0; i < organizmy.size(); ++i)
	{
		if (x == organizmy[i]->getX() && y == organizmy[i]->getY())
		{
			return 1;
		}
	}
	return 0;
}

void Swiat::stworzOrganizmy()
{
	int organizm = 6;
	int liczba_organizmow=rand() % (szerokosc/2)+(szerokosc+wysokosc);
	int x = 0;
	int y = 0;

	x = rand() % szerokosc;
	y = rand() % wysokosc;

	organizmy.push_back(new Czlowiek(x, y, ID_swiata));
	organizmy.back()->setSwiat(this);
	ID_swiata++;

	for (int i = 0; i < 20; i++)
	{
		x = rand() % szerokosc;
		y = rand() % wysokosc;

		organizmy.push_back(new Antylopa(x, y, ID_swiata));
		organizmy.back()->setSwiat(this);
		ID_swiata++;
	}

	x = 0;
	y = 0;

	for (int i = 0; i < liczba_organizmow; i++)
	{
		organizm = rand() % 10 + 1;
		while (1)
		{
			x = rand() % szerokosc;
			y = rand() % wysokosc;
			if (!czyZajete(x, y)) break;
		}

		if (organizm == 1)
		{
			organizmy.push_back(new Wilk(x, y, ID_swiata));
			organizmy.back()->setSwiat(this);
			ID_swiata++;
		}
		else if (organizm == 2)
		{
			organizmy.push_back(new Owca(x, y, ID_swiata));
			organizmy.back()->setSwiat(this);
			ID_swiata++;
		}
		else if (organizm == 3)
		{
			organizmy.push_back(new Lis(x, y, ID_swiata));
			organizmy.back()->setSwiat(this);
			ID_swiata++;
		}
		else if (organizm == 4)
		{
			organizmy.push_back(new Zolw(x, y, ID_swiata));
			organizmy.back()->setSwiat(this);
			ID_swiata++;
		}
		else if (organizm == 5)
		{
			organizmy.push_back(new Antylopa(x, y, ID_swiata));
			organizmy.back()->setSwiat(this);
			ID_swiata++;
		}
		else if (organizm == 6)
		{
			organizmy.push_back(new Trawa(x, y, ID_swiata));
			organizmy.back()->setSwiat(this);
			ID_swiata++;
		}
		else if (organizm == 7)
		{
			organizmy.push_back(new Mlecz(x, y, ID_swiata));
			organizmy.back()->setSwiat(this);
			ID_swiata++;
		}
		else if (organizm == 8)
		{
			organizmy.push_back(new Guarana(x, y, ID_swiata));
			organizmy.back()->setSwiat(this);
			ID_swiata++;
		}
		else if (organizm == 9)
		{
			organizmy.push_back(new WilczeJagody(x, y, ID_swiata));
			organizmy.back()->setSwiat(this);
			ID_swiata++;
		}
		else if (organizm == 10)
		{
			organizmy.push_back(new BarszczSosnowskiego(x, y, ID_swiata));
			organizmy.back()->setSwiat(this);
			ID_swiata++;
		}
	}
}

void Swiat::stworzSwiat()
{
	for (int i = 0; i < wysokosc; i++)
	{
		for (int j = 0; j < szerokosc; j++)
		{
			plansza[i][j] = '-';
		}
	}
}

void Swiat::rysujSwiat()
{
	for (int i = 0; i < organizmy.size(); ++i)
	{
		plansza[organizmy[i]->getY()][organizmy[i]->getX()] = organizmy[i]->getSymbol();
	}

	for (int i = 0; i < wysokosc; i++)
	{
		for (int j = 0; j < szerokosc; j++)
		{
			cout << plansza[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

int dlaInicjatywy(Organizm* organizm_1, Organizm* organizm_2)
{
	if (organizm_1->getInicjatywa() > organizm_2->getInicjatywa())
	{
		return 1;
	}
	else if (organizm_1->getInicjatywa() < organizm_2->getInicjatywa())
	{
		return 0;
	}
	else
	{
		return (organizm_1->getID() < organizm_2->getID());
	}
}

void Swiat::wykonajTure()
{
	int ostatni_ruch[2];
	ostatni_ruch[0] = 99;
	ostatni_ruch[1] = 0;
	if (getZapis() == 0)
	{
		stworzSwiat();
		stworzOrganizmy();
	}
	else if (getZapis() == 1)
	{
		FILE* plik = fopen("symulacja.txt", "r");
		if (plik == NULL)
		{
			perror("Plik symulacja.txt nie otworzyl sie");
			return;
		}

		int liczba_organizmow=0;
		int sila=0, inicjatywa = 0, x = 0, y = 0, poprzedni_x = 0, poprzedni_y = 0, id = 0;
		int moc_tura = 0, aktywacja_mocy = 0, dezaktywacja_tura = 0;
		char symbol=' ';
		string nazwa;
		fscanf(plik, "%d %d %d\n", &szerokosc, &wysokosc, &liczba_organizmow);
		stworzSwiat();
		for (int k = 0; k < liczba_organizmow; ++k)
		{
			fscanf(plik, "%c ", &symbol);
			if (symbol == 'C')
			{
				fscanf(plik, "%d %d %d %d %d %d %d %d %d %d\n", &sila, &inicjatywa, &x, &y, &poprzedni_x, &poprzedni_y, &id, &moc_tura, &aktywacja_mocy, &dezaktywacja_tura);
				stworzCzlowiekPlik(symbol, sila, inicjatywa, x, y, poprzedni_x, poprzedni_y, id, moc_tura, aktywacja_mocy, dezaktywacja_tura);
			}
			else
			{
				fscanf(plik, "%d %d %d %d %d %d %d \n", &sila, &inicjatywa, &x, &y, &poprzedni_x, &poprzedni_y, &id);
				stworzOrganizmPlik(symbol, sila, inicjatywa, x, y, poprzedni_x, poprzedni_y, id);
			}
		}
		
		fclose(plik);
		setZapis(0);
	}
	rysujSwiat();
	system("cls");
	cout << "Jakub Grudowski 180319" << endl;
	cout << endl;
	int j = 0;
	while (1)
	{
		sort(organizmy.begin(), organizmy.end(), dlaInicjatywy);
		j = 0;
		for (j; j <= organizmy.size(); ++j)
		{
			if (j == organizmy.size())
			{
				break;
			}

			if (organizmy[j]->getInicjatywa() < ostatni_ruch[0])
			{
				ostatni_ruch[0] = organizmy[j]->getInicjatywa();
				ostatni_ruch[1] = organizmy[j]->getID();
				break;
			}
			else if (organizmy[j]->getInicjatywa() == ostatni_ruch[0] && organizmy[j]->getID() > ostatni_ruch[1])
			{
				ostatni_ruch[0] = organizmy[j]->getInicjatywa();
				ostatni_ruch[1] = organizmy[j]->getID();
				break;
			}
		}
		if (j >= organizmy.size() - 1)
		{
			ostatni_ruch[0] = 99;
			ostatni_ruch[1] = 0;
			int klawisz = 0;
			klawisz = getchar();
			if (klawisz == 's' || klawisz == 'S')
			{
				FILE* plik = fopen("symulacja.txt", "w");
				if (plik == NULL)
				{
					perror("Plik symulacja.txt nie otworzyl sie");
					return;
				}
				fprintf(plik, "%d %d %d\n", getSzerokosc(), getWysokosc(), organizmy.size());
				for (int k = 0; k < organizmy.size(); ++k)
				{
					Czlowiek* c;
					if (c=dynamic_cast<Czlowiek*>(organizmy[k]))
					{
						fprintf(plik, "%c %d %d %d %d %d %d %d %d %d %d\n", organizmy[k]->getSymbol(), organizmy[k]->getOrganizmSila(), organizmy[k]->getInicjatywa(), organizmy[k]->getX(), organizmy[k]->getY(), organizmy[k]->getPoprzedniX(),
							organizmy[k]->getPoprzedniY(), organizmy[k]->getID(),c->getMocTura(), c->getAktywacjaMocy(), c->getDezaktywacjaTura());
					}
					else
					{
						fprintf(plik, "%c %d %d %d %d %d %d %d \n", organizmy[k]->getSymbol(), organizmy[k]->getOrganizmSila(), organizmy[k]->getInicjatywa(), organizmy[k]->getX(), organizmy[k]->getY(), organizmy[k]->getPoprzedniX(),
							organizmy[k]->getPoprzedniY(), organizmy[k]->getID());
					}
				}
				fclose(plik);
			}
			else if (klawisz == 'q' || klawisz == 'Q')
			{
				break;
			}
			continue;
		}
		stworzSwiat();
		organizmy[j]->akcja();
		for (int k = 0; k < organizmy.size(); ++k)
		{
			if (k != j && organizmy[j]->getX() == organizmy[k]->getX() && organizmy[j]->getY() == organizmy[k]->getY())
			{
				int wynik = organizmy[k]->kolizja(organizmy[j]);
				if (wynik == 1)
				{
					organizmy[k]->rozmnazanie();
				}
			}
		}
		system("cls");
		for (int l = 0; l < linie_informacje; l++)
		{
			wypiszInformacje(informacje[l]);
		}
		cout << endl;
		rysujSwiat();

		cout << "Jakub Grudowski 180319" << endl;
		cout << endl;
	}
}

Swiat::~Swiat()
{

}
