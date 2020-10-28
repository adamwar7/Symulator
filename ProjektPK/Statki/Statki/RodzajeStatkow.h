#pragma once
#include <iostream>
using namespace std;

class SprawdzPoprawnosc
{
public:
	virtual bool poprawnosc(int roz, int i1, char c1)=0;
	virtual void zapisz(int roz, int i1, char s1, bool poprawnosc)=0;
};

class Lodka : SprawdzPoprawnosc
{
	string symbol;
	int rozmiar;
protected:
	int icoo1;			//piewsza wspolrzedna x
	char ccoo1;			//pierwsza wspolrzednia y
public:
	/*Lodka();*/
	Lodka(string sym,int roz,int i1,char c1);
	~Lodka();
	virtual bool poprawnosc( int roz,  int i1, char c1);
	virtual void zapisz(int roz,int i1, char s1, bool poprawnosc);
	int zwrocX();
	char zwrocY();
	string zwrocSymbol();
	Lodka zworcLodke(char roz);
};

class Statek :public Lodka
{
protected:
	int icoo2;		//druga wspolrzedna x
	char ccoo2;		//druga wspolrzednia y
public:
	Statek(string sym,int roz, int i1, char c1, int i2, char c2,Lodka l);
	~Statek();
	virtual bool poprawnosc(int roz,int i2, char c2,Lodka l);
	virtual void zapisz(int i2, char c2, bool poprawnosc);
	int zwrocX2();
	char zwrocY2();
	Statek zworcStatek(char roz,Lodka lodka);
};

class Prom :public Statek
{
protected:
	int icoo3;		//trzecia wspolrzedna x
	char ccoo3;		//trzecia wspolrzedna y
public:
	Prom(string sym, int roz, int i1, char c1, int i2, char c2, int i3, char c3, Lodka l, Statek s);
	~Prom();
	virtual bool poprawnosc(int roz, int i1, char c1, Statek s);
	virtual void zapisz(int roz, int i3, char c3, bool poprawnosc);
	int zwrocX3();
	char zwrocY3();
	Prom zworcProm(char roz, Lodka lodka,Statek statek);
};

class Transportowiec :public Prom
{
protected:
	int icoo4;	//czwarta wspolrzedna x
	char ccoo4;	//czwarta wspolrzedna y
public:
	Transportowiec(string sym, int roz, int i1, char c1, int i2, char c2, int i3, char c3,int i4,char c4, Lodka l, Statek s,Prom p);
	~Transportowiec();
	virtual bool poprawnosc(int roz, int i1, char c1, Prom s);
	virtual void zapisz(int roz, int i4, char c4, bool poprawnosc);
	int zwrocX4();
	char zwrocY4();
	Transportowiec zworcTransportowiec(char roz, Lodka lodka, Statek statek, Prom prom);
};