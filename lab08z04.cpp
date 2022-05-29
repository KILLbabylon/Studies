#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct SAuto{
	string marka;
	string model;
	unsigned int l_drzwi;
	string kolor;
	unsigned int moc;
	double pojemnosc;
};

void zapisz(ostream & plik, SAuto & autko){
    if(plik.good()){
        plik << autko.marka << endl;
        plik << autko.model << endl;
        plik << autko.l_drzwi << endl;
        plik << autko.kolor << endl;
        plik << autko.moc << endl;
        plik << autko.pojemnosc << endl;
    }
}
void zapisz1(ostream & plik, SAuto * autko){
    if(plik.good()){
        plik << autko->marka << endl;
        plik << autko->model << endl;
        plik << autko->l_drzwi << endl;
        plik << autko->kolor << endl;
        plik << autko->moc << endl;
        plik << autko->pojemnosc << endl;
    }
}

int main(int argc, const char *argv[]){

    if(argc !=3){
        cerr << "mozna podac 2 argumenty\n";
        return 0;
    }
    string loc=(argv[1]); //sciezka do 1 pliku
    string loc2=(argv[2]); //sciezka do 2 pliku


    SAuto pojazd1 = {"opel","astra",5,"zielony",80,2.0};
    ofstream plik;
    plik.open(loc, ios::app);
    zapisz(plik, pojazd1);
    plik<<"--------------\n";
    plik.close();
        SAuto pojazd2 = {"Volvo","jakies szybkie",3,"czerwony",5000,40.0};
        SAuto * autko2 = & pojazd2;
        plik.open(loc2, ios::app);
        zapisz1(plik, autko2);
        plik<<"--------------\n";
        plik.close();

    return 0;
}