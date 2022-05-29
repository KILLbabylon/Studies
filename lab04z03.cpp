#include <iostream>
#include <cmath>
#include <stdio.h>
#include <string.h>
using namespace std;

unsigned int potega_10(unsigned int wykladnik){
    if (wykladnik != 0)
        return (10 * potega_10(wykladnik - 1));
    else
        return 1;
}

unsigned int ile_cyfr(unsigned int liczba){
    unsigned int wynik = 0;
    while(liczba){
        wynik++;
        liczba/=10;
    }
    return wynik;
}

unsigned int doklej_do_liczby(unsigned int zrodlo, unsigned int cyfra, bool na_poczatek = true)
{
    unsigned int wynik;
    if (cyfra > 9)
        return zrodlo;
    else if (na_poczatek == true){
        unsigned int c = ile_cyfr(zrodlo);
        wynik = (cyfra * potega_10(c)) + zrodlo;
    }
    else if (na_poczatek == false){
        wynik = (zrodlo * 10) + cyfra;
    }
    return wynik;
}
unsigned int znak_na_cyfre(char znak)
{
    if (znak >= '0' && znak <= '9')
    {
        unsigned int cyfra = znak - 48;
        return cyfra;
    }
    else
        return 0;
}

unsigned int zamien_na_liczbe(const char *znaki)
{
    int wynik = 0;
    for (int i = 0; znaki[i] != '\0'; ++i)
    {
        if (znaki[i] >= '0' && znaki[i] <= '9')
        {
            wynik = wynik * 10 + znaki[i] - 48;
        }
        else
        {
            cout << "nan: " << znaki[i] << "\n";
            wynik = wynik * 10;
        }
    }

    return wynik;
}

int main(int argc, char *argv[]){
    unsigned int a,b;
    cout<<"podaj potege: ",cin>>a;
    cout << "10^"<<a<<" = " << potega_10(a) << "\n";
    cout<<"podaj liczbe: ",cin>>a;
    cout << a<<": " << ile_cyfr(a) << " cyfr.\n";
    cout<<"podaj liczbe bazowa: ",cin>>b,
    cout<<"\npodaj liczbe do doklejenia z lewej: ",cin>>a;
    cout <<doklej_do_liczby(b, a) <<"\n";
    cout<<"\npodaj liczbe do doklejenia z prawej: ",cin>>a;
    cout <<doklej_do_liczby(b, a, false) << "\n";
    unsigned jakas_druga_liczba = zamien_na_liczbe("12134");
    cout << jakas_druga_liczba << "\n";
    jakas_druga_liczba = zamien_na_liczbe("1234ab56");
    cout << jakas_druga_liczba << "\n";

    if (argc == 1){
        char znaki[100];
        cout << "Wpisz ciag znakow\n";
        cin.get(znaki, 99);
        cout << zamien_na_liczbe(znaki) << "\n";
    }
    else if (argc > 2){
        cerr << "zbyt wiele argumentow, wpisz jedynie 1\n";
        return -1;
    }
    else{
        cout << zamien_na_liczbe(argv[1]) << "\n";
    }
}