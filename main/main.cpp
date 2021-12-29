#include "Swiat.h"

int main()
{
	char tak;
	int zapis = 0;
	int wysokosc, szerokosc;
	srand(time(NULL));
	cout << "Uruchomienie nastepnej symulacji umozliwia dowolny przycisk z klawiatury." << endl;
	cout<<"Sterowanie czlowiekiem za pomoca strzalek." << endl;
	cout << "Uruchomienie specjalnej umiejetnosci czlowieka, czyli CALOPALENIA za pomoca klawisza [c/C]." << endl;
	cout << "Zapis stanu symulacji za pomoca klawisza [s/S]." << endl;
	cout<<"Wyjscie z symulacji za pomoca [q/Q]." << endl;
	cout << "Czy chcesz wczytac symulacje do pliku?" << endl;
	cout << "[T / t] - TAK" << endl;
	cout<<"Dowolny inny znak z klawiatury - NIE." << endl;
	cin >> tak;
	if (tak == 't' || tak == 'T')
	{
		zapis = 1;
	}
	if (zapis == 0)
	{
		cout << "Podaj szerokosc planszy: " << endl;
		cin >> szerokosc;
		cout << "Podaj wysokosc planszy: " << endl;
		cin >> wysokosc;
		Swiat* s = new Swiat(szerokosc, wysokosc);
		s->setZapis(zapis);
		s->wykonajTure();
	}
	else if (zapis == 1)
	{
		cout << "Wczytywanie z pliku: " << endl;
		FILE* plik = fopen("symulacja.txt", "r");
		if (plik == NULL)
		{
			perror("Plik symulacja.txt nie otworzyl sie");
			return -1;
		}
		int szerokosc_zapis, wysokosc_zapis;
		fscanf(plik, "%d %d", &szerokosc_zapis, &wysokosc_zapis);
		fclose(plik);
		Swiat* s = new Swiat(szerokosc_zapis, wysokosc_zapis);
		s->setZapis(zapis);
		s->wykonajTure();
	}
}

