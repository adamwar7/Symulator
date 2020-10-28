#pragma once
#include <iostream>
#include "Mapa.h"
#include <fstream>

class Gracz
{
protected:
	int punktacja;						//punkty gracza
	Mapa rozstawienia;					//mapa statkow gracza

public:
	Gracz(Mapa mapa, int pkt);
	~Gracz();							//destruktor
	int zwrocPunkty();
	void edytujPunkty(int pkt);
	void ZapiszDoPlikuGracza1(fstream& plik);
	
	void ZapiszDoPlikuGracza2(fstream& plik);
};

