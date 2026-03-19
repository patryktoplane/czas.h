#include "Czas.h"
#include <iostream>

using namespace std;

int main()
{
    Czas c1, c2, c3, c4, c5, suma;

    cout << "ustawCzas" << endl;
    c1.setCzas(1, 2, 3);
    c2.setCzas(4, 5);
    c3.setCzas(6);

    c1.printCzas();
    c2.printCzas();
    c3.printCzas();

    cout << endl;
    cout << "wartosci ujemne" << endl;
    c4.setCzas(83, -20);
    c5.setCzas(3661);

    c4.printCzas();
    c5.printCzas();

    cout << endl;
    cout << "dodawanie" << endl;
    Czas a, b;
    a.setCzas(1, 25, 40);
    b.setCzas(0, 50, 30);

    a.printCzas();
    b.printCzas();

    suma = a + b;
    suma.printCzas();

    cout << endl;
    cout << "porownanie" << endl;
    if (a < b)
        cout << "a < b" << endl;
    else
        cout << "a >= b" << endl;

    return 0;
}
