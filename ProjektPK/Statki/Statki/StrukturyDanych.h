#pragma once
#include <iostream>

using namespace std;

struct wygladMap
{
	string symbol;		//symbol wyswietlania pola mapy
	int rozmiar;		//rozmiar mapy (4,6,10)
	bool statek;		//informacja o tym ze w tym miejscu znajduje sie statek
	string nazwaStatku;
	int y;
	char x;
	wygladMap* next;	//nastepny symbol na mapie
};
