#include "Czas.h"
#include "Harmonogram.h"
#include <iostream>

using namespace std;

Harmonogram* utworzTabliceHarmonogramow(int rozmiar)
{
    Harmonogram* nowaTablica = new Harmonogram[rozmiar];

    for (int i = 0; i < rozmiar; i++)
    {
        int ileCzasow = rand() % 5 + 1;

        for (int j = 0; j < ileCzasow; j++)
        {
            int h = rand() % 24;
            int m = rand() % 60;
            int s = rand() % 60;

            Czas nowyCzas(h, m, s);
            nowaTablica[i].addCzas(nowyCzas);
        }
    }

    return nowaTablica;
}

void bublesort(Harmonogram* tab, int rozmiar)
{
    for (int i = 0; i < rozmiar - 1; i++)
    {
        for (int j = 0; j < rozmiar - 1 - i; j++)
        {
            if (tab[j] > tab[j + 1])
            {
                Harmonogram temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
        }
    }
}

void printTablicaHarmonogramow(Harmonogram* tablica, int rozmiar)
{
    for (int i = 0; i < rozmiar; i++)
    {
        cout << "Harmonogram " << i + 1 << ":" << endl;
        tablica[i].printHarmonogram();
        cout << endl;
    }
}

int main()
{
    Harmonogram h1;

    Czas c1(0,5,0), c2(0,10,0), c3(0, 15, 0), c4(0, 20, 0), c5(0, 25, 0);

    h1.addCzas(c1);
    h1.addCzas(c2);
    h1.addCzas(c3);
    h1.addCzas(c4);
    h1.addCzas(c5);

    //cout << "Harmonogram h1:" << endl;
    //h1.printHarmonogram();

    //Harmonogram h2(h1);

    //cout << endl;
    //cout << "Harmonogram h2 - kopia h1:" << endl;
    //h2.printHarmonogram();

    //Harmonogram h3;
    //h3 = h1;

    //cout << endl;
    //cout << "Harmonogram h3 - po przypisaniu z h1:" << endl;
    //h3.printHarmonogram();

    //Czas zakres(0, 31, 0);
    //Harmonogram h4 = h1.kopiaDoZakresu(zakres);

    //cout << endl;
    //cout << "Harmonogram h4 - czasy mieszczace sie w zakresie 0:25:00:" << endl;
    //h4.printHarmonogram();

    Harmonogram h2;
    h2.addCzas(c1);
    h2.addCzas(c2);
    h2.addCzas(c3);
    if (h1 > h2)
        cout << "tak";
    else
        cout << "nie";
    
    //return 0;
        
        
        srand(time(0));
        Harmonogram* tablica = utworzTabliceHarmonogramow(3);

        cout << endl << "Przed sortowaniem:" << endl;
        printTablicaHarmonogramow(tablica, 3);


        for (int i = 0; i < 3; i++)
        {
            tablica[i].sortujCzasy();
        }

        bublesort(tablica, 3);

        cout << endl << "Po sortowaniu:" << endl;
        printTablicaHarmonogramow(tablica, 3);

        delete[] tablica;

        return 0;
    
}
