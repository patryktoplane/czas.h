#include "Czas.h"
#include<iostream>
using namespace std;

void Czas::setGodziny(int x)
{
	if (x >= 0 && x <= 23)
		godziny = x;
}
void Czas::setMinuty(int x)
{
	if (x >= 0 && x <= 59)
		minuty = x;
}
void Czas::setSekundy(int x)
{
	if (x >= 0 && x <= 59)
		sekundy = x;
}
void Czas::setCzas(int h, int m, int s)
{
	if (h >= 0 && h <= 23)
		godziny = h;
	else
		godziny = 0;

	if (m >= 0 && m <= 59)
		minuty = m;
	else
		minuty = 0;

	if (s >= 0 && s <= 59)
		sekundy = s;
	else
		sekundy = 0;
}
int Czas::getGodziny()
{
	return godziny;
}
int Czas::getMinuty()
{
	return minuty;
}
int Czas::getSekundy()
{
	return sekundy;
}
void Czas::printCzas()
{
	cout << "Czas: " << godziny << ":" << minuty << ":" << sekundy << endl;
}
