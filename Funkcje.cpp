#include <cstdlib>
#include <iostream>
using namespace std;

void wypelnianie(int* tab, int wielkosc, int max, int min)
{
    srand(time(NULL));

    for (int i = 0; i < wielkosc; i++)
    {
        tab[i] = min + (rand() % (max - min + 1));
    }
}
void wyswietlanie(int* tab, int wielkosc)
{
    for (int i = 0; i < wielkosc; i++)
    {
        cout << "Liczba nr. " << i + 1 << ": " << tab[i] << endl;
    }
}
void sortowanie(int* tab, int wielkosc)
{
    int x = 0;

    for (int i = 0; i < wielkosc; i++)
    {
        for (int j = 0; j < wielkosc - i; j++)
        {
            if (tab[j] < tab[j - 1])
            {
                x = tab[j];
                tab[j] = tab[j - 1];
                tab[j - 1] = x;
                x = 0;
            }
        }
    }
    
    cout << "\nLiczby posortowanie: " << endl;

    for (int i = 0; i < wielkosc; i++)
    {
        cout << "Liczba nr. " << i + 1 << ": " << tab[i] << endl;
    }
}
int nad_srednia(int* tab, int wielkosc)
{
    float suma = 0;
    float srednia = 0;
    int ilosc = 0;

    for (int i = 0; i < wielkosc; i++)
    {
        suma += tab[i];
    }
    
    srednia = suma / wielkosc;

    for (int i = 0; i < wielkosc; i++)
    {
        if (tab[i] > srednia)
        {
            ilosc++;
        }
    }

    return ilosc;
}
int pod_srednia(int* tab, int wielkosc)
{
    float suma = 0;
    float srednia = 0;
    int ilosc = 0;

    for (int i = 0; i < wielkosc; i++)
    {
        suma += tab[i];
    }

    srednia = suma / wielkosc;

    for (int i = 0; i < wielkosc; i++)
    {
        if (tab[i] < srednia)
        {
            ilosc++;
        }
    }

    return ilosc;
}
float mediana(int* tab, int wielkosc)
{
    int y = 0;
    float x = wielkosc;
    float numer1 = 0;
    float numer2 = 0;
    float mediana = 0;

    if (wielkosc % 2 == 0)
    {
        numer1 = tab[(wielkosc / 2) - 1];
        numer2 = tab[(wielkosc / 2)];
        mediana = numer1 + numer2;
        mediana = mediana / 2;
    }

    else
    {
        x = x / 2 + 0.5;
        y = x;
        mediana = tab[y - 1];
    }

    return mediana;
}

int main()
{
    int wielkosc;
    int* tab;
    int min;
    int max;

    cout << "Podaj wielkosc tablicy: " << endl;
    cin >> wielkosc;
    tab = new int[wielkosc];

    cout << "Przedzial liczb od: ";
    cin >> min;
    cout << "do: ";
    cin >> max;

    wypelnianie(tab, wielkosc, max, min);
    wyswietlanie(tab, wielkosc);
    sortowanie(tab, wielkosc);
    cout << "\nIlosc liczb wiekszych od sredniej: " << nad_srednia(tab, wielkosc);
    cout << "\nIlosc liczb mniejszych od sredniej: " << pod_srednia(tab, wielkosc);
    cout << "\nMediana wynosi: " << mediana(tab, wielkosc);
}


