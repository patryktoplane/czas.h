#pragma once
#include "Czas.h"
#include<iostream>

using namespace std;

class Harmonogram
{
private:
	Czas* czas = nullptr;
	int liczbaCzasow = 0;
	int rozmiar = 0;

public:
	Harmonogram();
	~Harmonogram();

	void addCzas(Czas& newCzas);
	int getLiczbaCzasow();

	Czas& operator[](int x);

	void printHarmonogram();
};
