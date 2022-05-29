#include <iostream>
using namespace std;

struct SAuto{
    string marka;
    string model;
    unsigned int liczDrzwi;
    string kolor;
    unsigned int moc;
    float pojemnosc;
}sam;

SAuto inicjuj(const string marka_s, const string model_s, const unsigned int drzwi_s, const string kolor_s, const unsigned moc_s, const float poj_s){
    SAuto samochod = {marka_s, model_s, drzwi_s, kolor_s, moc_s, poj_s};
    return samochod;
}

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

int main(){
    sam = inicjuj("Fiat", "Panda", 5, "Czerwony", 54, 1.1);
    cout <<"marka: "<< sam.marka <<" model: "<<sam.model<<" drzwi: "<<sam.liczDrzwi<<" kolor: "<<sam.kolor<<" moc: "<<sam.moc<<" pojemnosc: "<<sam.pojemnosc<<"\n";

    SAuto* samochod = &sam;
    *samochod = inicjuj("Fiat", "Panda", 5, "Czerwony", 54, 1.1);
    cout << samochod -> marka <<" "<< samochod -> model <<" "<< samochod -> liczDrzwi <<" "<< samochod -> kolor <<" "<< samochod -> moc <<" "<< samochod -> pojemnosc <<"\n";

    SAuto autko;
    inicjuj(autko, "Fiat", "Panda", 5, "Czerwony", 54, 1.1);
    cout<<"marka: "<<autko.marka<<" model: "<<autko.model<<"\n";
    
    SAuto autko2;
    inicjuj(&autko2, "Fiat", "Panda", 5, "Czerwony", 54, 1.1);
    cout<<"marka: "<<autko2.marka<<" model: "<<autko2.model<<"\n";

    return 0;
}