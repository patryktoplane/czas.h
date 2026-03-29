#include "Harmonogram.h"
#include "Czas.h"
#include <iostream>

using namespace std;

Harmonogram::Harmonogram()
{
	czas = nullptr;
	rozmiar = 0;
}

Harmonogram::Harmonogram(const Harmonogram& newHarmonogram)
{
	rozmiar = newHarmonogram.rozmiar;
	czas = new Czas[rozmiar];
	for (int i = 0; i < rozmiar; i++)
	{
		czas[i] = newHarmonogram.czas[i];
	}
}

Harmonogram::~Harmonogram()
{
	delete[] czas;
}

void Harmonogram::addCzas(Czas& newCzas)
{
	Czas* TablicaCzas = new Czas[rozmiar+1];
	for (int i = 0; i < rozmiar; i++)
	{
		TablicaCzas[i] = czas[i];
	}
	delete[] czas;
	czas = TablicaCzas;
	czas[rozmiar] = newCzas;
	rozmiar++;
}

void Harmonogram::printHarmonogram()
{
	for (int i = 0; i < rozmiar; i++)
	{
		czas[i].printCzas();
	}
}

int Harmonogram::getLiczbaCzasow()
{
	return rozmiar;
}

Czas& Harmonogram::operator[](int x)
{
	if (x >= 0 && x < rozmiar)
		return czas[x];
}

Czas Harmonogram::sumaCzasow()
{
	Czas wynik;

	for (int i = 0; i < rozmiar; i++)
	{
		wynik += czas[i];
	}

	return wynik;
}

Harmonogram& Harmonogram::operator=(const Harmonogram& newHarmonogram)
{
	if (&newHarmonogram == this)
		return *this;

	delete[] czas;
	rozmiar = newHarmonogram.rozmiar;
	czas = new Czas[rozmiar];

	for (int i = 0; i < rozmiar; i++)
	{
		czas[i] = newHarmonogram.czas[i];
	}

	return *this;
}

Harmonogram Harmonogram::kopiaDoZakresu(const Czas& zakres)
{
	Harmonogram nowyHarmonogram;
	Czas suma;

	for (int i = 0; i < rozmiar; i++)
	{
		suma += czas[i];

		if (suma <= zakres)
		{
			nowyHarmonogram.addCzas(czas[i]);
		}
		else
		{
			break;
		}
	}

	return nowyHarmonogram;
}
