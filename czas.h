#pragma once
#include<iostream>

using namespace std;

class Czas
{
private:
	int godziny = 0;
	int minuty = 0;
	int sekundy = 0;

	int TimeToSec();
	void SecToTime(int x);

public:
	int getGodzina();
	int getMinuta();
	int getSekunda();

	void setCzas(int h, int m, int s);
	void setCzas(int m, int s);
	void setCzas(int s);

	Czas(int h, int m, int s);
	Czas(int m, int s);
	Czas(int s);
	Czas();

	void printCzas();

	Czas operator+(Czas& nowy);
	Czas& operator+=(Czas& nowy);

	bool operator==(Czas& nowy);
	bool operator<(Czas& nowy);
	bool operator!=(Czas& nowy);
	bool operator>(Czas& nowy);
	bool operator<=(Czas& nowy);
	bool operator>=(Czas& nowy);
};
