#pragma once
#include "Czas.h"
#include<iostream>

using namespace std;

class Harmonogram
{
private:
	Czas* czas = nullptr;
	int rozmiar = 0;

public:
	Harmonogram();
	Harmonogram(const Harmonogram& newHarmonogram);

	~Harmonogram();

	void addCzas(Czas& newCzas);
	void printHarmonogram();

	int getLiczbaCzasow();

	Czas& operator[](int x);
	Czas sumaCzasow() const;

	Harmonogram& operator=(const Harmonogram& newHarmonogram);
	Harmonogram kopiaDoZakresu(const Czas& zakres);

	Harmonogram operator--(int);
	bool operator>(const Harmonogram& inny) const;

	void sortujCzasy();
};
