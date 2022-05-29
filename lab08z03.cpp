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
void zapisz(SAuto &ref){
	cout<<ref.marka<<"\n";
	cout<<ref.model<<"\n";
	cout<<ref.l_drzwi<<"\n";
	cout<<ref.kolor<<"\n";
	cout<<ref.moc<<"\n";
	cout<<ref.pojemnosc<<"\n";
}
void zapisz(SAuto *wsk){
	cout<<wsk->marka<<"\n";
	cout<<wsk->model<<"\n";
	cout<<wsk->l_drzwi<<"\n";
	cout<<wsk->kolor<<"\n";
	cout<<wsk->moc<<"\n";
	cout<<wsk->pojemnosc<<"\n";
}

void zapisz(string plikOUT, SAuto &ref){
	ofstream plik;
	plik.open(plikOUT,ios::app);
	plik<<ref.marka<<"\n";
	plik<<ref.model<<"\n";
	plik<<ref.l_drzwi<<"\n";
	plik<<ref.kolor<<"\n";
	plik<<ref.moc<<"\n";
	plik<<ref.pojemnosc<<"\n";
	plik.close();
}
void zapisz(string plikOUT, SAuto *wsk){
	ofstream plik;
	plik.open(plikOUT,ios::app);
	plik<<wsk->marka<<"\n";
	plik<<wsk->model<<"\n";
	plik<<wsk->l_drzwi<<"\n";
	plik<<wsk->kolor<<"\n";
	plik<<wsk->moc<<"\n";
	plik<<wsk->pojemnosc<<"\n";
	plik.close();
}

void zapisz(ofstream& plik, SAuto &ref){
	plik<<ref.marka<<"\n";
	plik<<ref.model<<"\n";
	plik<<ref.l_drzwi<<"\n";
	plik<<ref.kolor<<"\n";
	plik<<ref.moc<<"\n";
	plik<<ref.pojemnosc<<"\n";
	plik.close();
}
void zapisz(ofstream& plik, SAuto *wsk){
	plik<<wsk->marka<<"\n";
	plik<<wsk->model<<"\n";
	plik<<wsk->l_drzwi<<"\n";
	plik<<wsk->kolor<<"\n";
	plik<<wsk->moc<<"\n";
	plik<<wsk->pojemnosc<<"\n";
	plik.close();
}
int main(int argc,char *argv[]){

	if(argc !=6){
        cerr << "mozna podac 5 argumentow\n";
        return 0;
    }
    string loc=(argv[1]);
	string loc2=(argv[2]);
	string loc3=(argv[3]);
	string loc4=(argv[4]);
	string loc5=(argv[5]);

	SAuto samochod = {"Volvo","jakies szybkie",3,"czerwony",5000,40.0};
	SAuto &ref = samochod;
	zapisz(ref);
	SAuto samochod_2 = {"opel","astra",5,"zielony",80,2.0};
	SAuto *wsk =&samochod_2;
	zapisz(wsk);
	
	SAuto samochod_3 = {"Volvo","jakies szybkie",3,"czerwony",5000,40.0};
	SAuto &ref_2 = samochod_3;
	zapisz(loc,ref_2);
	SAuto samochod_4 = {"opel","astra",5,"zielony",80,2.0};
	SAuto *wsk_2 =&samochod_4;
	zapisz(loc2,wsk_2);
	
	ofstream plik;
	plik.open(loc3,ios::app);
	
	SAuto samochod_5 = {"Volvo","jakies szybkie",3,"czerwony",5000,40.0};
	SAuto &ref_3 = samochod_5;
	zapisz(plik,ref_3);
	
	ofstream plik2;
	plik2.open(loc4,ios::app);
	
	SAuto samochod_6 = {"opel","astra",5,"zielony",80,2.0};
	SAuto *wsk_3 = &samochod_6;
	zapisz(plik2,wsk_3);

	return 0;
}
