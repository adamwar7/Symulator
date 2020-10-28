#include "Gracz.h"


Gracz::Gracz(Mapa mapa, int pkt) : rozstawienia(mapa), punktacja(pkt) {};

int Gracz::zwrocPunkty()
{
	return punktacja;
}

void Gracz::edytujPunkty(int pkt)
{
	punktacja += pkt;
}

void Gracz::ZapiszDoPlikuGracza1(fstream& plik)
{
	plik.open("Gracz1.txt", ios::out);
	if (plik.good())
		plik << "Gracz1\n---------------\nPunkty: " << punktacja;
	else
	{
		cout << "Nie udalo sie otworzyc pliku";
	}
}

void Gracz::ZapiszDoPlikuGracza2(fstream& plik)
{
	plik.open("Gracz2.txt", ios::out);
	if (plik.good())
		plik << "Gracz2\n---------------\nPunkty: " << punktacja;
	else
	{
		cout << "Nie udalo sie otworzyc pliku";
	}
}



Gracz::~Gracz()
{

}

