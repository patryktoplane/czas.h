#include "Harmonogram.h"
#include "Czas.h"
#include <iostream>

using namespace std;

Harmonogram::Harmonogram()
{
	czas = nullptr;
	liczbaCzasow = 0;
	rozmiar = 0;
}
Harmonogram::~Harmonogram()
{
	delete[] czas;
}

void Harmonogram::addCzas(Czas& newCzas)
{
	if (liczbaCzasow >= rozmiar)
	{
		rozmiar++;
		Czas* TablicaCzas = new Czas[rozmiar];
		for (int i = 0; i < liczbaCzasow; i++)
		{
			TablicaCzas[i] = czas[i];
		}
		delete[] czas;
		czas = TablicaCzas;
	}
	czas[liczbaCzasow] = newCzas;
	liczbaCzasow++;
}

int Harmonogram::getLiczbaCzasow()
{
	return liczbaCzasow;
}

Czas& Harmonogram::operator[](int x)
{
	if (x >= 0 && x < liczbaCzasow)
		return czas[x];
}

void Harmonogram::printHarmonogram()
{
	for (int i = 0; i < liczbaCzasow; i++)
	{
		czas[i].printCzas();
	}
}
