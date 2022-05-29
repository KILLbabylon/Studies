#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct SObiektyw{
string rodzajObiektywu;
double przeslona;
unsigned int ogniskowa;
};

struct SAparat{
    string nazwa_aparatu;
    unsigned int ilosc;
    SObiektyw *obiektyw;
};

bool wczytaj(const string nazwa_pliku, SAparat &aparat){
    ifstream plik(nazwa_pliku);
    string nazwa;
    double przeslona;
    unsigned ogniskowa;

    if(plik.good()){
        plik >> aparat.nazwa_aparatu;
        plik >> aparat.ilosc;
        if(aparat.ilosc > 0){
            aparat.obiektyw = new SObiektyw[aparat.ilosc];
            for(unsigned i = 0; i < aparat.ilosc; i++){
                plik >> nazwa >> przeslona >> ogniskowa;
                aparat.obiektyw[i] = SObiektyw{nazwa, przeslona, ogniskowa};
            }
        }
    plik.close();
    return true;
    }
    plik.close();
    return false;
}

void wypisz(ostream &wyjscie, const SAparat &aparat){
    wyjscie << aparat.nazwa_aparatu << endl << aparat.ilosc << endl;
    for(size_t i = 0; i < aparat.ilosc; i++){
        wyjscie << aparat.obiektyw[i].rodzajObiektywu << ' ' << aparat.obiektyw[i].przeslona << ' ' << aparat.obiektyw[i].ogniskowa << endl;
    }
}

size_t zlicz(const SAparat &aparat){
    size_t n = 0;
    for(unsigned i = 0; i < aparat.ilosc; i++){
        if(aparat.obiektyw[i].ogniskowa > 50){
            n++;
        }
    }
    return n;
}

void usun(SAparat &aparat){
    delete[] aparat.obiektyw;
    aparat.obiektyw = nullptr;
}

int main(int argc, char** argv){
    if(argc !=3){
        cerr << "Zla liczba parametrow\n";
        return 1;
    }
    SAparat aparat;
    if(wczytaj(argv[1], aparat)){ //plik wejsciowy
        wypisz(cout, aparat);
        cout << "Ilosc obiektywow z ogniskowa > 50: "<< zlicz(aparat)<<"\n";

        ofstream plik(argv[2]); //plik wyjsciowy
        wypisz(plik, aparat);
        plik.close();
        usun(aparat);
    }
    return 0;
}