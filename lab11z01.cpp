#include <iostream>
#include <fstream>
using namespace std;

struct SMieszkanie{
    unsigned numerM;
    float pow;
    float wys;
    unsigned liczbaPok;
};

struct SPietro{
    int numerP;
    unsigned liczbaMiesz;
    SMieszkanie *mieszkanie;
};

struct SKlatka{
    unsigned numerK;
    unsigned liczbaPiet;
    SPietro *pietra;
};

struct SBlok{
    string nazwaUlicy;
    unsigned numerB;
    unsigned liczbaKlat;
    SKlatka *klatki;
};

bool wczytaj(const string nazwaPliku, SBlok& blok){
    ifstream plik(nazwaPliku);
    if(plik.good()){
        plik >> blok.nazwaUlicy >> blok.numerB;
        plik >> blok.liczbaKlat;
        if(blok.liczbaKlat > 0){
            blok.klatki = new SKlatka[blok.liczbaKlat];
            for(unsigned i = 0; i < blok.liczbaKlat; i++){
                plik >> blok.klatki[i].numerK;
                plik >> blok.klatki[i].liczbaPiet;
                if(blok.klatki[i].liczbaPiet > 0){
                    blok.klatki[i].pietra = new SPietro[blok.klatki[i].liczbaPiet];
                    for(unsigned j = 0; j < blok.klatki[i].liczbaPiet; j++){
                        plik >> blok.klatki[i].pietra[j].numerP;
                        plik >> blok.klatki[i].pietra[j].liczbaMiesz;
                        if(blok.klatki[i].pietra[j].liczbaMiesz > 0){
                            blok.klatki[i].pietra[j].mieszkanie = new SMieszkanie[blok.klatki[i].pietra[j].liczbaMiesz];
                            for(unsigned k = 0; k < blok.klatki[i].pietra[j].liczbaMiesz; j++){
                                plik >> blok.klatki[i].pietra[j].mieszkanie[k].numerM;
                                plik >> blok.klatki[i].pietra[j].mieszkanie[k].pow;
                                plik >> blok.klatki[i].pietra[j].mieszkanie[k].wys;
                                plik >> blok.klatki[i].pietra[j].mieszkanie[k].liczbaPok;
                            }
                        }
                    }
                }
                
            }
        }
        plik.close();
        return true;
    }
    plik.close();
    return false;
}

bool zapisz(ostream &output, const SMieszkanie &miekszanie){
    if (!output.good())
        return false;

    output << "\nnumer mieszkania: " <<miekszanie.numerM << "\npowierzchnia: " << miekszanie.pow << "\nwysokosc: " << miekszanie.wys << "\nliczba pokoi: " << miekszanie.liczbaPok << endl;

    return true;
}

bool zapisz(ostream &output, const SPietro &pietra){
    if (!output.good())
        return false;

    output << "\nnumer pietra: " <<pietra.numerP << "\nliczba mieszkan: " << pietra.liczbaMiesz << endl;

    for(unsigned i = 0; i < pietra.liczbaMiesz; i++){
        zapisz(output, pietra.mieszkanie[i]);
    }

    return true;
}

bool zapisz(ostream &output, const SKlatka &klatki){
    if (!output.good())
        return false;

    output << "\nnumer klatki: " <<klatki.numerK << "\nliczba pieter: " << klatki.liczbaPiet << endl;

    for (unsigned i = 0; i < klatki.liczbaPiet; i++){
        zapisz(output, klatki.pietra[i]);
    }

    return true;
}

bool zapisz(ostream &output, const SBlok &blok){
    if (!output.good())
        return false;

    output << "\nnazwa ulicy: " <<blok.nazwaUlicy << "\nnumer bloku: " << blok.numerB << "\nliczba klatek: " << blok.liczbaKlat << endl;

    for (unsigned i = 0; i < blok.liczbaKlat; i++){
        zapisz(output, blok.klatki[i]);
    }

    return true;
}

float wysokosc_pietra(SPietro &pietra){
    float max = pietra.mieszkanie[0].wys;
    for(unsigned i = 1; i < pietra.liczbaMiesz; i++)
        if(pietra.mieszkanie[i].wys > max)
            max = pietra.mieszkanie[i].wys;
    return max;
}

float wysokosc_klatki(SKlatka &klatki){
    float max = 0;
    for(unsigned i = 1; i < klatki.liczbaPiet; i++){
        max = wysokosc_pietra(klatki.pietra[i]);
        max += max;
    }
    return max;
}

void usun(SBlok& blok){
    if(blok.klatki){
        for(unsigned i = 0; i < blok.liczbaKlat; i++){
            if(blok.klatki[i].pietra){
                for(unsigned j = 0; j < blok.klatki[i].liczbaPiet; ++j){
                    if(blok.klatki[i].pietra[j].mieszkanie){
                        delete [] blok.klatki[i].pietra[j].mieszkanie;
                        blok.klatki[i].pietra[j].mieszkanie = nullptr;
                    }
                }
                delete [] blok.klatki[i].pietra;
                blok.klatki[i].pietra = nullptr;
            }
        }
        delete blok.klatki;
        blok.klatki = nullptr;
    }
}

int main(int argc, char** argv){
    if(argc !=2)
    {
        cerr << "Zla liczba parametrow uruchomienia programu";
        return 1;
    }

    SBlok blok;

    if(wczytaj(argv[1], blok))
        cout << "Wczytano plik." << endl;

    zapisz(cout, blok);

    ofstream wyjscie(argv[2]);
    zapisz(wyjscie, blok);
    wyjscie.close();

    int pietro;
    cout<<"Podaj numer pietra: ", cin >> pietro;; 
    cout << "\nwysokosc pietra: " << wysokosc_pietra(blok.klatki[0].pietra[pietro-1]) << endl;

    int klatka;
    cout<<"Podaj numer klatki: ", cin >> klatka;;
    cout << "\nwysokosc klatki: " << wysokosc_klatki(blok.klatki[klatka-1]) << endl;
    
    usun(blok);

    return 0;
}