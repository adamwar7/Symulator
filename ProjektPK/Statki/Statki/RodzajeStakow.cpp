#include "RodzajeStatkow.h"


//Lodka
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Lodka::Lodka()
//{
//	icoo1 = 1;
//	ccoo1 = 'A';
//}

Lodka::Lodka(string sym, int roz, int i1,char  c1)
{
	symbol = sym;
	bool sprawdz = poprawnosc( roz,i1,c1);
	zapisz(roz,i1, c1, sprawdz);
}

bool Lodka::poprawnosc(int roz, int i1, char  c1)
{
	char z = 65;
	for (int i = 0; i < roz; i++)
		z++;
	if (i1 >= roz - roz + 1 && i1 <= roz && c1 >= 65 && c1 <= z)
		return true;
	return false;
}

void Lodka::zapisz( int roz, int i1, char c1, bool poprawnosc)
{
	if (poprawnosc)
	{
		icoo1 = i1;
		ccoo1 = c1;
	}
}

int Lodka::zwrocX()
{
	return icoo1;
}
char Lodka::zwrocY()
{
	return ccoo1;
}

string Lodka::zwrocSymbol()
{
	return symbol;
}

Lodka Lodka::zworcLodke(char roz)
{
	system("cls");
	cout << "Podaj ponizej wspolrzedne statkow:\n---------------------\n";
	int l;
	char l1;
	cout << "Wspolrzedna X Lodki: ";
	cin >> l1;
	cout << "Wspolrzedna Y Lodki: ";
	cin >> l;
	if (roz == '1')
	{
		Lodka lodka1("[L]", 4, l, l1);
		return lodka1;

	}
	else if (roz == '2')
	{
		Lodka lodka1("[L]", 6, l, l1);
		return lodka1;
	}
	else if (roz == '3')
	{
		Lodka lodka1("[L]", 10, l, l1);
		return lodka1;
	}
	Lodka lodka1("[L]", 0, 0, '0');
	return lodka1;
}

Lodka::~Lodka()
{

}

//Statek
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Statek::Statek(string sym,int roz, int i1, char c1, int i2, char c2,Lodka l) :Lodka(sym,roz, i1, c1)
{
	bool sprawdz = poprawnosc(roz,i2, c2,l);
	zapisz(i2, c2, sprawdz);
}

bool Statek::poprawnosc(int roz, int i2, char c2,Lodka l)
{
	char z = 65;
	for (int i = 0; i < roz; i++)
		z++;
	if (i2 >= roz - roz + 1 && i2 <= roz && c2 >= 65 && c2 <= z && (i2 + 1 == icoo1 && c2 == ccoo1) || (i2 - 1 == icoo1 && c2 == ccoo1)
		|| (i2 == icoo1 && c2 - 1 == ccoo1) || (i2 == icoo1 && c2 + 1 == ccoo1) && ((icoo1 != l.zwrocX() || (ccoo1 != l.zwrocY()))
			&& (icoo2 != l.zwrocX() || (ccoo2 != l.zwrocY()))))
		return true;
	return false;
}

void Statek::zapisz(int i2, char c2, bool poprawnosc)
{
	icoo2 = i2;
	ccoo2 = c2;
}

int Statek::zwrocX2()
{
	return icoo2;
}
char Statek::zwrocY2()
{
	return ccoo2;
}
Statek::~Statek()
{

}

Statek Statek::zworcStatek(char roz,Lodka lodka)
{
	system("cls");
	cout << "Podaj ponizej wspolrzedne Statku:\n---------------------\n";
	int l;
	char l1;
	int l2;
	char l3;
	cout << "Wspolrzedna X Statku: ";
	cin >> l1;
	cout << "Wspolrzedna Y Statku: ";
	cin >> l;
	cout << "Wspolrzedna X1 Statku: ";
	cin >> l3;
	cout << "Wspolrzedna Y1 Statku: ";
	cin >> l2;
	if (roz == '1')
	{
		Statek statek1("[S]", 4, l, l1,l2,l3,lodka);
		return statek1;

	}
	else if (roz == '2')
	{
		Statek statek1("[S]", 6, l, l1, l2, l3, lodka);
		return statek1;

	}
	else if (roz == '3')
	{
		Statek statek1("[S]", 10, l, l1, l2, l3, lodka);
		return statek1;
		;
	}
	Statek statek1("[S]", 0, 0, '0', 0, '0', lodka);
	return statek1;

}

//////Prom
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Prom::Prom(string sym,int roz, int i1, char c1, int i2, char c2, int i3, char c3,Lodka l,Statek s) :Statek(sym,roz,i1, c1, i2, c2,l)
{
	bool sprawdz = poprawnosc(roz, i2, c2, s);
	zapisz(roz,i3, c3, sprawdz);
}

bool Prom::poprawnosc(int roz, int i3, char c3, Statek s)
{
	char z = 65;
	for (int i = 0; i < roz; i++)
		z++;
	if (i3 >= roz - roz + 1 && i3 <= roz && c3 >= 65 && c3 <= z && (i3 + 2 == icoo1 && c3 == ccoo1) || (i3 - 2 == icoo1 && c3 == ccoo1)
		|| (i3 == icoo1 && c3 - 2 == ccoo1) || (i3 == icoo1 && c3 + 2 == ccoo1) && (i3 + 1 == icoo2 && c3 == ccoo2) || (i3 - 1 == icoo2 && c3 == ccoo2)
		|| (i3 == icoo2 && c3 - 1 == ccoo2) || (i3 == icoo2 && c3 + 1 == ccoo2) && (icoo1 != s.zwrocX() || (ccoo1 != s.zwrocY()) && ( icoo1 != s.zwrocX2()
		|| (ccoo1 != s.zwrocY2()))&&(icoo2 != s.zwrocX() || (ccoo2 != s.zwrocY())) && (icoo2 != s.zwrocX2() || (ccoo2 != s.zwrocY2())) && (icoo3 != s.zwrocX()
		|| (ccoo3 != s.zwrocY())) && (icoo3 != s.zwrocX2() || (ccoo3 != s.zwrocY2()))))
		 return true;
	 return false;
}
 void Prom::zapisz(int roz, int i3, char c3, bool poprawnosc)
{
	 icoo3 = i3;
	 ccoo3 = c3;
}

 int Prom::zwrocX3()
 {
	 return icoo3;
 }
 char Prom::zwrocY3()
 {
	 return ccoo3;
 }

 Prom Prom::zworcProm(char roz, Lodka lodka, Statek statek)
 {
	 system("cls");
	 int l;
	 char l1;
	 int l2;
	 char l3;
	 int l4;
	 char l5;
	  if (roz == '2')
	 {
		  cout << "Podaj ponizej wspolrzedne Promu:\n---------------------\n";
		  cout << "Wspolrzedna X Statku: ";
		  cin >> l1;
		  cout << "Wspolrzedna Y Statku: ";
		  cin >> l;
		  cout << "Wspolrzedna X1 Statku: ";
		  cin >> l3;
		  cout << "Wspolrzedna Y1 Statku: ";
		  cin >> l2;
		  cout << "Wspolrzedna X2 Statku: ";
		  cin >> l5;
		  cout << "Wspolrzedna Y2 Statku: ";
		  cin >> l4;
		 Prom prom1("[P]", 6, l, l1, l2, l3,l4,l5, lodka,statek);
		 return prom1;

	 }
	 else if (roz == '3')
	 {
		  cout << "Podaj ponizej wspolrzedne Promu:\n---------------------\n";
		  cout << "Wspolrzedna X Statku: ";
		  cin >> l1;
		  cout << "Wspolrzedna Y Statku: ";
		  cin >> l;
		  cout << "Wspolrzedna X1 Statku: ";
		  cin >> l3;
		  cout << "Wspolrzedna Y1 Statku: ";
		  cin >> l2;
		  cout << "Wspolrzedna X2 Statku: ";
		  cin >> l5;
		  cout << "Wspolrzedna Y2 Statku: ";
		  cin >> l4;
		  Prom prom1("[P]", 10, l, l1, l2, l3, l4, l5, lodka, statek);
		  return prom1;
		 ;
	 }
	  Prom prom1("[P]", 0, 0, '0', 0, '0', 0, '0', lodka, statek);
	  return prom1;

 }

 Prom::~Prom()
 {

 }
//Transportowiec
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 Transportowiec::Transportowiec(string sym, int roz, int i1, char c1, int i2, char c2, int i3, char c3, int i4, char c4, Lodka l, Statek s,Prom p):Prom(sym, roz, i1, c1, i2, c2,i3,c3, l,s)
 {
	 bool sprawdz = poprawnosc(roz, i4, c4, p);
	 zapisz(roz, i4, c4, sprawdz);
 }

 bool  Transportowiec::poprawnosc(int roz, int i4, char c4, Prom p)
 {
	 char z = 65;
	 for (int i = 0; i < roz; i++)
		 z++;
	 if (i4 >= roz - roz + 1 && i4 <= roz && c4 >= 65 && c4 <= z && (i4 + 3 == icoo1 && c4 == ccoo1) || (i4 - 3 == icoo1 && i4 == ccoo1)
		 || (i4 == icoo1 && c4 - 3 == ccoo1) || (i4 == icoo1 && c4 + 3 == ccoo1) && (i4 + 2 == icoo2 && c4 == ccoo2) || (i4 - 2 == icoo2 && c4 == ccoo2)
		 || (i4 == icoo2 && c4 - 2 == ccoo2) || (i4 == icoo2 && c4 + 2 == ccoo2) && (i4 + 1 == icoo3 && c4 == ccoo3) || (i4 - 1 == icoo3 && c4 == ccoo3)
		 || (i4 == icoo3 && c4 - 1 == ccoo3) || (i4 == icoo3 && c4 + 1 == ccoo3) && (((icoo1 != p.zwrocX()) || (ccoo1 != p.zwrocY())) && ((icoo1 != p.zwrocX2())
		 || (ccoo1 != p.zwrocY2()))  && ((icoo1 != p.zwrocX3())	 || (ccoo1 != p.zwrocY3())) && (icoo2 != p.zwrocX() || (ccoo2 != p.zwrocY())) 
		 && ( icoo2 != p.zwrocX2() || (ccoo2 != p.zwrocY2())) && (icoo2 != p.zwrocX3() || (ccoo2 != p.zwrocY3())) && (icoo3 != p.zwrocX()
		 || (ccoo3 != p.zwrocY())) && (icoo3 != p.zwrocX2() || (ccoo3 != p.zwrocY2())) && (icoo3 != p.zwrocX3() || (ccoo3 != p.zwrocY3())) && (icoo4 != p.zwrocX()
		 || (ccoo4 != p.zwrocY())) && (icoo4 != p.zwrocX2() || (ccoo4 != p.zwrocY2())) && (icoo4 != p.zwrocX3() || (ccoo4 != p.zwrocY3()))))
		 return true;
	 return false;
 }

 void  Transportowiec::zapisz(int roz, int i4, char c4, bool poprawnosc)
 {
	 icoo4 = i4;
	 ccoo4 = c4;
 }
 int  Transportowiec::zwrocX4()
 {
	 return icoo4;
 }
 char  Transportowiec::zwrocY4()
 {
	 return ccoo4;
 }

 Transportowiec Transportowiec::zworcTransportowiec(char roz, Lodka lodka, Statek statek,Prom prom)
 {
	 int l;
	 char l1;
	 int l2;
	 char l3;
	 int l4;
	 char l5;
	 int l6;
	 char l7;
	 if (roz == '3')
	 {
		 cout << "Podaj ponizej wspolrzedne Transportowica:\n---------------------\n";
		 cout << "Wspolrzedna X Statku: ";
		 cin >> l1;
		 cout << "Wspolrzedna Y Statku: ";
		 cin >> l;
		 cout << "Wspolrzedna X1 Statku: ";
		 cin >> l3;
		 cout << "Wspolrzedna Y1 Statku: ";
		 cin >> l2;
		 cout << "Wspolrzedna X2 Statku: ";
		 cin >> l5;
		 cout << "Wspolrzedna Y2 Statku: ";
		 cin >> l4;
		 cout << "Wspolrzedna X2 Statku: ";
		 cin >> l7;
		 cout << "Wspolrzedna Y2 Statku: ";
		 cin >> l6;
		 Transportowiec t1("[T]", 10, l, l1, l2, l3, l4, l5,l6,l7, lodka, statek,prom);
		 return t1;

	 }
	 Transportowiec t1("[T]", 0, 0, '0', 0, '0', 0, '0', 0, '0', lodka, statek, prom);
	 return t1;

 }
 Transportowiec::~Transportowiec()
 {

 }