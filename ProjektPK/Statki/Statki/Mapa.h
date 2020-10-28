#pragma once
#include <iostream>
#include "StrukturyDanych.h"
#include "RodzajeStatkow.h"
#include <fstream>
using namespace std;

class Mapa
{
protected:
	string symbol;  //symbol wyswietlania pola mapy  
	int rozmiar;	//rozmiar mapy (4,6,10)
	wygladMap* mapaStatkow; //mapa statkow gracza
	wygladMap* mapaTrafien; //mapa trafien gracza
	Lodka lodka;
	Statek statek;
	Prom prom;
	Transportowiec trans;

public:
	//Mapa();
	Mapa(string s, int r, wygladMap*& mS, wygladMap*& mT, Lodka l, Statek sta, Prom p, Transportowiec t) :symbol(s), rozmiar(r), mapaStatkow(mS), mapaTrafien(mT), lodka(l), statek(sta), prom(p), trans(t) {};//konstruktor wieloargumentowy
	~Mapa(); //destruktor
	//void wczytaj(string s, int r, wygladMap*& mS, wygladMap*& mT); //funkcja do wczytywania danych do objektu z mechanizmem sprawdzajacym poprawnosc danych
	string zworcSymbolMapy();
	int zwrocrozmiar();
	wygladMap*& zwrocMapeStatkow();
	wygladMap*& zwrocMapeTrafien();
	void zapiszMape(wygladMap*& stat);
	void wypiszMape(wygladMap* statLUBtraf);
	void zapiszMapeStrzalow(wygladMap*& traf);
	int strzal(wygladMap*& statkiPrzeciwnika, wygladMap*& mapaStrzalowGracza);
	void przejdzDalej();
	void wypiszDoPliku(fstream& plik, wygladMap* mS, wygladMap* mT);
	void zwalnianiePamieci(wygladMap*& pHead);
};