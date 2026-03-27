#include "Czas.h"
#include <iostream>
using namespace std;

int Czas::getGodzina()
{
    return godziny;
}

int Czas::getMinuta()
{
    return minuty;
}

int Czas::getSekunda()
{
    return sekundy;
}

void Czas::setCzas(int h, int m, int s)
{
    if (h < 0)
        h = 0;
    if (m < 0)
        m = 0;
    if (s < 0)
        s = 0;

    int sumaSekund = h * 3600 + m * 60 + s;
    SecToTime(sumaSekund);
}

void Czas::setCzas(int m, int s)
{
    if (m < 0)
        m = 0;
    if (s < 0)
        s = 0;

    int sumaSekund = m * 60 + s;
    SecToTime(sumaSekund);
}

void Czas::setCzas(int s)
{
    if (s < 0)
        s = 0;

    SecToTime(s);
}

Czas::Czas(int h, int m, int s)
{
    setCzas(h, m, s);
}

Czas::Czas(int m, int s)
{
    setCzas(m, s);
}

Czas::Czas(int s)
{
    setCzas(s);
}

Czas::Czas()
{
    setCzas(0);
}

void Czas::printCzas()
{
    cout << "Czas: " << godziny << ":" << minuty << ":" << sekundy << endl;
}

int Czas::TimeToSec()
{
    return godziny * 3600 + minuty * 60 + sekundy;
}

void Czas::SecToTime(int x)
{
    if (x < 0)
        x = 0;

    godziny = x / 3600;
    minuty = (x % 3600) / 60;
    sekundy = x % 60;
}

Czas Czas::operator+(Czas& x)
{
    Czas wynik;
    wynik.SecToTime(this->TimeToSec() + x.TimeToSec());
    return wynik;
}

Czas& Czas::operator+=(Czas& x)
{
    this->SecToTime(this->TimeToSec() + x.TimeToSec());
    return *this;
}

bool Czas::operator==(Czas& x)
{
    if (this->TimeToSec() == x.TimeToSec())
        return true;
    else
        return false;
}

bool Czas::operator<(Czas& x)
{
    if (this->TimeToSec() < x.TimeToSec())
        return true;
    else
        return false;
}

bool Czas::operator!=(Czas& x)
{
    if (this->TimeToSec() != x.TimeToSec())
        return true;
    else
        return false;
}

bool Czas::operator>(Czas& x)
{
    if (this->TimeToSec() > x.TimeToSec())
        return true;
    else
        return false;
}

bool Czas::operator<=(Czas& x)
{
    if (this->TimeToSec() <= x.TimeToSec())
        return true;
    else
        return false;
}

bool Czas::operator>=(Czas& x)
{
    if (this->TimeToSec() >= x.TimeToSec())
        return true;
    else
        return false;
}
