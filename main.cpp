#include "Czas.h"
#include <iostream>

using namespace std;

int main()
{
    Czas c1;
    Czas c2;
    Czas c3;
    Czas c4;

    c1.setCzas(1, 23, 34);
    c2.setCzas(8, 59, 0);
    c3.setCzas(12, 83, -20);
    c4.setCzas(3, 19, 157);

    c1.printCzas();
    c2.printCzas();
    c3.printCzas();
    c4.printCzas();

    return 0;
}
