#include <iostream>
#include "Gracz.h"
#include "Mapa.h"
#include "RodzajeStatkow.h"
#include "StrukturyDanych.h"
#include <string>
#include "Funkcje.h"
using namespace std;

int main()
{
	fstream g1;
	fstream g2;
	char rozmiar = podajRozmiar();
	Lodka l1 = l1.zworcLodke(rozmiar);
	Statek s1 = s1.zworcStatek(rozmiar, l1);
	Prom p1 = p1.zworcProm(rozmiar, l1, s1);
	Transportowiec t1 = t1.zworcTransportowiec(rozmiar, l1, s1, p1);
	wygladMap* statkiGracza1 = nullptr;
	wygladMap* trafienaiGracza1 = nullptr;
	Lodka l2 = l2.zworcLodke(rozmiar);
	Statek s2 = s2.zworcStatek(rozmiar, l2);
	Prom p2 = p2.zworcProm(rozmiar, l2, s2);
	Transportowiec t2 = t2.zworcTransportowiec(rozmiar, l2, s2, p2);
	wygladMap* statkiGracza2 = nullptr;
	wygladMap* trafienaiGracza2 = nullptr;
	zwrocPrawdziwyRozmiar(rozmiar);
	Mapa m1("[#]", zwrocPrawdziwyRozmiar(rozmiar), statkiGracza1, trafienaiGracza1, l1, s1, p1, t1);
	Mapa m2("[#]", zwrocPrawdziwyRozmiar(rozmiar), statkiGracza2, trafienaiGracza2, l2, s2, p2, t1);
	Gracz gracz1(m1, 0);
	Gracz gracz2(m2, 0);
	m1.zapiszMape(statkiGracza1);
	m1.zapiszMapeStrzalow(trafienaiGracza1);
	m2.zapiszMape(statkiGracza2);
	m2.zapiszMapeStrzalow(trafienaiGracza2);
	while (true)
	{
		cout << "Gracz 1:\n\n" << "Punkty: " << gracz1.zwrocPunkty() << endl << endl;
		m1.wypiszMape(statkiGracza1);
		cout << endl << endl;
		m1.wypiszMape(trafienaiGracza1);
		gracz1.edytujPunkty(m1.strzal(statkiGracza2, trafienaiGracza1));
		m1.przejdzDalej();
		cout << "Gracz 1:\n\n" << "Punkty: " << gracz1.zwrocPunkty() << endl << endl;
		m1.wypiszMape(statkiGracza1);
		cout << endl << endl;
		m1.wypiszMape(trafienaiGracza1);
		m1.przejdzDalej();
		cout << "Gracz 2:\n\n" << "Punkty: " << gracz1.zwrocPunkty() << endl << endl;
		m1.wypiszMape(statkiGracza2);
		cout << endl << endl;
		m2.wypiszMape(trafienaiGracza2);
		gracz2.edytujPunkty((m2.strzal(statkiGracza1, trafienaiGracza2)));
		m1.przejdzDalej();
		cout << "Gracz 2:\n\n" << "Punkty: " << gracz1.zwrocPunkty() << endl << endl;
		m2.wypiszMape(statkiGracza1);
		cout << endl << endl;
		m2.wypiszMape(trafienaiGracza1);
		m2.przejdzDalej();
		if (m1.zwrocrozmiar() == 4)
		{
			if (gracz1.zwrocPunkty() == 20)
			{
				system("cls");
				cout << "Gracz1 wygrywa!" << endl;
				gracz1.ZapiszDoPlikuGracza1(g1);
				m1.wypiszDoPliku(g1, statkiGracza1, trafienaiGracza1);
				gracz2.ZapiszDoPlikuGracza2(g2);
				m2.wypiszDoPliku(g2, statkiGracza2, trafienaiGracza2);
				break;
			}
			else if (gracz2.zwrocPunkty() == 20)
			{
				system("cls");
				cout << "Gracz2 wygrywa!" << endl;
				gracz1.ZapiszDoPlikuGracza1(g1);
				m1.wypiszDoPliku(g1, statkiGracza1, trafienaiGracza1);
				gracz2.ZapiszDoPlikuGracza2(g2);
				m2.wypiszDoPliku(g2, statkiGracza2, trafienaiGracza2);
				break;
			}
		}
		else if (m1.zwrocrozmiar() == 6)
		{
			if (gracz1.zwrocPunkty() == 29)
			{
				system("cls");
				cout << "Gracz1 wygrywa!" << endl;
				gracz1.ZapiszDoPlikuGracza1(g1);
				m1.wypiszDoPliku(g1, statkiGracza1, trafienaiGracza1);
				gracz2.ZapiszDoPlikuGracza2(g2);
				m2.wypiszDoPliku(g2, statkiGracza2, trafienaiGracza2);
				break;
			}
			else if (gracz2.zwrocPunkty() == 29)
			{
				system("cls");
				cout << "Gracz2 wygrywa!" << endl;
				gracz1.ZapiszDoPlikuGracza1(g1);
				m1.wypiszDoPliku(g1, statkiGracza1, trafienaiGracza1);
				gracz2.ZapiszDoPlikuGracza2(g2);
				m2.wypiszDoPliku(g2, statkiGracza2, trafienaiGracza2);
				break;
			}
		}
		else if (m1.zwrocrozmiar() == 10)
		{
			if (gracz1.zwrocPunkty() == 34)
			{
				system("cls");
				cout << "Gracz1 wygrywa!" << endl;
				gracz1.ZapiszDoPlikuGracza1(g1);
				m1.wypiszDoPliku(g1, statkiGracza1, trafienaiGracza1);
				gracz2.ZapiszDoPlikuGracza2(g2);
				m2.wypiszDoPliku(g2, statkiGracza2, trafienaiGracza2);
				break;
			}
			else if (gracz2.zwrocPunkty() == 34)
			{
				system("cls");
				cout << "Gracz2 wygrywa!" << endl;
				gracz1.ZapiszDoPlikuGracza1(g1);
				m1.wypiszDoPliku(g1, statkiGracza1, trafienaiGracza1);
				gracz2.ZapiszDoPlikuGracza2(g2);
				m2.wypiszDoPliku(g2, statkiGracza2, trafienaiGracza2);
				break;
			}
		}
	}
		m1.zwalnianiePamieci(statkiGracza1);
		m1.zwalnianiePamieci(trafienaiGracza1);
		m2.zwalnianiePamieci(statkiGracza2);
		m2.zwalnianiePamieci(trafienaiGracza2);


	//testowanie1 - powodzenie
   // string symbol = "[#]";
   // string symbolLodki = "[L]";
   // Lodka l1("[L]", 10, 4, 'A');
   // Statek s1("[S]", 10, 1, 'A', 2, 'A', l1);
   // Prom p1("[P]", 10, 3, 'D', 4, 'D', 5, 'D',l1, s1);
   // Transportowiec t1("[T]", 10, 10, 'D', 10, 'E', 10, 'F', 10, 'G', l1, s1, p1);
   // wygladMap* b = nullptr;
   // wygladMap* c = nullptr;
   // Mapa m1(symbol, 10,b,c,l1,s1,p1,t1);
   // Gracz g1(m1,0);
   //// int i = g1.zwrocPunkty();
   ////cout << i;
   //m1.zapiszMape(b);
   //m1.wypiszMape(b);
   //m1.zapiszMapeStrzalow(c);
   //m1.wypiszMape(c);
   //g1.edytujPunkty(m1.strzal(b));
   //int i = g1.zwrocPunkty();
   //cout << i << endl;
   //m1.wypiszMape(b);
	system("pause");
	return 0;

}
