#include "Funkcje.h"

char podajRozmiar()
{
	char rozmiar = '0';
	while (rozmiar != '1' && rozmiar != '2' && rozmiar != '3')
	{
		cout << "Podaj wielkosc mapy: '1' - mala mapa, '2' srednia mapa, '3' - duza mapa\n";
		cout << "Wprowadz: ";
		cin >> rozmiar;
		system("cls");
	}
	return rozmiar;
}


int zwrocPrawdziwyRozmiar(char fakerozmiar)
{
	if (fakerozmiar == '1')
	{
		return 4;
	}
	else if (fakerozmiar == '2')
	{
		return 6;
	}
	else
		return 10;
}