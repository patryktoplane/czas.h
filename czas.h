#pragma once
#include<iostream>
using namespace std;
class Czas
{
public:
	void setGodziny(int x);
	void setMinuty(int x);
	void setSekundy(int x);
	void setCzas(int h, int m, int s);
	int getGodziny();
	int getMinuty();
	int getSekundy();
	void printCzas();
private:
	int godziny = 0;
	int minuty = 0;
	int sekundy = 0;
};
