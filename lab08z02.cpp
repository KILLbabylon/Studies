#include <iostream>
#include <fstream>
using namespace std;

struct SAuto{
    string marka;
    string model;
    unsigned int liczDrzwi;
    string kolor;
    unsigned int moc;
    float pojemnosc;
}sam;

void inicjuj(SAuto& autko, const string marka_s, const string model_s, const unsigned int drzwi_s, const string kolor_s, const unsigned moc_s, const float poj_s){
    autko.marka = marka_s;
    autko.model = model_s;
    autko.liczDrzwi = drzwi_s;
    autko.kolor = kolor_s;
    autko.moc = moc_s;
    autko.pojemnosc = poj_s;
}

void inicjuj(SAuto* samochod, const string marka_s, const string model_s, const unsigned int drzwi_s, const string kolor_s, const unsigned moc_s, const float poj_s){
    samochod->marka = marka_s;
    samochod->model = model_s;
    samochod->liczDrzwi = drzwi_s;
    samochod->kolor = kolor_s;
    samochod->moc = moc_s;
    samochod->pojemnosc = poj_s;
}

void pobierz(SAuto & autko){
    string marka_s,model_s,kolor_s = "";
    unsigned int drzwi_s,moc_s, poj_s=0;
    cout << "Podaj marke samochodu: ", cin >> marka_s;
    cout << "Podaj model samochodu: ", cin >> model_s;
    cout << "Podaj liczbe drzwi samochodu: ", cin >> drzwi_s;
    cout << "Podaj kolor samochodu: ", cin >> kolor_s;
    cout << "Podaj moc samochodu: ", cin >> moc_s;
    cout << "Podaj pojemnosc samochodu: ", cin >> poj_s;

    inicjuj(autko, marka_s, model_s, drzwi_s, kolor_s, moc_s, poj_s);
} 

void pobierz(SAuto * autko){
    string marka_s,model_s,kolor_s = "";
    unsigned int drzwi_s,moc_s, poj_s=0;
    cout << "Podaj marke samochodu: ", cin >> marka_s;
    cout << "Podaj model samochodu: ", cin >> model_s;
    cout << "Podaj liczbe drzwi samochodu: ", cin >> drzwi_s;
    cout << "Podaj kolor samochodu: ", cin >> kolor_s;
    cout << "Podaj moc samochodu: ", cin >> moc_s;
    cout << "Podaj pojemnosc samochodu: ", cin >> poj_s;

    inicjuj(autko, marka_s, model_s, drzwi_s, kolor_s, moc_s, poj_s);
} 

void pobierz(SAuto& sam, const string nazwa_pliku){
    ifstream plik;
    plik.open(nazwa_pliku);
    if(plik.good()){
        string marka_s,model_s,kolor_s = "";
        unsigned int drzwi_s,moc_s, poj_s = 0;
        plik >> marka_s >> model_s >> drzwi_s >> kolor_s >> moc_s >> poj_s;
        inicjuj(sam, marka_s, model_s, drzwi_s, kolor_s, moc_s, poj_s);
    }
}

void pobierz(SAuto* sam, const string nazwa_pliku){
    ifstream plik;
    plik.open(nazwa_pliku);
    if(plik.good()){
        string marka_s,model_s,kolor_s = "";
        unsigned int drzwi_s,moc_s, poj_s = 0;
        plik >> marka_s >> model_s >> drzwi_s >> kolor_s >> moc_s >> poj_s;
        inicjuj(sam, marka_s, model_s, drzwi_s, kolor_s, moc_s, poj_s);
    }
}

void pobierz(SAuto& sam, ifstream& in){   
        string marka_s,model_s, kolor_s = "";
        unsigned int drzwi_s,moc_s, poj_s = 0;
        in >> marka_s >> model_s >> drzwi_s >> kolor_s >> moc_s >> poj_s;
        inicjuj(sam, marka_s, model_s, drzwi_s, kolor_s, moc_s, poj_s);
}

void pobierz(SAuto* sam, ifstream& in){   
        string marka_s,model_s, kolor_s = "";
        unsigned int drzwi_s,moc_s, poj_s = 0;
        in >> marka_s >> model_s >> drzwi_s >> kolor_s >> moc_s >> poj_s;
        inicjuj(sam, marka_s, model_s, drzwi_s, kolor_s, moc_s, poj_s);
}

int main(int argc, char** argv){
    if(argc !=2){
        cerr << "mozna podac 1 argument\n";
        return -1;
    }
    string loc=(argv[1]);
    SAuto samochod;
    pobierz(samochod);
    cout<<"marka: "<<samochod.marka<<"\n";

    SAuto samochod2;
    pobierz(&samochod2);
    cout<<"marka: "<<samochod2.marka<<"\n";

    SAuto samochod3;
    pobierz(&samochod3, loc);
    cout<<"marka: "<<samochod3.marka<<"\n";

    SAuto samochod4;
    pobierz(samochod4, loc);
    cout<<"marka: "<<samochod3.marka<<"\n";

    ifstream fin;
    SAuto samochod5;
    fin.open(loc);
    pobierz(&samochod5, fin);
    cout<<"kolor: "<<samochod5.kolor<<"\n";

    ifstream fin2;
    SAuto samochod6;
    fin2.open(loc);
    pobierz(samochod6, fin2);
    cout<<"moc: "<<samochod6.moc<<"\n";

}