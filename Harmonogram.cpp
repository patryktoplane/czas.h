#include "Harmonogram.h"
#include "Czas.h"
#include <time.h>
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

Czas Harmonogram::sumaCzasow() const
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

Harmonogram Harmonogram::operator--(int)
{
	Harmonogram staraKopia(*this);

	if (rozmiar == 0)
	{
		return staraKopia;
	}

	Harmonogram nowyHarmonogram;
	for (int i = 0; i < rozmiar - 1; i++)
	{
		nowyHarmonogram.addCzas(czas[i]);
	}

	*this = nowyHarmonogram;

	return staraKopia;
}

bool Harmonogram::operator>(const Harmonogram& inny) const
{
	return this->sumaCzasow() > inny.sumaCzasow();
}

void Harmonogram::sortujCzasy()
{
	for (int i = 0; i < rozmiar - 1; i++)
	{
		for (int j = 0; j < rozmiar - 1 - i; j++)
		{
			if (czas[j] > czas[j + 1])
			{
				Czas temp = czas[j];
				czas[j] = czas[j + 1];
				czas[j + 1] = temp;
			}
		}
	}
}
