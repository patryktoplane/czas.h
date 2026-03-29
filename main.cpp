#include "Czas.h"
#include "Harmonogram.h"
#include <iostream>

using namespace std;

int main()
{
    Harmonogram h1;

    Czas c1(0,5,0), c2(0,10,0), c3(0, 15, 0), c4(0, 20, 0), c5(0, 25, 0);

    h1.addCzas(c1);
    h1.addCzas(c2);
    h1.addCzas(c3);
    h1.addCzas(c4);
    h1.addCzas(c5);

    cout << "Harmonogram h1:" << endl;
    h1.printHarmonogram();

    Harmonogram h2(h1);

    cout << endl;
    cout << "Harmonogram h2 - kopia h1:" << endl;
    h2.printHarmonogram();

    Harmonogram h3;
    h3 = h1;

    cout << endl;
    cout << "Harmonogram h3 - po przypisaniu z h1:" << endl;
    h3.printHarmonogram();

    Czas zakres(0, 31, 0);
    Harmonogram h4 = h1.kopiaDoZakresu(zakres);

    cout << endl;
    cout << "Harmonogram h4 - czasy mieszczace sie w zakresie 0:25:00:" << endl;
    h4.printHarmonogram();

    return 0;
}
