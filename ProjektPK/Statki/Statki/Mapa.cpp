#include "Mapa.h"

//Mapa::Mapa()
//{
//	symbol = "[#]";
//	rozmiar = 1;
//	mapaStatkow = nullptr;
//	mapaTrafien = nullptr;
//}

//Mapa::Mapa(string s, int r, wygladMap*& mS, wygladMap*& mT)
//{
//	wczytaj(s, r, mS, mT);
//}

//void Mapa::wczytaj(string s, int r, wygladMap* &mS, wygladMap* &mT)
//{
//	symbol = s;
//	rozmiar = r;
//	mapaStatkow = mS;
//	mapaTrafien = mT;
//}
string Mapa::zworcSymbolMapy()
{
	return symbol;
}

int Mapa::zwrocrozmiar()
{
	return rozmiar;
}
wygladMap*& Mapa::zwrocMapeStatkow()
{
	return mapaStatkow;
}

wygladMap*& Mapa::zwrocMapeTrafien()
{
	return mapaTrafien;
}

void Mapa::zapiszMape(wygladMap*& stat)
{
	char z = 65;   //kod ASCII 'A'
	if (rozmiar == 4)
	{
		for (int i = 0; i < rozmiar; i++)
		{

			for (int j = 1; j < rozmiar + 1; j++)
			{
				if (!stat)
				{
					if ((j == lodka.zwrocX()) && (z == lodka.zwrocY()))
						stat = new wygladMap{ lodka.zwrocSymbol(),rozmiar,true,"Lodka",lodka.zwrocX(),lodka.zwrocY(),nullptr };
					else if (j == statek.zwrocX() && (z == statek.zwrocY()))
						stat = new wygladMap{ statek.zwrocSymbol(),rozmiar,true,"Statek",statek.zwrocX(),statek.zwrocY(),nullptr };
					else if (j == statek.zwrocX2() && (z == statek.zwrocY2()))
						stat = new wygladMap{ statek.zwrocSymbol(),rozmiar,true,"Statek",statek.zwrocX2(),statek.zwrocY2(),nullptr };
					else
						stat = new wygladMap{ symbol,rozmiar,false,"pusto",j,z,nullptr };
				}
				else
				{
					auto p = stat;
					while (p->next)
						p = p->next;
					if ((j == lodka.zwrocX()) && (z == lodka.zwrocY()))
						p->next = new wygladMap{ lodka.zwrocSymbol(),rozmiar,true,"Lodka",lodka.zwrocX(),lodka.zwrocY(),nullptr };
					else if (j == statek.zwrocX() && (z == statek.zwrocY()))
						p->next = new wygladMap{ statek.zwrocSymbol(),rozmiar,true,"Statek",statek.zwrocX(),statek.zwrocY(),nullptr };
					else if (j == statek.zwrocX2() && (z == statek.zwrocY2()))
						p->next = new wygladMap{ statek.zwrocSymbol(),rozmiar,true,"Statek",statek.zwrocX2(),statek.zwrocY2(),nullptr };
					else
						p->next = new wygladMap{ symbol,rozmiar,false,"pusto",j,z,nullptr };
				}
			}
			z++;
		}
	}
	else if (rozmiar == 6)
	{
		for (int i = 0; i < rozmiar; i++)
		{

			for (int j = 1; j < rozmiar + 1; j++)
			{
				if (!stat)
				{
					if ((j == lodka.zwrocX()) && (z == lodka.zwrocY()))
						stat = new wygladMap{ lodka.zwrocSymbol(),rozmiar,true,"Lodka",lodka.zwrocX(),lodka.zwrocY(),nullptr };
					else if (j == statek.zwrocX() && (z == statek.zwrocY()))
						stat = new wygladMap{ statek.zwrocSymbol(),rozmiar,true,"Statek",statek.zwrocX(),statek.zwrocY(),nullptr };
					else if (j == statek.zwrocX2() && (z == statek.zwrocY2()))
						stat = new wygladMap{ statek.zwrocSymbol(),rozmiar,true,"Statek",statek.zwrocX2(),statek.zwrocY2(),nullptr };
					else if (j == prom.zwrocX() && (z == prom.zwrocY()))
						stat = new wygladMap{ prom.zwrocSymbol(),rozmiar,true,"Prom",prom.zwrocX(),prom.zwrocY(),nullptr };
					else if (j == prom.zwrocX2() && (z == prom.zwrocY2()))
						stat = new wygladMap{ prom.zwrocSymbol(),rozmiar,true,"Prom",prom.zwrocX2(),prom.zwrocY2(),nullptr };
					else if (j == prom.zwrocX3() && (z == prom.zwrocY3()))
						stat = new wygladMap{ prom.zwrocSymbol(),rozmiar,true,"Prom",prom.zwrocX3(),prom.zwrocY3(),nullptr };
					else
						stat = new wygladMap{ symbol,rozmiar,false,"pusto",j,z,nullptr };
				}
				else
				{
					auto p = stat;
					while (p->next)
						p = p->next;
					if ((j == lodka.zwrocX()) && (z == lodka.zwrocY()))
						p->next = new wygladMap{ lodka.zwrocSymbol(),rozmiar,true,"Lodka",lodka.zwrocX(),lodka.zwrocY(),nullptr };
					else if (j == statek.zwrocX() && (z == statek.zwrocY()))
						p->next = new wygladMap{ statek.zwrocSymbol(),rozmiar,true,"Statek",statek.zwrocX(),statek.zwrocY(),nullptr };
					else if (j == statek.zwrocX2() && (z == statek.zwrocY2()))
						p->next = new wygladMap{ statek.zwrocSymbol(),rozmiar,true,"Statek",statek.zwrocX2(),statek.zwrocY2(),nullptr };
					else if (j == prom.zwrocX() && (z == prom.zwrocY()))
						p->next = new wygladMap{ prom.zwrocSymbol(),rozmiar,true,"Prom",prom.zwrocX(),prom.zwrocY(),nullptr };
					else if (j == prom.zwrocX2() && (z == prom.zwrocY2()))
						p->next = new wygladMap{ prom.zwrocSymbol(),rozmiar,true,"Prom",prom.zwrocX2(),prom.zwrocY2(),nullptr };
					else if (j == prom.zwrocX3() && (z == prom.zwrocY3()))
						p->next = new wygladMap{ prom.zwrocSymbol(),rozmiar,true,"Prom",prom.zwrocX3(),prom.zwrocY3(),nullptr };
					else
						p->next = new wygladMap{ symbol,rozmiar,false,"pusto",j,z,nullptr };
				}
			}
			z++;
		}
	}
	else
	{
		for (int i = 0; i < rozmiar; i++)
		{

			for (int j = 1; j < rozmiar + 1; j++)
			{
				if (!stat)
				{
					if ((j == lodka.zwrocX()) && (z == lodka.zwrocY()))
						stat = new wygladMap{ lodka.zwrocSymbol(),rozmiar,true,"Lodka",lodka.zwrocX(),lodka.zwrocY(),nullptr };
					else if (j == statek.zwrocX() && (z == statek.zwrocY()))
						stat = new wygladMap{ statek.zwrocSymbol(),rozmiar,true,"Statek",statek.zwrocX(),statek.zwrocY(),nullptr };
					else if (j == statek.zwrocX2() && (z == statek.zwrocY2()))
						stat = new wygladMap{ statek.zwrocSymbol(),rozmiar,true,"Statek",statek.zwrocX2(),statek.zwrocY2(),nullptr };
					else if (j == prom.zwrocX() && (z == prom.zwrocY()))
						stat = new wygladMap{ prom.zwrocSymbol(),rozmiar,true,"Prom",prom.zwrocX(),prom.zwrocY(),nullptr };
					else if (j == prom.zwrocX2() && (z == prom.zwrocY2()))
						stat = new wygladMap{ prom.zwrocSymbol(),rozmiar,true,"Prom",prom.zwrocX2(),prom.zwrocY2(),nullptr };
					else if (j == prom.zwrocX3() && (z == prom.zwrocY3()))
						stat = new wygladMap{ prom.zwrocSymbol(),rozmiar,true,"Prom",prom.zwrocX3(),prom.zwrocY3(),nullptr };
					else if (j == trans.zwrocX() && (z == trans.zwrocY()))
						stat = new wygladMap{ trans.zwrocSymbol(),rozmiar,true,"Transportowiec",trans.zwrocX(),trans.zwrocY(),nullptr };
					else if (j == trans.zwrocX2() && (z == trans.zwrocY2()))
						stat = new wygladMap{ trans.zwrocSymbol(),rozmiar,true,"Transportowiec",trans.zwrocX2(),trans.zwrocY2(),nullptr };
					else if (j == trans.zwrocX3() && (z == trans.zwrocY3()))
						stat = new wygladMap{ trans.zwrocSymbol(),rozmiar,true,"Transportowiec",trans.zwrocX3(),trans.zwrocY3(),nullptr };
					else if (j == trans.zwrocX4() && (z == trans.zwrocY4()))
						stat = new wygladMap{ trans.zwrocSymbol(),rozmiar,true,"Transportowiec",trans.zwrocX4(),trans.zwrocY4(),nullptr };
					else
						stat = new wygladMap{ symbol,rozmiar,false,"pusto",j,z,nullptr };
				}
				else
				{
					auto p = stat;
					while (p->next)
						p = p->next;
					if ((j == lodka.zwrocX()) && (z == lodka.zwrocY()))
						p->next = new wygladMap{ lodka.zwrocSymbol(),rozmiar,true,"Lodka",lodka.zwrocX(),lodka.zwrocY(),nullptr };
					else if (j == statek.zwrocX() && (z == statek.zwrocY()))
						p->next = new wygladMap{ statek.zwrocSymbol(),rozmiar,true,"Statek",statek.zwrocX(),statek.zwrocY(),nullptr };
					else if (j == statek.zwrocX2() && (z == statek.zwrocY2()))
						p->next = new wygladMap{ statek.zwrocSymbol(),rozmiar,true,"Statek",statek.zwrocX2(),statek.zwrocY2(),nullptr };
					else if (j == prom.zwrocX() && (z == prom.zwrocY()))
						p->next = new wygladMap{ prom.zwrocSymbol(),rozmiar,true,"Prom",prom.zwrocX(),prom.zwrocY(),nullptr };
					else if (j == prom.zwrocX2() && (z == prom.zwrocY2()))
						p->next = new wygladMap{ prom.zwrocSymbol(),rozmiar,true,"Prom",prom.zwrocX2(),prom.zwrocY2(),nullptr };
					else if (j == prom.zwrocX3() && (z == prom.zwrocY3()))
						p->next = new wygladMap{ prom.zwrocSymbol(),rozmiar,true,"Prom",prom.zwrocX3(),prom.zwrocY3(),nullptr };
					else if (j == trans.zwrocX() && (z == trans.zwrocY()))
						p->next = new wygladMap{ trans.zwrocSymbol(),rozmiar,true,"Transportowiec",trans.zwrocX(),trans.zwrocY(),nullptr };
					else if (j == trans.zwrocX2() && (z == trans.zwrocY2()))
						p->next = new wygladMap{ trans.zwrocSymbol(),rozmiar,true,"Transportowiec",trans.zwrocX2(),trans.zwrocY2(),nullptr };
					else if (j == trans.zwrocX3() && (z == trans.zwrocY3()))
						p->next = new wygladMap{ trans.zwrocSymbol(),rozmiar,true,"Transportowiec",trans.zwrocX3(),trans.zwrocY3(),nullptr };
					else if (j == trans.zwrocX4() && (z == trans.zwrocY4()))
						p->next = new wygladMap{ trans.zwrocSymbol(),rozmiar,true,"Transportowiec",trans.zwrocX4(),trans.zwrocY4(),nullptr };
					else
						p->next = new wygladMap{ symbol,rozmiar,false,"pusto",j,z,nullptr };
				}
			}
			z++;
		}
	}
}


void Mapa::zapiszMapeStrzalow(wygladMap*& traf)
{
	char z = 65;
	for (int i = 0; i < rozmiar; i++)
	{
		for (int j = 0; j < rozmiar + 1; j++)
		{
			if (!traf)
			{
				traf = new wygladMap{ symbol,rozmiar,false,"pusto",j,z,nullptr };
			}
			else
			{
				auto p = traf;
				while (p->next)
					p = p->next;
				p->next = new wygladMap{ symbol,rozmiar,false,"pusto",j,z,nullptr };
			}
		}
		z++;
		
	}
}

void Mapa::wypiszMape(wygladMap* statLUBtraf)
{
	char znak = 65;  //KOD ASCII 'A'
	cout << "   ";
	for (int i = 1; i < rozmiar + 1; i++)
	{
		cout << ' ' << i << ' ';
	}
	cout << endl;
	while (statLUBtraf)
	{
		cout << ' ' << znak << ' ';
		znak++;
		for (int i = 0; i < rozmiar; i++)
		{
			cout << statLUBtraf->symbol;
			statLUBtraf = statLUBtraf->next;
		}
		cout << endl;
	}

}

int Mapa::strzal(wygladMap*& statkiPrzeciwnika,wygladMap*& mapaStrzalowGracza)
{
	char z = 65;
	int ygrekowa;
	char xowa;
	cout << "\nAtakuj!\n";
	while (true)
	{
		bool xTrue = false;
		bool yTrue = false;
		while (!xTrue)
		{
			cout << "\nPodaj wspolrzedna X: ";
			cin >> xowa;
			if (xowa >= z && xowa <= z + rozmiar - 1)
				xTrue = true;
			else
				cout << "\n Podano zle dane lub wykraczajace poza zakres mapy, wprowdz ponownie\n";
		}
		while (!yTrue)
		{
			cout << "\nPodaj wspolrzedna Y: ";
			cin >> ygrekowa;
			if (ygrekowa >= 1 && ygrekowa <= rozmiar)
				yTrue = true;
			else
				cout << "\n Podano zle dane lub wykraczajace poza zakres mapy, wprowdz ponownie\n";
		}
		if (xTrue && yTrue)
			break;
	}
	auto p = statkiPrzeciwnika;
	auto c = mapaStrzalowGracza;
	while (p)
	{
		if (ygrekowa == p->y && xowa == p->x)
		{
			if (p->nazwaStatku == "Lodka")
			{
				cout << "BRAWO! TRAFILES LODKE PRZECWINIKA!\n";
				p->nazwaStatku = "Zatopniony";
				p->symbol = "[X]";
				c->nazwaStatku = "Zatopniony";
				c->symbol = "[X]";
				
				return 10;
			}
			else if (p->nazwaStatku == "Statek")
			{
				cout << "BRAWO! TRAFILES STATEK PRZECWINIKA!\n";
				p->nazwaStatku = "Zatopniony";
				p->symbol = "[X]";
				c->nazwaStatku = "Zatopniony";
				c->symbol = "[X]";
			
				return 5;
			}
			else if (p->nazwaStatku == "Prom")
			{
				cout << "BRAWO! TRAFILES PROM PRZECWINIKA!\n";
				p->nazwaStatku = "Zatopniony";
				p->symbol = "[X]";
				c->nazwaStatku = "Zatopniony";
				c->symbol = "[X]";
				
				return 3;
			}
			else if (p->nazwaStatku == "Transportowiec")
			{
				cout << "BRAWO! TRAFILES TRANSPORTOWIEC PRZECWINIKA!\n";
				p->nazwaStatku = "Zatopniony";
				p->symbol = "[X]";
				c->nazwaStatku = "Zatopniony";
				c->symbol = "[X]";
			
				return 1;
			}
			else
			{
				cout << "Strzal chybiony :( Kolej przeciwnika!\n";
				p->symbol = "[X]";
				c->symbol = "[X]";
				
				return 0;
			}
		}
		p = p->next;
		c = c->next;
	}
	return 0;
}


void Mapa::przejdzDalej()
{
	char a = '0';
	while (a != '1')
	{
		cout << "\n\n Wprowadz '1' aby przejsc dalej: ";
		cin >> a;
		system("cls");
	}
}

void Mapa::wypiszDoPliku(fstream& plik,wygladMap* mS,wygladMap* mT)
{
	auto p = mS;
	plik << "\n\nStatki:\n";
	for (int i = 0; i < rozmiar; i++)
	{
		for (int i = 0; i < rozmiar; i++)
		{
			if (p)
			{
				plik << p->symbol;
				p = p->next;
			}
		}
		plik << endl;
	}	
	auto t = mT;
	plik << "\nTrafenia:\n";
	for (int i = 0; i < rozmiar; i++)
	{
		for (int i = 0; i < rozmiar; i++)
		{
			if (t)
			{
				plik << t->symbol;
				t = t->next;
			}
		}
		plik << endl;
	}
	plik.close();
}

void Mapa::zwalnianiePamieci(wygladMap*& pHead) {
	if (pHead)
	{
		zwalnianiePamieci(pHead->next);
		delete pHead;
		pHead = nullptr;
	}
}

Mapa::~Mapa()
{
	
}